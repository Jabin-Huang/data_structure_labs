#pragma once
#include<iostream>
using namespace std;
#define sMAXLEN 100

typedef int elementType;

class seqQueue {
private:
	elementType data[sMAXLEN];
	int front, rear;
public:
	void init();
	bool empty();
	bool full();
	void enqueue(elementType const& x);
	void getFront(elementType &x);
	void dequeue();
	int length();
	void print();
};

void seqQueue::init() {
	front = 0;
	rear = 0;
}
bool seqQueue::empty() {
	if (front == rear) {
		return true;
	}
	else {
		return false;
	}
}

bool seqQueue::full() {
	if ((rear + 1) % sMAXLEN==front) {
		return true;
	}
	else {
		return false;
	}
}

void seqQueue::getFront(elementType &x) {
	if (empty()) {
		cout << "队空！不能取元素！" << endl;
	}
	else {
		x = data[(front + 1) % sMAXLEN];
	}
}

void seqQueue::enqueue(elementType const& x) {
	if (full()) {
		cout << "队满！不能再入队！" << endl;
	}
	else {
		rear = (rear + 1) % sMAXLEN;
		data[rear] = x;
	}
}

void seqQueue::dequeue() {
	if (empty()) {
		cout << "空队列！不能再出队！" << endl;
	}
	else {
		front = (front + 1) % sMAXLEN;
	}
}

int seqQueue::length() {
	int len = 0;
	for (int i = front+1; i != (rear+1)%sMAXLEN;i=(i+1)%sMAXLEN) {
		len++;
	}
	return len;
}

void seqQueue::print() {
	if (!empty()) {
		for (int i = front + 1; i != (rear+1)%sMAXLEN; i = (i + 1) % sMAXLEN) {
			cout << data[i] << ' ';
		}
		cout << endl;
	}
}
