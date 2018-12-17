#pragma once
#include<queue>
#include<algorithm>

//森林的先序遍历
void Tree::printPre(node *T) {
	if (T) {
		cout << T->data << " ";
		printPre(T->firstChild);
		printPre(T->nextSibling);
	}
}

//森林的后序遍历（相当于二叉树的中序遍历）
void Tree::printPost(node *T) {
	if (T) {
		printPost(T->firstChild);
		cout << T->data << " ";
		printPost(T->nextSibling);
	}
}

//森林的层次遍历（借助队列）
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

//先序输出结点值及其层次号。
void Tree::printPre_level(node *T,int i) {
	if (T) {
		printf("(%c,%d)",T->data,i);
		printPre_level(T->firstChild, i+1);
		printPre_level(T->nextSibling,i);
	}
}

//求森林的高度
int Tree::height(node *T) {
	if (T==NULL) {
		return 0;
	}
	return max(height(T->firstChild) + 1, height(T->nextSibling));
}

//求森林结点总数
int Tree::numOfNode(node *T) {
	if (T == NULL) {
		return 0;
	}
	else {
		return numOfNode(T->firstChild) + numOfNode(T->nextSibling)+1;
	}
}

//求森林叶子结点数
int Tree::numOflef(node *T) {
	if (T == NULL) {
		return 0;
	}

	if (T&&T->firstChild == NULL) {//当T为叶结点时，还要递归考虑其兄弟结点
		return 1+numOflef(T->nextSibling);
	}

	if (T) {
		return numOflef(T->firstChild) + numOflef(T->nextSibling);
	}
}

//求森林的度
void Tree::numOfDegree(node *T,int i,int &ans) {
	if (T) {
		ans = max(ans, i);
		numOfDegree(T->firstChild, 1, ans);
		numOfDegree(T->nextSibling, i + 1, ans);
	}
}

//输出广义表表示的树
void Tree::printList(node *T, int k) {
	if (T) {
		if (k == 1) { //当T为firstChild时
			cout << '(' << T->data;
		}
		if (k == 2) {//当T为nextSibling时
			cout << ',' << T->data;
		}
		if (k == 0) {
			cout << T->data;
		}
		printList(T->firstChild, 1);
		cout << ')'; //firstChild的子树输出完成时
		printList(T->nextSibling, 2);
	}
}