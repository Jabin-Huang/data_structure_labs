#pragma once

typedef char elementType;
typedef struct Node {
	elementType data;
	struct Node *lc, *rc,*parent;
}node;
 
class BinTree {
private:
	node *root;
public:
	bool createTree(node *& root, char strLine[100][3], int nLen, int &nRow);
	void preOrderTrav(node *T,void (*visit)(node *T));
	void inOrderTrav(node *T, void(*visit) (node *T));
	void postOrderTrav(node *T, void(*visit) (node *T));
	bool empty();
	node *TreeRoot() { return root; }

};

#include"CreateTree.h"
#include"Traverse.h"