#include"BinTree.h"
#include<iostream>
#include<cstdlib>


using namespace std;

void test0(BinTree &T) {
	char filename[80];
	char strLine[100][3];
	int nArrlen=0, nRow = 0;
	cout << "输入文件名" << endl;
	cin >> filename;
	cin.get();
	if (!ReadFileToArray(filename, strLine, nArrlen)) {
		cout << "读取文件失败" << endl;
		cin.get();
		return;
	}
	if (!T.createTree(T.TreeRoot(), NULL, strLine, nArrlen, nRow)) {
		cout << "创建失败！" << endl;
		cin.get();
	}
	else cout << "创建成功！" << endl;
	cout <<"根结点地址："<<T.TreeRoot() << endl;
	cin.get();
}

void test1(BinTree &T) {
	cout << "先序遍历: ";
	T.PrintPreOrder(T.TreeRoot());
	cout << endl;
	cout << "中序遍历: ";
	T.PrintInOrder(T.TreeRoot());
	cout << endl;
	cout << "后序遍历：";
	T.PrintPostOrder(T.TreeRoot());
	cout << endl;
	cin.get();
}
void test2(BinTree &T) {
	cout << "中序遍历次序及对应层次数：" << endl;
	T.PrintInOrder_level(T.TreeRoot(),1);
	cin.get();
}

void test3(BinTree &T) {
	cout<<"二叉树的高度为:"<<T.height(T.TreeRoot())<<endl;
	cin.get();
}
void test4(BinTree &T) {
	cout << "二叉树的结点数为：" << T.numOfnode(T.TreeRoot()) << endl;
	cin.get();
}
void test5(BinTree &T) {
	cout << "叶子结点数:" << T.numOflef(T.TreeRoot()) << endl;
	cin.get();
}
void test6(BinTree &T) {
	int i = 0;
	T.numOfTwoDegree(T.TreeRoot(), i);
	cout << "度为2的结点数:" <<i << endl;
	cin.get();
}
void test7(BinTree &T) {
	cout << "输入一个元素：";
	elementType x;
	cin >> x;
	cin.get();
	T.nbrinfo(x);
	cin.get();
}
void test8(BinTree &T) {
	cout << "输入一个元素：";
	elementType x;
	cin >> x;
	cin.get();
	if (!T.level(T.TreeRoot(), x, 1)) {
		cout << "不存在该元素" << endl;
	}
	cin.get();
}
void test9(BinTree &T) {
	elementType A[1000];
	memset(A, 0, sizeof(A));
	int i = 0;
	cout << "按下标顺序输入该数组(以'#'结束)：";
	while ( i==0 || A[i] != '#') {
		cin >> A[++i];
	}
	cin.get();
	T.convertFromArray(T.TreeRoot(), A,1);
	cout << "转换完成，二叉树的层次遍历序列为：";
	T.printInLevel(T.TreeRoot());
	cin.get();
}

void test10(BinTree &T) {
	cout << "交换前,其层次遍历序列：";
	T.printInLevel(T.TreeRoot());
	cout << endl;
	T.swapLR(T.TreeRoot());
	cout << "交换后,其层次遍历序列：";
	T.printInLevel(T.TreeRoot());
	cout << endl;
	cin.get();

}

void test11(BinTree &T) {
	BinTree T1;
	T1.copyTree(T.TreeRoot(), T1.TreeRoot());
	cout << "被复制树T的层次遍历序列：";
	T.printInLevel(T.TreeRoot());
	cout << " 复制树T1的层次遍历序列：";
	T1.printInLevel(T1.TreeRoot());
	cin.get();

}

void test12(BinTree &T) {
	cout << "所有叶子到根结点的路径：" << endl;
	T.printPath(T.TreeRoot());
	cin.get();
}

void test13(BinTree &T) {
	cout << "层次遍历序列：";
	T.printInLevel(T.TreeRoot());
	cin.get();
}

void test14(BinTree &T) {
	elementType a,b;
	cout << "输入两个结点元素：";
	cin >> a >> b;
	cin.get();
	cout << "两者的最近公共祖先是：" << endl;
	cout<<T.LCA(T.find(T.TreeRoot(),a), T.find(T.TreeRoot(),b))->data<<endl;
	cin.get();
}

void test15(BinTree T) {
	int res = 0;
	elementType path[1000];
	T.findLongest(T.TreeRoot(), 0, res, path);
	cout << "最长路径长度:" << res <<endl;
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
			cout << "10.交换二叉树中每个结点的左右孩子指针的值。（即：左子树变为右子树，右子树变为左子树）。\n\n";
			cout << "11.复制一棵二叉树T到T1。\n\n";
			cout << "12.输出二叉树从每个叶子结点到根结点的路径（经历的结点）\n\n";
			cout << "13.对二叉链表表示的二叉树，按从上到下，从左到右打印结点值，即按层次打印。\n\n";
			cout << "14.对二叉链表表示的二叉树，求2个结点最近的共同祖先。\n\n";
			cout << "15.求二叉树中一条最长的路径长度（边数），并输出路径上的个结点值。\n\n";
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