package com.ssb.droidsound.utils;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Enumeration;
import java.util.List;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;


import android.content.Context;

public final class Unzipper {

	private static final String TAG = Unzipper.class.getSimpleName();

	private static Unzipper _instance = null;

    private Unzipper() {
    }

    		
    public static synchronized Unzipper getInstance() {
		if(_instance == null) {
			_instance = new Unzipper();
		}
		return _instance;
	}

	private static final class UnzipJob {
		public final String asset;
		public final File targetDir;
		private UnzipJob(String a, File t) {
			asset = a;
			targetDir = t;
		}
	}

	private static final class UnzipWorker implements Runnable {

		private final List<UnzipJob> unzipList = new ArrayList<UnzipJob>();

        //private List<String> doneList = new ArrayList(); below is the weaker type of this one
		private final Collection<String> doneList = new ArrayList<String>();

		private final Context context;
		private boolean doQuit;

		private UnzipWorker(Context ctx) {
			context = ctx;
		}

		@Override
		public void run() {
			while(!doQuit) {
				try {
					synchronized (this) {
						wait();
					}
				} catch (InterruptedException e) {
					return;
				}
				Log.d(TAG, "UNZIP THREAD WOKE UP");
				while(true) {
					UnzipJob job = null;
					synchronized (unzipList) {
						if(unzipList.size() > 0) {
							Log.d(TAG, "List has %d entries ", unzipList.size());
							job = unzipList.get(0);
							unzipList.remove(0);
							Log.d(TAG, "Found " + job.asset);
						} else {
							//Log.d(TAG, "Quitting thread");
							//return;
						}
					}
					if(job != null) {
						unzipAsset(context, job.asset, job.targetDir);
						synchronized (doneList) {
							doneList.add(job.asset);
						}
					} else {
						break;
					}
				}
			}
		}

		public void addJob(String asset, File targetDir) {
			synchronized (unzipList) {

				for(UnzipJob job : unzipList) {
					if(job.asset.equals(asset)) {
						Log.d(TAG, "##### SKIPPING " + asset);
						return;
					}
				}
				Log.d(TAG, "##### ADDING " + asset);
				unzipList.add(new UnzipJob(asset, targetDir));
			}
			synchronized (this) {
				notifyAll();
			}
		}

		public boolean checkJob(String asset) {
			//boolean rc = false; Redundant. Value never used
            boolean rc;
			synchronized (doneList) {
				rc = doneList.contains(asset);
				//if(rc) {
				//	doneList.remove(asset);
				//}
			}
			return rc;
		}

	}

	private UnzipWorker unzipWorker;
	private Thread unzipThread;

	public boolean checkJob(String asset) {
		return unzipWorker.checkJob(asset);
	}

	public void unzipAssetAsync(Context context, String asset, File targetDir) {

		if(unzipThread != null) {
			if(!unzipThread.isAlive()) {
				unzipThread = null;
			}
		}

		if(unzipThread == null) {
			unzipWorker = new UnzipWorker(context);
			unzipThread = new Thread(unzipWorker);
			unzipThread.setName("Unzipper-UnzipWorkerThread");
			unzipThread.setPriority(2);
			unzipThread.start();
			try {
				Thread.sleep(300);
			} catch (InterruptedException e) {
			}
		}
		unzipWorker.addJob(asset, targetDir);
	}

	public static synchronized boolean unzipAsset(Context context, String asset, File targetDir) {

		File tempFile = null;
		try {
			tempFile = new File(targetDir, asset);

            //FileOutputStream os = new FileOutputStream(tempFile); //Left here in case the Buffered I/O causes any problems.
			BufferedOutputStream os = new BufferedOutputStream (new FileOutputStream(tempFile));
            InputStream is = context.getAssets().open(asset);

            //byte [] buffer = new byte [(128*1024)]; //Left shift is more efficient.
            byte [] buffer = new byte [(128 << 10)];
			while(true) {
				int rc = is.read(buffer);
				if(rc <= 0) {
					break;
				}
				os.write(buffer, 0, rc);
			}
			is.close();
			os.close();

			ZipFile zf = new ZipFile(tempFile);
			Enumeration<? extends ZipEntry> entries = zf.entries();
			while(entries.hasMoreElements()) {
				ZipEntry entry = entries.nextElement();
				is = zf.getInputStream(entry);
				String name = entry.getName();
				File efile = new File(targetDir, name);

				Log.d(TAG, "Extracting %s / %s", name, efile.getPath());

				if(name.endsWith("/")) {
					continue;
				}

				efile.getParentFile().mkdirs();
				//os = new FileOutputStream(efile); //Here in case Buffered I/O causes any problems.
				os = new BufferedOutputStream(new FileOutputStream(efile));

				while(true) {
					int rc = is.read(buffer);
					if(rc <= 0) {
						break;
					}
					os.write(buffer, 0, rc);
				}
				is.close();
				os.close();
			}
			tempFile.delete();
			return true;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		if(tempFile != null) {
			tempFile.delete();
		}
		return false;
	}
}