#include"BinTree.h"
#include<iostream>
#include<cstdlib>

using namespace std;
void test1(BinTree T) {
	cout << "先序遍历: ";
	T.preOrderTrav(T.TreeRoot(),visit);
	cout << "中序遍历: ";
	T.inOrderTrav(T.TreeRoot(),visit);
	cout << "后序遍历：";
	T.postOrderTrav(T.TreeRoot(), visit);
}
void test2(BinTree T) {
	cout << "中序遍历次序及对应层次数：" << endl;

}
int main() {
	BinTree T;
	while (true) {
			system("CLS");
			cout << "0.创建二叉树\n\n";
		    cout << "1.打印出二叉树的三种遍历序。\n\n";
			cout << "2.设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数。\n\n";
			cout << "3.求二叉树的高度。\n\n";
			cout << "4.求二叉树的结点数。\n\n";
			cout << "5.求二叉树的叶子结点数。\n\n";
			cout << "6.求二叉树的度为2的结点数。\n\n";
			cout << "7.键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，不存在时给出相应提示信息。\n";
			cout << "对兄弟结点和孩子结点，存在时要明确指出是左兄弟、左孩子、右兄弟或右孩子。\n\n";
			cout << "8.键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息。\n\n";
			cout << "9.将按顺序方式存储在数组中的二叉树转换为二叉链表形式。（数组中要扩展为完全二叉树）。\n\n";
			cout<<"10.交换二叉树中每个结点的左右孩子指针的值。（即：左子树变为右子树，右子树变为左子树）。\n\n";
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
			default:
				break;
			}

	}
}