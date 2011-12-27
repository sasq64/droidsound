package com.ssb.droidsound.plugins;

import java.nio.charset.Charset;



public class HivelyPlugin extends DroidSoundPlugin {
	private static final Charset ISO88591 = Charset.forName("ISO-8859-1");
	static {
		System.loadLibrary("hively");
	}

	private long songRef;

	@Override
	public void setOption(String string, Object val) {
		/* no options */
	}

	@Override
	public String getVersion() {
		return "HVL Replay 1.6";
	}

	@Override
	public boolean canHandle(String name) {
		return name.toUpperCase().endsWith(".HVL") || name.toUpperCase().endsWith(".AHX");
	}

	@Override
	public String[] getDetailedInfo() {
		String[] info = new String[2];
		info[0] = "Format";
		info[1] = "Hively/AHX";
		return info;
	}

	@Override
	public int getSoundData(short[] dest) {
		return N_getSoundData(songRef, dest, dest.length);
	}

	@Override
	public String getStringInfo(int what) {
		return null;
	}

	@Override
	protected boolean load(String name, byte[] module) {
		songRef = N_load(module, module.length);
		return songRef != 0;
	}

	@Override
	public void unload() {
		N_unload(songRef);
	}

	@Override
	protected MusicInfo getMusicInfo(String name, byte[] module) {
		if (module.length < 3) {
			return null;
		}
		String magic = new String(module, 0, 3, ISO88591);
		if (magic.equals("HVL") || magic.equals("THX")) {
			MusicInfo info = new MusicInfo();
			int namePtr = ((module[4] & 0xff) << 8) | (module[5] & 0xff);
			if (namePtr <= module.length - 128) {
				info.title = new String(module, namePtr, namePtr + 128, ISO88591);
				info.title = info.title.replaceFirst("\u0000.*", "");
				return info;
			}

			return null;
		}

		return null;
	}

	native private long N_load(byte [] module, int size);
	native private void N_unload(long song);
	native private int N_getSoundData(long song, short [] dest, int size);
}
