package com.ssb.droidsound;

interface IPlayerServiceCallback {
	void intChanged(int what, int value);
	void stringChanged(int what, String value);
}
