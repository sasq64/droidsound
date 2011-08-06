package com.ssb.droidsound;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.io.Writer;
import java.lang.Thread;
import java.util.Date;

import android.content.Context;
import android.os.Build;
import com.ssb.droidsoundedit.R;


class MyExceptionHandler implements Thread.UncaughtExceptionHandler {

	public Context application;
	private final Thread.UncaughtExceptionHandler oldHandler;
	private final String targetDir;

	public MyExceptionHandler(Thread.UncaughtExceptionHandler oldh, String target) {
		oldHandler = oldh;
		targetDir = target;
	}

	public void uncaughtException(Thread thread, Throwable ex)
	{
		ex.printStackTrace();
        Writer result = new StringWriter();
        PrintWriter printWriter = new PrintWriter(result);
        ex.printStackTrace(printWriter);
        String stacktrace = result.toString();
        printWriter.close();

        File f = new File(targetDir,  "droidsound_crash.txt");
        writeToFile(stacktrace, f);
        oldHandler.uncaughtException(thread, ex);
	}

	private void writeToFile(String stacktrace, File f) {
		try {
			BufferedWriter bos = new BufferedWriter(new FileWriter(f));

			bos.write(String.format("Droidsound crash\n"));//, PlayerActivity.DROIDSOUND_VERSION));
			Date d = new Date();
			bos.write(String.format("%s\n\nMANUFACTURER:%s\nNMODEL:%s\n", d.toString(), Build.DEVICE, Build.MODEL)); 

			bos.write(stacktrace);
			bos.flush();
			bos.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
