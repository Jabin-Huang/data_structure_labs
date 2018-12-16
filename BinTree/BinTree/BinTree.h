#pragma once
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef char elementType;
typedef struct Node {
	elementType data;
	struct Node *lc, *rc,*parent;
}node;
 
class BinTree {
private:
	node *root=NULL;
public:
	bool createTree(node *& root, node * par,char strLine[100][3], int nLen, int &nRow);
	void PrintPreOrder(node *T);
	void PrintInOrder(node *T);
	void PrintPostOrder(node *T);
	void PrintInOrder_level(node *T, int i); //中序遍历输出结点值及对应层次数
	int height(node *T);
	int numOfnode(node *T);
	int numOflef(node *T);
	void numOfTwoDegree(node *T,int &i);
	node* find(node *T,elementType e);
	void nbrinfo(elementType e);
	bool level(node *T,elementType e,int i);
	bool empty() { return !root; };
	node*& TreeRoot() { return root; }
	void convertFromArray(node *&T, elementType A[], int i);
	void swapLR(node*&T);
	void copyTree(node *T, node*&T1);
	void printPath(node*T);
	void printInLevel(node *T);
	node* LCA(node *a, node *b);
	void findLongest(node *T,int step,int &maxx,elementType path[]);
};

#include"CreateTree.h"
#include"Function.h"