#include"linkQueue.h"
#include"seqQueue.h"
#include"task.h"
#include<cstdlib>

int main() {
	linkQueue linkQ;
	seqQueue seqQ;
	while (true) {
		system("CLS");
		cout << "================˳��ѭ������================\n";
		cout << "1.��ʼ��һ�����С�\n\n";
		cout << "2.�ж��Ƿ�ӿա�\n\n";
		cout << "3.�ж��Ƿ������\n\n";
		cout << "4.���\n\n";
		cout << "5.����\n\n";
		cout << "6.ȡ��ͷԪ��\n\n";
		cout << "7.��ǰ������Ԫ�ظ���\n\n";
		cout << "8.����8��\n";
		cout << "��������������ʱ�����������\n";
		cout << "����������ż��ʱ����ͷ����\n";
		cout << "����������0ʱ���㷨�˳�\n\n";
		cout << "================������=====================\n";
		cout << "9.��ʼ��һ�����С�\n\n";
		cout << "10.�ж��Ƿ�ӿա�\n\n";
		cout << "11.�ж��Ƿ������\n\n";
		cout << "12.���\n\n";
		cout << "13.����\n\n";
		cout << "14.ȡ��ͷԪ��\n\n";
		cout << "15.��ǰ������Ԫ�ظ���\n\n";
		cout << "16.����8��\n";
		cout << "��������������ʱ�����������\n";
		cout << "����������ż��ʱ����ͷ����\n";
		cout << "����������0ʱ���㷨�˳�\n";
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