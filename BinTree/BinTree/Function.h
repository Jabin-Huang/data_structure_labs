#pragma once

#include<algorithm>

//<1>��ӡ�������������ֱ�����
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

//<2>����㷨�������������������и�����ֵ��������Ӧ�Ĳ������
void BinTree::PrintInOrder_level(node *T, int i) {
	if (T) {
		PrintInOrder_level(T->lc, ++i);
		cout << T->data << "(��Σ�" << i << ")" << " ";
		PrintInOrder_level(T->rc, ++i);
	}
}
//<3>��������ĸ߶ȡ�
int BinTree::height(node *T) {
	if (T == NULL) {
		return 0;
	}
	return max(height(T->lc), height(T->rc)) + 1;
}

//<4>��������Ľ������
int BinTree::numOfnode(node *T) {
	if (T == NULL) {
		return 0;
	}
	return numOfnode(T->lc) + numOfnode(T->rc) + 1;
}

//<5>���������Ҷ�ӽ������
int BinTree::numOflef(node *T) {
	if (T->lc == NULL && T->rc == NULL) {
		return 1;
	}
	return numOflef(T->lc) + numOflef(T->rc);
}

//<6>��������Ķ�Ϊ2�Ľ������
void BinTree::numOfTwoDegree(node *T,int &i) {
	if (T&&T->lc&&T->rc) {
		i++;
	}
	if (T) {
		numOfTwoDegree(T->lc, i);
		numOfTwoDegree(T->rc, i);
	}
}

//����Ԫ��e�ĵ�ַ
node* BinTree::find(node *T,elementType e) {
	if (T&&T->data == e) {
		return T;
	}
	if (T) {
		return find(T->lc, e);
		return find(T->rc, e);
	}
	return NULL;//δ�ҵ�Ԫ��e
}

//<7>��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��������ʱ������Ӧ��ʾ��Ϣ�����ֵܽ��ͺ��ӽ�㣬����ʱҪ��ȷָ�������ֵܡ����ӡ����ֵܻ��Һ��ӡ�
void BinTree::nbrinfo(elementType e) {
	node * addr = find(root,e);

	if (addr->parent) {
		cout << "����㣺" << addr->parent->data << "(" << addr->parent << ")" << endl;
	}
	else cout << "����㲻���ڡ�" << endl;

	if (addr->parent) {//���ڵ㲻�������Ǹ��ڵ㣬���ڵ㲻�����ֵܽ��
		if (addr->parent->lc == addr) {
			if (addr->parent->rc) {
				cout << "�䱾��Ϊ���������,�������ֵ�Ϊ" << addr->parent->rc->data << "(" << addr->parent->rc << ")" << endl;
			}
			else {
				cout << "���ֵܽ��" << endl;
			}
		}
		else {
			if (addr->parent->lc) {
				cout << "�䱾��Ϊ������Һ���,�������ֵ�Ϊ" << addr->parent->lc->data << "(" << addr->parent->lc << ")" << endl;
			}else{
				cout << "���ֵܽ��" << endl;
			}
		}
	}
	else {
		cout << "���ֵܽ��" << endl;
	}
	if (addr->lc) {
		cout << "����Ϊ" << addr->lc->data << "("<<addr->rc<<")"<<endl;
	}
	if (addr->rc) {
		cout << "����Ϊ" << addr->rc->data << "(" << addr->rc << ")" << endl;
	}

}

//<8>��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ��
bool BinTree::level(node *T,elementType e,int i) {
	if (T&&T->data == e) {
		cout << "����Ϊ��" << i << endl;
		return true;
	}
	if (T) {
		if(level(T->lc, e, i+1)) return true;
		if(level(T->rc, e, i+1)) return true;
	}
	cout << "δ�ҵ���Ԫ��" << endl;
	return false; //δ�ҵ�Ԫ��e
}

//<9>����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ����������Ҫ��չΪ��ȫ����������

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

//<10>������������ÿ���������Һ���ָ���ֵ����������������Ϊ����������������Ϊ��������
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
//<11>����һ�ö�����T��T1��
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


