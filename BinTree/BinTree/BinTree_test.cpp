#include"BinTree.h"
#include<iostream>
#include<cstdlib>
#include "BinTree_test.h"

using namespace std;
void test1(BinTree T) {
	cout << "�������: ";
	T.PrintPreOrder(T.TreeRoot());
	cout << "�������: ";
	T.PrintInOrder(T.TreeRoot());
	cout << "���������";
	T.PrintPostOrder(T.TreeRoot());
}
void test2(BinTree T) {
	cout << "����������򼰶�Ӧ�������" << endl;
	T.PrintInOrder_level(T.TreeRoot(),1);
}

void test3(BinTree T) {

}
void test4(BinTree T) {

}
void test5(BinTree T) {

}
int main() {
	BinTree T,T1;
	while (true) {
			system("CLS");
			cout << "0.����������\n\n";
		    cout << "1.��ӡ�������������ֱ�����\n\n";
			cout << "2.����㷨�������������������и�����ֵ��������Ӧ�Ĳ������\n\n";
			cout << "3.��������ĸ߶ȡ�\n\n";
			cout << "4.��������Ľ������\n\n";
			cout << "5.���������Ҷ�ӽ������\n\n";
			cout << "6.��������Ķ�Ϊ2�Ľ������\n\n";
			cout << "7.��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��������ʱ������Ӧ��ʾ��Ϣ��\n";
			cout << "���ֵܽ��ͺ��ӽ�㣬����ʱҪ��ȷָ�������ֵܡ����ӡ����ֵܻ��Һ��ӡ�\n\n";
			cout << "8.��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ��\n\n";
			cout << "9.����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ����������Ҫ��չΪ��ȫ����������\n\n";
			cout<<"10.������������ÿ���������Һ���ָ���ֵ����������������Ϊ����������������Ϊ����������\n\n";
			int choose;
			cin >> choose;
			cin.get();
			switch (choose) {
			case 1:void test1(BinTree T); break;
			case 2:void test2(BinTree T); break;
			case 3:void test3(BinTree T); break;
			case 4:void test4(BinTree T); break;
			case 5:void test5(BinTree T); break;
			case 6:void test6(BinTree T); break;
			case 7:void test7(BinTree T); break;
			case 8:void test8(BinTree T); break;
			case 9:void test9(BinTree T); break;
			case 10:void test10(BinTree T); break;
			case 11:void test11(BinTree T); break;
			case 12:void test12(BinTree T); break;
			case 13:void test13(BinTree T); break;
			case 14:void test14(BinTree T); break;
			case 15:void test15(BinTree T); break;
			default:
				break;
			}

	}
}