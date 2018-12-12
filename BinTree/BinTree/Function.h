#pragma once

#include<algorithm>

//<1>打印出二叉树的三种遍历序。
void BinTree::PrintInOrder(node *T) {
	if (T) {
		PrintInOrder(T->lc);
		cout << T->data << " ";
		PrintInOrder(T->rc);
	}
}

void BinTree::PrintPreOrder(node *T ) {
	if (T) {
		cout << T->data << " ";
		PrintPreOrder(T->lc);
		PrintPreOrder(T->rc);
	}
}

void BinTree::PrintPostOrder(node *T ) {
	if (T) {
		PrintPostOrder(T->lc);
		PrintPostOrder(T->rc);
		cout << T->data << " ";
	}
}

//<2>设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数。
void BinTree::PrintInOrder_level(node *T, int i) {
	if (T) {
		PrintInOrder_level(T->lc, ++i);
		cout << T->data << "(层次：" << i << ")" << " ";
		PrintInOrder_level(T->rc, ++i);
	}
}
//<3>求二叉树的高度。
int BinTree::height(node *T) {
	if (T == NULL) {
		return 0;
	}
	return max(height(T->lc), height(T->rc)) + 1;
}

//<4>求二叉树的结点数。
int BinTree::numOfnode(node *T) {
	if (T == NULL) {
		return 0;
	}
	return numOfnode(T->lc) + numOfnode(T->rc) + 1;
}

//<5>求二叉树的叶子结点数。
int BinTree::numOflef(node *T) {
	if (T->lc == NULL && T->rc == NULL) {
		return 1;
	}
	return numOflef(T->lc) + numOflef(T->rc);
}

//<6>求二叉树的度为2的结点数。
void BinTree::numOfTwoDegree(node *T,int &i) {
	if (T&&T->lc&&T->rc) {
		i++;
	}
	if (T) {
		numOfTwoDegree(T->lc, i);
		numOfTwoDegree(T->rc, i);
	}
}

//返回元素e的地址
node* BinTree::find(node *T,elementType e) {
	if (T&&T->data == e) {
		return T;
	}
	if (T) {
		return find(T->lc, e);
		return find(T->rc, e);
	}
	return NULL;//未找到元素e
}

//<7>键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，不存在时给出相应提示信息。对兄弟结点和孩子结点，存在时要明确指出是左兄弟、左孩子、右兄弟或右孩子。
void BinTree::nbrinfo(elementType e) {
	node * addr = find(root,e);

	if (addr->parent) {
		cout << "父结点：" << addr->parent->data << "(" << addr->parent << ")" << endl;
	}
	else cout << "父结点不存在。" << endl;

	if (addr->parent) {//父节点不存在则是根节点，根节点不存在兄弟结点
		if (addr->parent->lc == addr) {
			if (addr->parent->rc) {
				cout << "其本身为父结点左孩子,它的右兄弟为" << addr->parent->rc->data << "(" << addr->parent->rc << ")" << endl;
			}
			else {
				cout << "无兄弟结点" << endl;
			}
		}
		else {
			if (addr->parent->lc) {
				cout << "其本身为父结点右孩子,它的左兄弟为" << addr->parent->lc->data << "(" << addr->parent->lc << ")" << endl;
			}else{
				cout << "无兄弟结点" << endl;
			}
		}
	}
	else {
		cout << "无兄弟结点" << endl;
	}
	if (addr->lc) {
		cout << "左孩子为" << addr->lc->data << "("<<addr->rc<<")"<<endl;
	}
	if (addr->rc) {
		cout << "左孩子为" << addr->rc->data << "(" << addr->rc << ")" << endl;
	}

}

//<8>键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息。
bool BinTree::level(node *T,elementType e,int i) {
	if (T&&T->data == e) {
		cout << "其层次为：" << i << endl;
		return true;
	}
	if (T) {
		if(level(T->lc, e, i+1)) return true;
		if(level(T->rc, e, i+1)) return true;
	}
	cout << "未找到该元素" << endl;
	return false; //未找到元素e
}

//<9>将按顺序方式存储在数组中的二叉树转换为二叉链表形式。（数组中要扩展为完全二叉树）。

void BinTree::convertFromArray(node *&T,elementType A[],int i) {
	T= new node;
	T->data = A[i];
	if (A[2 * i] != 0) {
		convertFromArray(T->lc, A, 2 * i );
	}
	if (A[2 * i + 1] != 0) {
		convertFromArray(T->rc, A, 2 * i + 1);
	}
}

//<10>交换二叉树中每个结点的左右孩子指针的值。（即：左子树变为右子树，右子树变为左子树）
void BinTree::swapLR(node *&T) {
	if (T->lc || T->rc) {
		swap(T->lc, T->rc);
		if (T->lc) {
			swapLR(T->lc);
		}
		if (T->rc) {
			swapLR(T->rc);
		}
	}
}
//<11>复制一棵二叉树T到T1。
void BinTree::copyTree(node *T, node *&T1) {
	if (T) {
		T1 = new node;
		T1->data = T->data;
		T1->lc = NULL;
		T1->rc = NULL;
		if(T->lc)
			copyTree(T->lc, T1->lc);
		if(T->rc)
			copyTree(T->rc, T1->rc);
	}
}

void BinTree::printPath(node *T) {

}


