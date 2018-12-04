#include"linkQueue.h"
#include"seqQueue.h"
#include"task.h"
#include<cstdlib>

int main() {
	linkQueue linkQ;
	seqQueue seqQ;
	while (true) {
		system("CLS");
		cout << "================顺序循环队列================\n";
		cout << "1.初始化一个队列。\n\n";
		cout << "2.判断是否队空。\n\n";
		cout << "3.判断是否队满。\n\n";
		cout << "4.入队\n\n";
		cout << "5.出队\n\n";
		cout << "6.取队头元素\n\n";
		cout << "7.求当前队列中元素个数\n\n";
		cout << "8.任务8：\n";
		cout << "当键盘输入奇数时，此奇数入队\n";
		cout << "当键盘输入偶数时，队头出队\n";
		cout << "当键盘输入0时，算法退出\n\n";
		cout << "================链队列=====================\n";
		cout << "9.初始化一个队列。\n\n";
		cout << "10.判断是否队空。\n\n";
		cout << "11.判断是否队满。\n\n";
		cout << "12.入队\n\n";
		cout << "13.出队\n\n";
		cout << "14.取队头元素\n\n";
		cout << "15.求当前队列中元素个数\n\n";
		cout << "16.任务8：\n";
		cout << "当键盘输入奇数时，此奇数入队\n";
		cout << "当键盘输入偶数时，队头出队\n";
		cout << "当键盘输入0时，算法退出\n";
		cout << "===========================================\n";
		int choose;
		cin >> choose;
		cin.get();
		switch (choose) {
			case 1:seqQueuetask1(seqQ); break;
			case 2:seqQueuetask2(seqQ); break;
			case 3:seqQueuetask3(seqQ); break;
			case 4:seqQueuetask4(seqQ); break;
			case 5:seqQueuetask5(seqQ); break;
			case 6:seqQueuetask6(seqQ); break;
			case 7:seqQueuetask7(seqQ); break;
			case 8:seqQueuetask8(seqQ); break;
			case 9:linkQueuetask1(linkQ); break;
			case 10:linkQueuetask2(linkQ); break;
			case 11:linkQueuetask3(linkQ); break;
			case 12:linkQueuetask4(linkQ); break;
			case 13:linkQueuetask5(linkQ); break;
			case 14:linkQueuetask6(linkQ); break;
			case 15:linkQueuetask7(linkQ); break;
			case 16:linkQueuetask8(linkQ); break;

			default:
				break;
		}
	}
	return 0;
}