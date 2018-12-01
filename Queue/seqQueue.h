#pragma once

#define MAXLEN 1000

typedef int elementType;

class seqQueue {
private:
	elementType data[MAXLEN];
	int front, rear;
public:
	void init();

};

void seqQueue::init() {
	front = 0;
	rear = 0;

}