#pragma once
#include<queue>
#include<algorithm>

//ɭ�ֵ��������
void Tree::printPre(node *T) {
	if (T) {
		cout << T->data << " ";
		printPre(T->firstChild);
		printPre(T->nextSibling);
	}
}

//ɭ�ֵĺ���������൱�ڶ����������������
void Tree::printPost(node *T) {
	if (T) {
		printPost(T->firstChild);
		cout << T->data << " ";
		printPost(T->nextSibling);
	}
}

//ɭ�ֵĲ�α������������У�
void Tree::printlevel(node *T) {
	queue<node*> q;
	q.push(T);
	node *s = T->nextSibling;
	while (s) {
		q.push(s);
		s = s->nextSibling;
	}
	while (!q.empty()) {
		node *u = q.front();
		q.pop();
		cout << u->data << " ";
		s = u->firstChild;
		while (s) {
			q.push(s);
			s = s->nextSibling;
		}
	}
}

//����������ֵ�����κš�
void Tree::printPre_level(node *T,int i) {
	if (T) {
		printf("(%c,%d)",T->data,i);
		printPre_level(T->firstChild, i+1);
		printPre_level(T->nextSibling,i);
	}
}

//��ɭ�ֵĸ߶�
int Tree::height(node *T) {
	if (T==NULL) {
		return 0;
	}
	return max(height(T->firstChild) + 1, height(T->nextSibling));
}

//��ɭ�ֽ������
int Tree::numOfNode(node *T) {
	if (T == NULL) {
		return 0;
	}
	else {
		return numOfNode(T->firstChild) + numOfNode(T->nextSibling)+1;
	}
}

//��ɭ��Ҷ�ӽ����
int Tree::numOflef(node *T) {
	if (T == NULL) {
		return 0;
	}

	if (T&&T->firstChild == NULL) {//��TΪҶ���ʱ����Ҫ�ݹ鿼�����ֵܽ��
		return 1+numOflef(T->nextSibling);
	}

	if (T) {
		return numOflef(T->firstChild) + numOflef(T->nextSibling);
	}
}

//��ɭ�ֵĶ�
void Tree::numOfDegree(node *T,int i,int &ans) {
	if (T) {
		ans = max(ans, i);
		numOfDegree(T->firstChild, 1, ans);
		numOfDegree(T->nextSibling, i + 1, ans);
	}
}

//���������ʾ����
void Tree::printList(node *T, int k) {
	if (T) {
		if (k == 1) { //��TΪfirstChildʱ
			cout << '(' << T->data;
		}
		if (k == 2) {//��TΪnextSiblingʱ
			cout << ',' << T->data;
		}
		if (k == 0) {
			cout << T->data;
		}
		printList(T->firstChild, 1);
		cout << ')'; //firstChild������������ʱ
		printList(T->nextSibling, 2);
	}
}