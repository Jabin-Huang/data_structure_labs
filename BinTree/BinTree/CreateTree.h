#pragma once
#include<iostream>
using namespace std;

char strLine[100][3];
int nArrlen;

bool ReadFileToArray(char filename[], char strLine[100][3], int &nArrlen) {
	//filenameΪ�򿪵��ļ���
	//strLine�洢�����������Ϣ
	//nArrlenΪ������
	FILE * pf;
	char str[1000];
	pf = fopen(filename, "r");
	if (!pf) {
		cout << "�����������ļ���ʧ�ܣ�\n";
		return false;
	}
	if (fgets(str, 1000, pf) != NULL) {
		if (strcmp(str, "BinaryTree\n") != 0) {
			cout << "�򿪵��ļ���ʽ����!\n";
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
bool BinTree::createTree(node *& root,node * par,char strLine[100][3],int nLen,int &nRow) { //�ݹ鴴��
	//nLenΪ�����(������)
	//nRoww��ǰ�к�
	if (nRow >= nLen || nLen == 0) {
		return false; //������ϻ�������
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