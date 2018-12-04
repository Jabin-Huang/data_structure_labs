#pragma once

class VST {
public:
	void operator()(node *T) {
		cout <<T->data<<' ';
	}
};

void output(node *T) {
	cout << T->data;
}

void (*visit)(node *T)=NULL;
visit = &output;

void BinTree::inOrderTrav(node *T,void (*visit)(node *T)) {
	if (T) {
		inOrderTrav(T->lc,visit);  
		visit(T);
		inOrderTrav(T->rc,visit);
	}
}

void BinTree::preOrderTrav(node *T, void(*visit)(node *T)) {
	if (T) {
		visit(T);
		preOrderTrav(T->lc,visit);
		
		preOrderTrav(T->rc,visit);
	}
}

void BinTree::postOrderTrav(node *T, void(*visit)(node *T)) {
	if (T) {
		postOrderTrav(T->lc,visit);
		postOrderTrav(T->rc,visit);
		visit(T);
	}
}