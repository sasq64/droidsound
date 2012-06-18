package com.ssb.droidsound.file;

import java.io.IOException;
import java.io.InputStream;

public class StreamFileSource extends FileSource {

	private InputStream inputStream;

	public StreamFileSource(String ref, InputStream is) {
		super(ref);
		inputStream = is;
	}
	
	@Override
	protected InputStream intGetStream() throws IOException {
		return inputStream;
	}

}
