#include"bin_search.h"
#include"BST.h"
#include<cstdio>
#include<iostream>
#include<cstdlib>

#define MAXLEN 10000
using namespace std;

elementType A[MAXLEN];
node *root;
node *AVL;
void test1() {
	cout << "输入数据（以-999结束）：";
	keytype x;
	int i = 0;
	while (cin >> x && x != -999) {
		A[i++].key = x;
	}
	cout << "输入要查找的元素（以-999结束）：";
	while (cin >> x && x != -999) {
		if (bin_search(A, i, x) == -1) {
			cout << "不存在该元素！" << endl;
		}
	}
	cin.get();
}
void test2() {
	createBst(root);
	cout << "创建结果：\n";
	printBST(root);
	cin.get();
}
void test3() {
	keytype x;
	cout << "输入要查找的元素（以-999结束）：";
	while (cin >> x && x != -999) {
		node *addr=NULL;
		if (addr=BstSearch(root,x)) {
			cout << "该元素地址为：" << addr << endl;
		}
		else {
			cout << "不存在该元素!" << endl;
		}
	}
	cin.get();
}
void test4() {
	keytype x;
	cout << "删除前：\n";
	printBST(root);
	cout << "输入要删除的元素（以-999结束）：";
	while (cin >> x && x != -999) {
		remove(root, x);
		cout << "删除后：" << endl;
		printBST(root);
	}
	cin.get();
}
void test5() {
	cout << "输入数据（以-999结束）：";
	keytype x;
	while (cin >> x && x != -999) {
		AVLinsert(AVL, x);
	}
	cout << "创建成功！" << endl;
	printBST(AVL);
	cout << "根结点左子树高度：";
	if (AVL->lc) {
		cout << AVL->lc->height<<endl;
	}
	else cout << 0 << endl;
	cout << "根结点右子树高度：";
	if (AVL->rc) {
		cout << AVL->rc->height << endl;
	}
	else cout << 0 << endl;
	cin.get();
}

int main() {
	int choose;
	while (true) {
		system("CLS");
		cout << "(1) 对给定数据表，采用二分查找算法实现查找，给出查找过程依次所比较的元素（的下标）。" << "\n\n";
		cout << "(2) 由输入序列构建二叉排序树" << "\n\n";
		cout << "(3) 在二叉排序树中查找指定值的结点" << "\n\n";
		cout << "(4) 在二叉排序树中删除特定值的结点。" << "\n\n";
		cout << "(5) 构建AVL。" << "\n\n";
		cout << "输入序号以测试：" << "\n\n";
		cin >> choose;
		cin.get();
		switch (choose) {
		case 1:test1(); cin.get(); break;
		case 2:test2(); cin.get(); break;
		case 3:test3(); cin.get(); break;
		case 4:test4(); cin.get(); break;
		case 5:test5(); cin.get(); break;
		default:
			break;
		}
	}

	return 0;
}