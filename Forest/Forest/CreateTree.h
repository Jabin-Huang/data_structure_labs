#pragma once

#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAXLEN 1000
typedef char elementType;

//先创建双亲表示的森林，再由此森林转化为兄弟-孩子链表表示。

typedef struct pNode {
	elementType data;   //结点数据域
	int parent;         //父结点指针（下标）

}PTNode;

//双亲表示的树（森林）结构
typedef struct pTree {
	PTNode node[MAXLEN];   //结点数组
	int n;              //结点总数
}pTree;

void init(pTree &T) {
	T.n = 0;
}

bool getAncestor(pTree &T, elementType x) {
	int w = 0;
	elementType y=x;

	for (w = 0; w < T.n; w++) {
		if (T.node[w].data == y) {
			w = T.node[w].parent; //取父节点
			y = T.node[w].data;
			cout << y << '\t';
			break;
		}
	}
	if (w >= T.n) {
		return false; //x不在树上
	}

	while (w != -1) {//搜索父节点之外的其它祖先节点
		if (T.node[w].data == y) {
			w = T.node[w].parent;
			y = T.node[w].data;
			cout << y << '\t';
		}
		else {
			w = (w + 1) % T.n;
		}
	}
	return true;
}

//求孩子结点
void getChildren(pTree &T, elementType x) {
	int i, w;
	for (w = 0; w < T.n; w++) {
		if (T.node[w].data == x)
			break;
	}
	if (w >= T.n) { //x不在表中
		return;
	}

	for (i = 0; i < T.n; i++) {
		if (T.node[i].parent == w) {//找到子节点
			cout << T.node[i].data << '\t';
		}
	}
	cout << endl;
}

int firstChild(pTree &T, int v) {
	int w;
	if (v == -1) {
		return -1;
	}

	for (w = 0; w < T.n; w++) {
		if (T.node[w].parent == v) {
			return w;
		}
	}
	return -1;
}

int nextSibling(pTree &T, int v, int w) { //搜索v位于w之后的下一个孩子结点下标
	int i;
	for (i = w + 1; i < T.n; i++) {
		if (T.node[i].parent == v) {
			return i;
		}
	}
	return -1;
}

void preOrder(pTree &T, int v) {
	int w;
	cout << T.node[v].data << "\t";

	w = firstChild(T, v);
	while (w != -1) {
		preOrder(T, w);
		w = nextSibling(T, v, w);
	}
}

void preTraverse(pTree &T) {
	int i;
	int visited[MAXLEN];
	for (i = 0; i < T.n; i++) {
		visited[i] = 0;
	}
	//以根节点出发进行先序遍历
	for (i = 0; i < T.n; i++) {
		if (T.node[i].parent == -1) {
			preOrder(T, i);
		}
	}
}

void postOrder(pTree &T, int v) {
	int w;
	w = firstChild(T, v);
	while (w != -1) {
		postOrder(T, w);
		w = nextSibling(T, v, w);
	}
	cout << T.node[v].data << '\t';
}

void postTraverse(pTree &T) {
	int i;
	int visited[MAXLEN];
	for (i = 0; i < T.n; i++) {
		visited[i] = 0;
	}
	//以根节点出发进行后序遍历
	for (i = 0; i < T.n; i++) {
		if (T.node[i].parent == -1)
			postOrder(T, i);
	}
}

//打印树
void printTree(pTree &T) {
	int i;
	cout << "下标\t结点\t双亲" << endl;
	for (i = 0; i < T.n; i++)
		cout << i << "\t" << T.node[i].data << "\t" << T.node[i].parent << endl;
}
//-------------------------------------------
//开始由双亲表示转换为孩子兄弟链表表示

bool CreateTreeFromFile(char fileName[], pTree &T) {
	FILE* pFile;     //定义顺序表的文件指针
	char str[1000];  //存放读出一行文本的字符串
	int i = 0, j = 0;
	pFile = fopen(fileName, "r");
	if (!pFile) {
		printf("错误：文件%s打开失败。\n", fileName);
		return false;
	}
	
	int nNum = 0;
	//读取结点列表，结点数据存入树的结点数组	
	if (fgets(str, 1000, pFile) != NULL) {
		char* token = strtok(str, " ");
		while (token != NULL) {
			T.node[nNum].data = *token;
			T.node[nNum].parent = -1;       //父结点指针初始化为-1
			token = strtok(NULL, " ");
			nNum++;
		}
	}
	else {
		cout << "文件为空！\n";
		fclose(pFile);
		return false;
	}
	
	//循环读取边（父子队）数据
	int nP;  //父结点数组下标
	int nC;  //子结点数组下标

	elementType Nf, Ns; //父子结点对的两个结点
	while (fgets(str, 1000, pFile) != NULL) {
		char* token = strtok(str, " ");  //以空格为分隔符，分割一行数据，写入邻接矩阵

		if (token == NULL)  //分割为空串，失败退出
		{
			printf("错误：读取树的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Nf = *token;  //获取父结点

		token = strtok(NULL, " ");  //读取下一个子串，即子结点
		if (token == NULL)  //分割为空串，失败退出
		{
			printf("错误：读取树的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Ns = *token;  //获取边的第二个结点（子结点）

		//取得父结点下标		
		for (nP = 0; nP < nNum; nP++) {
			if (T.node[nP].data == Nf)  //从顶点列表找到第一个顶点的编号
				break;
		}
		//获取子结点的数组下标		
		for (nC = 0; nC < nNum; nC++) {
			if (T.node[nC].data == Ns)  //从顶点列表找到第二个顶点的编号
				break;
		}

		T.node[nC].parent = nP;        //nC的父结点的下标为nP
	}

	T.n = nNum;  //树的结点数，即顶点数组的实际大小

	fclose(pFile); //关闭文件
	return true;
}

//搜索双亲表示中，下标w的下一个兄弟结点，返回兄弟结点的下标
int next(pTree &T, int w) {
	int i;
	for (i = w + 1; i < T.n; i++) {
		if (T.node[w].parent == T.node[i].parent)
			return i;
	}
	return -1;
}

void create(node *&T, pTree &T1, int v) {
	int w;
	T = new node;
	T->data = T1.node[v].data;
	T->firstChild = NULL;
	T->nextSibling = NULL;
	w = firstChild(T1, v);
	if (w != -1) {
		create(T->firstChild, T1, w);
	}

	w = next(T1, v);
	if (w != -1) {
		create(T->nextSibling, T1, w);
	}
}

void Tree::createTree() {
	pTree T1;
	char filename[100];
	cout << "输入文件名:";
	cin >> filename;
	cin.get();
	if (CreateTreeFromFile(filename, T1)) {
		cout << "创建成功！" << endl;
	}
	int i;
	for (i = 0; i < T1.n; i++) {
		if (T1.node[i].parent == -1)
			break;
	}
	if (i < T1.n) {
		create(root, T1, i);
	}
}

