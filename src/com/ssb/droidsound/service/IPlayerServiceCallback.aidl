package com.ssb.droidsound.service;

interface IPlayerServiceCallback {
	void update(in String [] data, boolean newsong);
	void error(int errNo, String error);
}
