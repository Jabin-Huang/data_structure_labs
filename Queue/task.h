#pragma once

#include<iostream>
using namespace std;


void linkQueuetask1(linkQueue& Q) {
	Q.init();
	cout << "初始化成功！\n";
	cin.get();
}

void linkQueuetask2(linkQueue& Q) {
	if (Q.empty()) {
		cout << "队空" << endl;
	}
	else {
	   cout << "队不空" << endl;
	}
	cin.get();
}
void linkQueuetask3(linkQueue& Q) {
	if (Q.full()) {
		cout << "队满" << endl;
	}
	else {
		cout << "队未满" << endl;
	}
	cin.get();
}
void linkQueuetask4(linkQueue& Q) {
	int choose;
	cout << "1.依次输入入队元素（以-1结束）" << endl;
	cout << "2.或输入n 将1到n的数依次入队" << endl;
	cout << "请选择输入方式：";
	cin >> choose;
	cin.get();
	switch (choose) {
	case 1: {
		int x;
		cin >> x;
		cin.get();
		while (x != -1) {
			Q.enqueue(x);
			cin >> x;
			cin.get();
		}
		cout << "当前队列：";
		Q.print();
		break;
	}
	case 2: {
		int n;
		cin >> n;
		cin.get();
		for (int i = 1; i <=n ; i++) {
			Q.enqueue(i);
		}
		cout << "当前队列：";
		Q.print();
		break;
	}
	default:
		break;
	}
	cin.get();
}

void linkQueuetask5(linkQueue& Q) {
	elementType t=99999; 
	Q.getFront(t);
	if (t != 99999) {
		Q.dequeue();
		cout << "出队成功\n出队的元素为：" << t<<endl;
	}
	cin.get();
}
void linkQueuetask6(linkQueue& Q) {
	elementType t = 99999;
	Q.getFront(t);
	if (t != 99999) {
		cout << "队首元素为: " << t << endl;
	}
	cin.get();
}
void linkQueuetask7(linkQueue& Q) {
	cout << "当前队列元素个数为: " << Q.length();
	cin.get();
}

void linkQueuetask8(linkQueue& Q) {
	Q.init();
	int n = 1;
	while (n != 0) {
		cin >> n;
		cin.get();
		if (n % 2 != 0) {
			Q.enqueue(n);
			cout << "奇数已入队:";
			Q.print();
		}
		else if (n % 2 == 0 && n != 0) {
			Q.dequeue();
			cout << "队头已出队:";
			Q.print();
		}
	}
	cout << "算法退出" << endl;
	cin.get();
}
 

void seqQueuetask1(seqQueue& Q) {
	Q.init();
	cout << "初始化成功！\n";
	cin.get();
}

void seqQueuetask2(seqQueue& Q) {
	if (Q.empty()) {
		cout << "队空" << endl;
	}
	else {
		cout << "队不空" << endl;
	}
	cin.get();
}
void seqQueuetask3(seqQueue& Q) {
	if (Q.full()) {
		cout << "队满" << endl;
	}
	else {
		cout << "队未满" << endl;
	}
	cin.get();
}
void seqQueuetask4(seqQueue& Q) {
	int choose;
	cout << "1.依次输入入队元素（以-1结束）" << endl;
	cout << "2.或输入n 将1到n的数依次入队" << endl;
	cout << "请选择输入方式：";
	cin >> choose;
	cin.get();
	switch (choose) {
	case 1: {
		int x;
		cin >> x;
		cin.get();
		while (x != -1) {
			Q.enqueue(x);
			cin >> x;
			cin.get();
		}
		cout << "当前队列：";
		Q.print();
		break;
	}
	case 2: {
		int n;
		cin >> n;
		cin.get();
		for (int i = 1; i <= n; i++) {
			Q.enqueue(i);
		}
		cout << "当前队列：";
		Q.print();
		break;
	}
	default:
		break;
	}
	cin.get();

}

void seqQueuetask5(seqQueue& Q) {
	elementType t = 99999;
	Q.getFront(t);
	if (t != 99999) {
		Q.dequeue();
		cout << "出队成功\n出队的元素为：" << t << endl;
	}
	cin.get();
}
void seqQueuetask6(seqQueue& Q) {
	elementType t = 99999;
	Q.getFront(t);
	if (t != 99999) {
		cout << "队首元素为: " << t << endl;
	}
	cin.get();
}
void seqQueuetask7(seqQueue& Q) {
	cout << "当前队列元素个数为: " << Q.length();
	cin.get();
}

void seqQueuetask8(seqQueue& Q) {
	Q.init();
	int n = 1;
	while (n != 0) {
		cin >> n;
		cin.get();
		if (n % 2 != 0) {
			Q.enqueue(n);
			cout << "奇数已入队:";
			Q.print();
		}
		else if (n % 2 == 0 && n != 0) {
			Q.dequeue();
			cout << "队头已出队:";
			Q.print();
		}
	}
	cout << "算法退出" << endl;
	cin.get();
}