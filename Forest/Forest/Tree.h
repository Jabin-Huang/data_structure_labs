#pragma once

typedef char elementType;

typedef struct Node {
	elementType data;
	struct Node *nextSibling, *firstChild;
}node;

class Tree {
private:
	node *root;
public:
	void createTree();
	node*& treeRoot() { return root; }
	void printPre(node *T);
	void printPost(node *T);
	void printlevel(node *T);
	int height(node *T);
	int numOfNode(node *T);
	int numOflef(node *T);
	void numOfDegree(node *T,int i,int &ans);
	void printPre_level(node *T,int i);
	void printList(node *T,int k);
};

#include"CreateTree.h"
#include"Function.h"