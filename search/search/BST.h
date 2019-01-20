#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

typedef int keytype;

typedef struct Bnode {
	keytype data;//关键字
	int height;//该节点的高度，用于AVL调整
	struct Bnode *lc, *rc; //左孩子，右孩子
}node;


//二叉排序树的插入算法
void insert(node *&T, node *s) {
	if (T == NULL) { //若当前结点为空，则在此插入
		T = s;
	}
	else if (s->data < T->data) { //若插入值比当前结点小，则往左子树递归
		insert(T->lc, s);
	}
	else {//若插入值比当前结点大，则往右子树递归
		insert(T->rc, s);
	}
}

//创建二叉排序树
void createBst(node *&T) {
	T = NULL;
	keytype x;
	cout << "输入数据（以-999结束）：";
	while (cin>>x&&x != -999) {
		node *s = new node;
		s->data = x;
		s->lc = NULL;
		s->rc = NULL;
		insert(T, s);
	}
}


//二叉排序树查找某个元素值
node *&BstSearch(node *&T, keytype x) {
	//T为当前根结点地址
	if (!T|| x==T->data) { //当T为空或T所指的值为要查询的x时，返回T
		return T;
	}
	//当x比当前结点值小时，继续往左子树递归查找；否则往右子树递归查找
	if (x < T->data) return BstSearch(T->lc, x);
	else return BstSearch(T->rc, x);
}

//求p左右子树都存在时的直接前驱和直接前驱的父结点（par）
node *pre(node *p,node *&par) {
	par = p;
	p = p->lc;
	while (p->rc) {
		par = p;
		p = p->rc;
	}
	return p;//直接前驱即p左子树中的最大值
}

//二叉排序树的删除算法
void remove(node *&T, keytype x) {
	node *&p = BstSearch(T, x);//定位待删除的结点
	if (p->lc == NULL && p->rc == NULL) {//若是叶子结点
		delete p;
		p = NULL;
	}
	else if (p->lc == NULL&&p->rc!=NULL) { //若左子树为空，右子树不空
		node *u = p;
		p = p->rc;
		delete u;
	}
	else if (p->rc == NULL && p->lc != NULL) {//若右子树为空，左子树不空，则如上种情况对称处理
		node *u = p;
		p = p->lc;
		delete u;
	}
	else if (p->lc != NULL && p->rc != NULL) {//若左右子树都不为空，则采用直接前驱将其顶替
		node *parOfPre;
		node *Pre = pre(p,parOfPre);//Pre为p的直接前驱，parOfPre为直接前驱的父亲
		//此种情况p的直接前驱必无右子树，可能有左子树
		//若直接前驱的父结点不为x，则可直接将其左子树接到父结点的右孩子上
		if (parOfPre->data != x) {
			p->data = Pre->data;//将直接前驱的值赋给p
			parOfPre->rc = Pre->lc;
		}
		else { //若直接前驱的父结点刚好为x，则将其左子树接到父结点（x）的左孩子
			p->data = Pre->data;//将直接前驱的值赋给p
			parOfPre->lc = Pre->lc;
		}
		delete Pre;
	}
}

//更新树的高度（用于AVL）
int updateHeight(node *p) {
	if (p == NULL) return 0;
	return (p->height = max(updateHeight(p->lc) , updateHeight(p->rc)) + 1);
}


node *LLrotate(node *A) { //"LL"型失衡的调整，A为最低不平衡结点
	node *B=A->lc;
	A->lc = B->rc; //将B的右子树调为A的左子树
	B->rc = A; //将A调为B的右孩子
	
	//更新高度
	updateHeight(A);
	updateHeight(B);
	return B;//返回调整后的新根节点
}

node *RRrotate(node *A) {//"RR"型失衡的调整，A为最低不平衡结点
	node *B = A->rc;
	A->rc = B->lc; //将B的左子树调为A的右子树
	B->lc = A; //将A调为B的左孩子

	//更新高度
	updateHeight(A);
	updateHeight(B);
	return B;//返回调整后的新根节点
} 

node *LRrotate(node *A) {//"LR"型失衡的调整，A为最低不平衡结点
	node *B = A->lc;
	node *C = B->rc;
	A->lc = C->rc;
	B->rc = C->lc;
	C->lc = B;
	C->rc = A;

	updateHeight(A);
	updateHeight(B);
	updateHeight(C);
	return C;
}

node *RLrotate(node *A) {//"RL"型失衡的调整，A为最低不平衡结点
	node *B = A->rc;
	node *C = B->lc;
	A->rc = C->lc;
	B->lc = C->rc;
	C->lc = A;
	C->rc = B;

	updateHeight(A);
	updateHeight(B);
	updateHeight(C);
	return C;
}

//判断平衡
bool isBalenced(node *root) {
	int a, b;
	if (root->lc) a = root->lc->height;
	else a = 0;
	if (root->rc) b = root->rc->height;
	else b = 0;
	return fabs(a-b) <= 1;
}

//AVL的插入算法
node* AVLinsert(node *&root,keytype x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->lc = NULL;
		root->rc = NULL;
		root->height = 1;
		return root;
	}
	if (x > root->data) {//x比当前根结点大，插入在右子树中
		root->rc = AVLinsert(root->rc, x); //将调整好的子树的根结点赋值给右孩子
		if (!isBalenced(root)) {
			if (x > root->rc->data) //"RR"型失衡
				root = RRrotate(root);
			else root = RLrotate(root);//"RL"型失衡
		}
	}
	else {//x比当前根结点小，插入在左子树中
		root->lc = AVLinsert(root->lc, x);////将调整好的子树的根结点赋值给左孩子
		if (!isBalenced(root)) {
			if (x < root->lc->data)//“LL”型失衡
				root = LLrotate(root);
			else root = LRrotate(root);//”LR“型失衡
		}
	}
	updateHeight(root);
	return root; //返回调整后的根节点
}

//先序打印
void PrePrint(node *root) {
	if (root) {
		cout << root->data << " ";
		PrePrint(root->lc);
		PrePrint(root->rc);
	}
}

//中序打印
void InPrint(node *root) {
	if (root) {
		InPrint(root->lc);
		cout << root->data << " ";
		InPrint(root->rc);
	}
}

//打印二叉树的序列
void printBST(node *root) {
	cout << "先序序列：";
	PrePrint(root);
	cout << endl;
	cout << "中序序列：" ;
	InPrint(root);
	cout << endl;
	cin.get();
}

