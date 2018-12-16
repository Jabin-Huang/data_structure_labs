#pragma once



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
		cout << T->data << "(层次：" << i << ")" << endl;
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
	if (T) {
		if (T->lc == NULL && T->rc == NULL) {
			return 1;//当前结点无孩子，则是叶子结点，返回1
		}
		return numOflef(T->lc) + numOflef(T->rc);
	}
	return 0;//当前结点只有左孩子或右孩子时，不存在的左孩子或右孩子应该返回0
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
	if (T) {//找到便逐层返回
		node* t;
		if(t=find(T->lc, e)) return t;
		if(t=find(T->rc, e)) return t;
	}
	return NULL;//未找到元素e
}

//<7>键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，不存在时给出相应提示信息。对兄弟结点和孩子结点，存在时要明确指出是左兄弟、左孩子、右兄弟或右孩子。
void BinTree::nbrinfo(elementType e) {
	node * addr = NULL;
	if (! (addr = find(root, e))) {
		cout << "不存在该节点" << endl;
		return;
	}

	if (addr->parent) {
		cout << "父结点：" << addr->parent->data << "(" << addr->parent << ")" << endl;
	}
	else cout << "父结点不存在。" << endl;

	if (addr->parent) {//父节点不存在则是根节点，根节点不存在兄弟结点
		if (addr->parent->lc == addr) {
			if (addr->parent->rc) {
				cout << "其本身为父结点左孩子,它的右兄弟为" << addr->parent->rc->data << " (" << addr->parent->rc << ")" << endl;
			}
			else {
				cout << "无兄弟结点" << endl;
			}
		}
		else {
			if (addr->parent->lc) {
				cout << "其本身为父结点右孩子,它的左兄弟为" << addr->parent->lc->data << " (" << addr->parent->lc << ")" << endl;
			}else{
				cout << "无兄弟结点" << endl;
			}
		}
	}
	else {
		cout << "无兄弟结点" << endl;
	}

	if (addr->lc) {
		cout << "左孩子为" << addr->lc->data << " ("<<addr->rc<<")"<<endl;
	}
	else {
		cout << "无左孩子" << endl;
	}
	
	if (addr->rc) {
		cout << "左孩子为" << addr->rc->data << " (" << addr->rc << ")" << endl;
	}
	else {
		cout << "无右孩子" << endl;
	}
}

//<8>键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息。
bool BinTree::level(node *T,elementType e,int i) {
	if (T&&T->data == e) {
		cout << "其层次为：" << i << endl;
		cin.get();
		return true;
	}
	if (T) {
		if(level(T->lc, e, i+1)) return true;
		if(level(T->rc, e, i+1)) return true;
	}
	return false; //未找到元素e
}

//<9>将按顺序方式存储在数组中的二叉树转换为二叉链表形式。（数组中要扩展为完全二叉树）。

void BinTree::convertFromArray(node *&T,elementType A[],int i) {
	T= new node;
	T->data = A[i];
	T->lc = NULL;
	T->rc = NULL;
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
	if (T) {
		if (!T->lc && !T->rc) {
			node *lef = T;
			while (lef != root) {
				cout << lef->data << "-->";
				lef = lef->parent;
			}
			cout << root->data << endl;
		}
		printPath(T->lc);
		printPath(T->rc);
	}
}

void BinTree::printInLevel(node *T) {
	queue<node*> q;
	q.push(T);
	while (!q.empty()) {
		T = q.front();
		cout << T->data <<' ' ;
		q.pop();
		if(T->lc) q.push(T->lc);
		if(T->rc) q.push(T->rc);
	}
	cout << endl;
}

node* BinTree::LCA(node *a, node *b) {
	node *t1=a, *t2=b;
	while (t1 != root && t2 != root) {
		t1 = t1->parent;
		t2 = t2->parent;
	}
	int step = 0;
	char choose='a';
	
	//求出两结点层次的差距
	while (t1 != root) {
		choose = 'a';
		step++;
		t1 = t1->parent;
	}
	while (t2 != root) {
		choose = 'b';
		step++;
		t2 = t2->parent;
	}
	//指针从更深层结点往上遍历父结点，使两指针所指在同一层次
	switch (choose) {
		case 'a': while (step--) a = a->parent; break;
		case 'b': while (step--) b = b->parent; break;
	default:
		break;
	}//此时两结点层次相同
	//再同步往上找公共祖先
	while (a != b) {
		a = a->parent;
		b = b->parent;
	}
	return a;
}

//<15>求二叉树中一条最长的路径长度（边数），并输出路径上的个结点值。
void BinTree::findLongest(node *T,int step,int &maxx,elementType path[]) {
	if (T) {
		if (!T->lc && !T->rc) {
			node *a = T; //临时变量，防止当前递归的T被改变。
			if (maxx < step) {
				maxx = step;
				int i = 0;
				while (a != root) {
					path[i++] = a->data;
					a=a->parent;
				}
				path[i] = root->data;
			}
		}
		findLongest(T->lc,step+1,maxx,path);
		findLongest(T->rc,step+1,maxx,path);
	}
}




