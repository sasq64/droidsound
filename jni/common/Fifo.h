#ifndef DS_FIFO_H
#define DS_FIFO_H

class Fifo {

public:
	Fifo(int size);
	~Fifo();
	void putBytes(char *src, int bytelen);
	void putShorts(short *src, int shortlen) {
		putBytes((char*)src, shortlen*2);
	}
	int getBytes(char *dest, int bytelen);
	int getShorts(short *dest, int shortlen) {
		return getBytes((char*)dest, shortlen*2) / 2;
	}
	int filled() { return bufPtr - buffer; }

private:
	int size;
	char *buffer;
	char *bufPtr;

};

Fifo::Fifo(int size) {
	buffer = (char *)malloc(size);
	bufPtr = buffer;
}

Fifo::~Fifo() {
	free(buffer);
}

void Fifo::putBytes(char *src, int bytelen) {
	memcpy(bufPtr, src, bytelen);
	bufPtr += bytelen;
}

int Fifo::getBytes(char *dest, int bytelen) {

	int filled = bufPtr - buffer;
	if(bytelen > filled)
		bytelen = filled;

	memcpy(dest, buffer, bytelen);
	if(filled > bytelen)
		memmove(buffer, &buffer[bytelen], filled - bytelen);
	bufPtr = &buffer[filled - bytelen];

	return bytelen;
}

#endif
