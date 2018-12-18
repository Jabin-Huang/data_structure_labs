#include"Tree.h"

Tree T;

void test0() {
	T.createTree();
	cin.get();
}

void test1() {
	cout << "先序遍历：";
	T.printPre(T.treeRoot());
	cout << endl;
	cout << "后序遍历：";
	T.printPost(T.treeRoot());
	cout << endl;
	cout << "层次遍历：";
	T.printlevel(T.treeRoot());
	cout << endl;
	cin.get();
}
void test2() {
	cout << "森林的高度：";
	cout << T.height(T.treeRoot()) << endl;
	cin.get();
}
void test3() {
	cout << "森林的结点总数：";
	cout << T.numOfNode(T.treeRoot()) << endl;
	cin.get();
}
void test4() {
	cout << "森林叶子总数：";
	cout << T.numOflef(T.treeRoot()) << endl;
	cin.get();
}
void test5() {
	cout << "森林的度：";
	int ans = 0;
	T.numOfDegree(T.treeRoot(), 0, ans);
	cout << ans << endl ;
	cin.get();
}
void test6() {
	cout << "先序输出结点值及其层次号:";
	T.printPre_level(T.treeRoot(), 1);
	cin.get();
}
void test7() {
	cout << "输出广义表表示的树:";
	T.printList(T.treeRoot(), 1);
	cin.get();
}

int main() {
	while (true) {
		system("CLS");
		cout << "(0)从文件创建森林。" << "\n\n";
		cout << "(1)按先序、后序、层次遍历森林。" << "\n\n";
		cout << "(2)求森林的高度。" << "\n\n";
		cout << "(3)求森林结点总数。" << "\n\n";
		cout << "(4)求森林叶子结点数。" << "\n\n";
		cout << "(5)求森林的度。" << "\n\n";
		cout << "(6)先序输出结点值及其层次号。" << "\n\n";
		cout << "(7)输出广义表表示的树。" << "\n\n";
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