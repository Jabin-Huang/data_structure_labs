#include"Tree.h"

Tree T;

void test0() {
	T.createTree();
	cin.get();
}

void test1() {
	cout << "���������";
	T.printPre(T.treeRoot());
	cout << endl;
	cout << "���������";
	T.printPost(T.treeRoot());
	cout << endl;
	cout << "��α�����";
	T.printlevel(T.treeRoot());
	cout << endl;
	cin.get();
}
void test2() {
	cout << "ɭ�ֵĸ߶ȣ�";
	cout << T.height(T.treeRoot()) << endl;
	cin.get();
}
void test3() {
	cout << "ɭ�ֵĽ��������";
	cout << T.numOfNode(T.treeRoot()) << endl;
	cin.get();
}
void test4() {
	cout << "ɭ��Ҷ��������";
	cout << T.numOflef(T.treeRoot()) << endl;
	cin.get();
}
void test5() {
	cout << "ɭ�ֵĶȣ�";
	int ans = 0;
	T.numOfDegree(T.treeRoot(), 0, ans);
	cout << ans << endl ;
	cin.get();
}
void test6() {
	cout << "����������ֵ�����κ�:";
	T.printPre_level(T.treeRoot(), 1);
	cin.get();
}
void test7() {
	cout << "���������ʾ����:";
	T.printList(T.treeRoot(), 1);
	cin.get();
}

int main() {
	while (true) {
		system("CLS");
		cout << "(0)���ļ�����ɭ�֡�" << "\n\n";
		cout << "(1)�����򡢺��򡢲�α���ɭ�֡�" << "\n\n";
		cout << "(2)��ɭ�ֵĸ߶ȡ�" << "\n\n";
		cout << "(3)��ɭ�ֽ��������" << "\n\n";
		cout << "(4)��ɭ��Ҷ�ӽ������" << "\n\n";
		cout << "(5)��ɭ�ֵĶȡ�" << "\n\n";
		cout << "(6)����������ֵ�����κš�" << "\n\n";
		cout << "(7)���������ʾ������" << "\n\n";
		int choose;
		cin >> choose;
		cin.get();
		switch (choose) {
		case 0:test0(); break;
		case 1:test1(); break;
		case 2:test2(); break;
		case 3:test3(); break;
		case 4:test4(); break;
		case 5:test5(); break;
		case 6:test6(); break;
		case 7:test7(); break;
		default:
			break;
		}
	}
	return 0;
}