#pragma once

#include<iostream>
using namespace std;

#define MAXLEN 100

typedef int elementType;

typedef struct Node {
	elementType data;
	struct Node *next;
}node;

class linkQueue {
private:
	node *front, *rear;
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

void linkQueue::init() {
	front = rear = NULL;
}

bool linkQueue::empty() {
	return front==NULL;
}

bool linkQueue::full() {
	return length() == MAXLEN;
}

int linkQueue::length() {
	node *p1=front;
	int len = 0;
	while (p1 != NULL) {
		p1 = p1->next;
		len++;
	}
	return len;
}

void linkQueue::enqueue(elementType const& x) {
	if (full()) {
		cout << "队满！无法入队!" << endl;
	}
	else {
		if (empty()) {
			front = rear = new node;
			front->data = x;
			front->next = NULL;
		}
		else {
			rear->next = new node;
			rear->next->data = x;
			rear->next->next = NULL;
			rear = rear->next;
		}
	}
}

void linkQueue::dequeue() {
	if (empty()) {
		cout << "队空！无法出队!" << endl;
	}
	else {
		node *p = front;
		front = front->next;
		delete p;
	}
}

void linkQueue::getFront(elementType &x) {
	if (empty()) {
		cout << "队空！无法获取队头!" << endl;
	}
	else {
		x = front->data;
	}
}


void linkQueue::print() {
	if (!empty()) {
		node *p1 = front;
		while (p1 != NULL) {
			cout << p1->data << ' ';
			p1 = p1->next;
		}
		cout << endl;
	}
}
