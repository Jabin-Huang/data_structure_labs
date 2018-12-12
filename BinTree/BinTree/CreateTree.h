#pragma once
#include<iostream>
using namespace std;

char strLine[100][3];
int nArrlen;

bool ReadFileToArray(char filename[], char strLine[100][3], int &nArrlen) {
	//filename为打开的文件名
	//strLine存储二叉树结点信息
	//nArrlen为结点个数
	FILE * pf;
	char str[1000];
	pf = fopen(filename, "r");
	if (!pf) {
		cout << "二叉树数据文件打开失败！\n";
		return false;
	}
	if (fgets(str, 1000, pf) != NULL) {
		if (strcmp(str, "BinaryTree\n") != 0) {
			cout << "打开的文件格式错误!\n";
			fclose(pf);
			return false;
		}
	}
	nArrlen = 0;
	while (fscanf(pf, "%c %c %c\n", &strLine[nArrlen][0], &strLine[nArrlen][1], &strLine[nArrlen][2]) != EOF) {
		nArrlen++;
	}
	fclose(pf);
	return true;
}
bool BinTree::createTree(node *& root,node * par,char strLine[100][3],int nLen,int &nRow) { //递归创建
	//nLen为结点数(总行数)
	//nRoww当前行号
	if (nRow >= nLen || nLen == 0) {
		return false; //处理完毕或无数据
	}

	root = new node;
	root->data = strLine[nRow][0];
	root->lc = NULL;
	root->rc = NULL;
	root->parent = par;
	int nRowNext = nRow;
	if (strLine[nRowNext][1] == '1') {
		nRow++;
		createTree(root->lc, root, strLine, nLen, nRow);
	}
	if (strLine[nRowNext][1] == '1') {
		nRow++;
		createTree(root->rc, root, strLine, nLen, nRow);
	}
	return true;
}