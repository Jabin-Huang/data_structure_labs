#include"BinTree.h"
#include<iostream>
#include<cstdlib>


using namespace std;

void test0(BinTree &T) {
	char filename[80];
	char strLine[100][3];
	int nArrlen=0, nRow = 0;
	cout << "�����ļ���" << endl;
	cin >> filename;
	cin.get();
	if (!ReadFileToArray(filename, strLine, nArrlen)) {
		cout << "��ȡ�ļ�ʧ��" << endl;
		cin.get();
		return;
	}
	if (!T.createTree(T.TreeRoot(), NULL, strLine, nArrlen, nRow)) {
		cout << "����ʧ�ܣ�" << endl;
		cin.get();
	}
	else cout << "�����ɹ���" << endl;
	cout <<"������ַ��"<<T.TreeRoot() << endl;
	cin.get();
}

void test1(BinTree &T) {
	cout << "�������: ";
	T.PrintPreOrder(T.TreeRoot());
	cout << endl;
	cout << "�������: ";
	T.PrintInOrder(T.TreeRoot());
	cout << endl;
	cout << "���������";
	T.PrintPostOrder(T.TreeRoot());
	cout << endl;
	cin.get();
}
void test2(BinTree &T) {
	cout << "����������򼰶�Ӧ�������" << endl;
	T.PrintInOrder_level(T.TreeRoot(),1);
	cin.get();
}

void test3(BinTree &T) {
	cout<<"�������ĸ߶�Ϊ:"<<T.height(T.TreeRoot())<<endl;
	cin.get();
}
void test4(BinTree &T) {
	cout << "�������Ľ����Ϊ��" << T.numOfnode(T.TreeRoot()) << endl;
	cin.get();
}
void test5(BinTree &T) {
	cout << "Ҷ�ӽ����:" << T.numOflef(T.TreeRoot()) << endl;
	cin.get();
}
void test6(BinTree &T) {
	int i = 0;
	T.numOfTwoDegree(T.TreeRoot(), i);
	cout << "��Ϊ2�Ľ����:" <<i << endl;
	cin.get();
}
void test7(BinTree &T) {
	cout << "����һ��Ԫ�أ�";
	elementType x;
	cin >> x;
	cin.get();
	T.nbrinfo(x);
	cin.get();
}
void test8(BinTree &T) {
	cout << "����һ��Ԫ�أ�";
	elementType x;
	cin >> x;
	cin.get();
	if (!T.level(T.TreeRoot(), x, 1)) {
		cout << "�����ڸ�Ԫ��" << endl;
	}
	cin.get();
}
void test9(BinTree &T) {
	elementType A[1000];
	memset(A, 0, sizeof(A));
	int i = 0;
	cout << "���±�˳�����������(��'#'����)��";
	while ( i==0 || A[i] != '#') {
		cin >> A[++i];
	}
	cin.get();
	T.convertFromArray(T.TreeRoot(), A,1);
	cout << "ת����ɣ��������Ĳ�α�������Ϊ��";
	T.printInLevel(T.TreeRoot());
	cin.get();
}

void test10(BinTree &T) {
	cout << "����ǰ,���α������У�";
	T.printInLevel(T.TreeRoot());
	cout << endl;
	T.swapLR(T.TreeRoot());
	cout << "������,���α������У�";
	T.printInLevel(T.TreeRoot());
	cout << endl;
	cin.get();

}

void test11(BinTree &T) {
	BinTree T1;
	T1.copyTree(T.TreeRoot(), T1.TreeRoot());
	cout << "��������T�Ĳ�α������У�";
	T.printInLevel(T.TreeRoot());
	cout << " ������T1�Ĳ�α������У�";
	T1.printInLevel(T1.TreeRoot());
	cin.get();

}

void test12(BinTree &T) {
	cout << "����Ҷ�ӵ�������·����" << endl;
	T.printPath(T.TreeRoot());
	cin.get();
}

void test13(BinTree &T) {
	cout << "��α������У�";
	T.printInLevel(T.TreeRoot());
	cin.get();
}

void test14(BinTree &T) {
	elementType a,b;
	cout << "�����������Ԫ�أ�";
	cin >> a >> b;
	cin.get();
	cout << "���ߵ�������������ǣ�" << endl;
	cout<<T.LCA(T.find(T.TreeRoot(),a), T.find(T.TreeRoot(),b))->data<<endl;
	cin.get();
}

void test15(BinTree T) {
	int res = 0;
	elementType path[1000];
	T.findLongest(T.TreeRoot(), 0, res, path);
	cout << "�·������:" << res <<endl;
	for (int i = res; i >0; i--) {
		cout << path[i] << "-->";
	}
	cout << path[0] << endl;
	cin.get();
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
			cout << "10.������������ÿ���������Һ���ָ���ֵ����������������Ϊ����������������Ϊ����������\n\n";
			cout << "11.����һ�ö�����T��T1��\n\n";
			cout << "12.�����������ÿ��Ҷ�ӽ�㵽������·���������Ľ�㣩\n\n";
			cout << "13.�Զ��������ʾ�Ķ������������ϵ��£������Ҵ�ӡ���ֵ��������δ�ӡ��\n\n";
			cout << "14.�Զ��������ʾ�Ķ���������2���������Ĺ�ͬ���ȡ�\n\n";
			cout << "15.���������һ�����·�����ȣ��������������·���ϵĸ����ֵ��\n\n";
			int choose;
			cin >> choose;
			cin.get();
			switch (choose) {
			case 0: test0( T); break;
			case 1: test1( T); break;
			case 2: test2( T); break;
			case 3: test3( T); break;
			case 4:  test4( T); break;
			case 5:  test5( T); break;
			case 6:  test6( T); break;
			case 7:  test7( T); break;
			case 8:  test8( T); break;
			case 9:  test9( T); break;
			case 10: test10( T); break;
			case 11: test11( T); break;
			case 12: test12( T); break;
			case 13: test13( T); break;
			case 14: test14( T); break;
			case 15: test15( T); break;
			default:
				break;
			}

	}
}