#pragma once

#include<iostream>
using namespace std;


void linkQueuetask1(linkQueue& Q) {
	Q.init();
	cout << "��ʼ���ɹ���\n";
	cin.get();
}

void linkQueuetask2(linkQueue& Q) {
	if (Q.empty()) {
		cout << "�ӿ�" << endl;
	}
	else {
	   cout << "�Ӳ���" << endl;
	}
	cin.get();
}
void linkQueuetask3(linkQueue& Q) {
	if (Q.full()) {
		cout << "����" << endl;
	}
	else {
		cout << "��δ��" << endl;
	}
	cin.get();
}
void linkQueuetask4(linkQueue& Q) {
	int choose;
	cout << "1.�����������Ԫ�أ���-1������" << endl;
	cout << "2.������n ��1��n�����������" << endl;
	cout << "��ѡ�����뷽ʽ��";
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
		cout << "��ǰ���У�";
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
		cout << "��ǰ���У�";
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
		cout << "���ӳɹ�\n���ӵ�Ԫ��Ϊ��" << t<<endl;
	}
	cin.get();
}
void linkQueuetask6(linkQueue& Q) {
	elementType t = 99999;
	Q.getFront(t);
	if (t != 99999) {
		cout << "����Ԫ��Ϊ: " << t << endl;
	}
	cin.get();
}
void linkQueuetask7(linkQueue& Q) {
	cout << "��ǰ����Ԫ�ظ���Ϊ: " << Q.length();
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
			cout << "���������:";
			Q.print();
		}
		else if (n % 2 == 0 && n != 0) {
			Q.dequeue();
			cout << "��ͷ�ѳ���:";
			Q.print();
		}
	}
	cout << "�㷨�˳�" << endl;
	cin.get();
}
 

void seqQueuetask1(seqQueue& Q) {
	Q.init();
	cout << "��ʼ���ɹ���\n";
	cin.get();
}

void seqQueuetask2(seqQueue& Q) {
	if (Q.empty()) {
		cout << "�ӿ�" << endl;
	}
	else {
		cout << "�Ӳ���" << endl;
	}
	cin.get();
}
void seqQueuetask3(seqQueue& Q) {
	if (Q.full()) {
		cout << "����" << endl;
	}
	else {
		cout << "��δ��" << endl;
	}
	cin.get();
}
void seqQueuetask4(seqQueue& Q) {
	int choose;
	cout << "1.�����������Ԫ�أ���-1������" << endl;
	cout << "2.������n ��1��n�����������" << endl;
	cout << "��ѡ�����뷽ʽ��";
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
		cout << "��ǰ���У�";
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
		cout << "��ǰ���У�";
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
		cout << "���ӳɹ�\n���ӵ�Ԫ��Ϊ��" << t << endl;
	}
	cin.get();
}
void seqQueuetask6(seqQueue& Q) {
	elementType t = 99999;
	Q.getFront(t);
	if (t != 99999) {
		cout << "����Ԫ��Ϊ: " << t << endl;
	}
	cin.get();
}
void seqQueuetask7(seqQueue& Q) {
	cout << "��ǰ����Ԫ�ظ���Ϊ: " << Q.length();
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
			cout << "���������:";
			Q.print();
		}
		else if (n % 2 == 0 && n != 0) {
			Q.dequeue();
			cout << "��ͷ�ѳ���:";
			Q.print();
		}
	}
	cout << "�㷨�˳�" << endl;
	cin.get();
}