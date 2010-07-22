package com.ssb.droidsound.service;

interface IPlayerServiceCallback {
	void intChanged(int what, int value);
	void stringChanged(int what, String value);
}
