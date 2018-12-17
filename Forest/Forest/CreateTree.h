#pragma once

#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAXLEN 1000
typedef char elementType;

//�ȴ���˫�ױ�ʾ��ɭ�֣����ɴ�ɭ��ת��Ϊ�ֵ�-���������ʾ��

typedef struct pNode {
	elementType data;   //���������
	int parent;         //�����ָ�루�±꣩

}PTNode;

//˫�ױ�ʾ������ɭ�֣��ṹ
typedef struct pTree {
	PTNode node[MAXLEN];   //�������
	int n;              //�������
}pTree;

void init(pTree &T) {
	T.n = 0;
}

bool getAncestor(pTree &T, elementType x) {
	int w = 0;
	elementType y=x;

	for (w = 0; w < T.n; w++) {
		if (T.node[w].data == y) {
			w = T.node[w].parent; //ȡ���ڵ�
			y = T.node[w].data;
			cout << y << '\t';
			break;
		}
	}
	if (w >= T.n) {
		return false; //x��������
	}

	while (w != -1) {//�������ڵ�֮����������Ƚڵ�
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

//���ӽ��
void getChildren(pTree &T, elementType x) {
	int i, w;
	for (w = 0; w < T.n; w++) {
		if (T.node[w].data == x)
			break;
	}
	if (w >= T.n) { //x���ڱ���
		return;
	}

	for (i = 0; i < T.n; i++) {
		if (T.node[i].parent == w) {//�ҵ��ӽڵ�
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

int nextSibling(pTree &T, int v, int w) { //����vλ��w֮�����һ�����ӽ���±�
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
	//�Ը��ڵ���������������
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
	//�Ը��ڵ�������к������
	for (i = 0; i < T.n; i++) {
		if (T.node[i].parent == -1)
			postOrder(T, i);
	}
}

//��ӡ��
void printTree(pTree &T) {
	int i;
	cout << "�±�\t���\t˫��" << endl;
	for (i = 0; i < T.n; i++)
		cout << i << "\t" << T.node[i].data << "\t" << T.node[i].parent << endl;
}
//-------------------------------------------
//��ʼ��˫�ױ�ʾת��Ϊ�����ֵ������ʾ

bool CreateTreeFromFile(char fileName[], pTree &T) {
	FILE* pFile;     //����˳�����ļ�ָ��
	char str[1000];  //��Ŷ���һ���ı����ַ���
	int i = 0, j = 0;
	pFile = fopen(fileName, "r");
	if (!pFile) {
		printf("�����ļ�%s��ʧ�ܡ�\n", fileName);
		return false;
	}
	
	int nNum = 0;
	//��ȡ����б�������ݴ������Ľ������	
	if (fgets(str, 1000, pFile) != NULL) {
		char* token = strtok(str, " ");
		while (token != NULL) {
			T.node[nNum].data = *token;
			T.node[nNum].parent = -1;       //�����ָ���ʼ��Ϊ-1
			token = strtok(NULL, " ");
			nNum++;
		}
	}
	else {
		cout << "�ļ�Ϊ�գ�\n";
		fclose(pFile);
		return false;
	}
	
	//ѭ����ȡ�ߣ����Ӷӣ�����
	int nP;  //����������±�
	int nC;  //�ӽ�������±�

	elementType Nf, Ns; //���ӽ��Ե��������
	while (fgets(str, 1000, pFile) != NULL) {
		char* token = strtok(str, " ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���

		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ���ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Nf = *token;  //��ȡ�����

		token = strtok(NULL, " ");  //��ȡ��һ���Ӵ������ӽ��
		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ���ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Ns = *token;  //��ȡ�ߵĵڶ�����㣨�ӽ�㣩

		//ȡ�ø�����±�		
		for (nP = 0; nP < nNum; nP++) {
			if (T.node[nP].data == Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
		//��ȡ�ӽ��������±�		
		for (nC = 0; nC < nNum; nC++) {
			if (T.node[nC].data == Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}

		T.node[nC].parent = nP;        //nC�ĸ������±�ΪnP
	}

	T.n = nNum;  //���Ľ�����������������ʵ�ʴ�С

	fclose(pFile); //�ر��ļ�
	return true;
}

//����˫�ױ�ʾ�У��±�w����һ���ֵܽ�㣬�����ֵܽ����±�
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
	cout << "�����ļ���:";
	cin >> filename;
	cin.get();
	if (CreateTreeFromFile(filename, T1)) {
		cout << "�����ɹ���" << endl;
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

