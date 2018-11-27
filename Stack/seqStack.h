#pragma once

 
#define MAXLEN 10000
typedef int elementType;

class seqStack {
private:
	elementType data[MAXLEN];
	int t;

public:
	void init();
	bool empty();
	bool top(elementType &x);
	bool full();
	bool push(elementType x);
	bool pop(elementType &x);
	void convert(int n, int base);
	bool paren(const char exp[]);
	bool stackPermutation(const int B[], int n);
	
};

void seqStack::init() {
	t = -1;
}
bool seqStack::empty() {
	return (t == -1);
}

bool seqStack::top(elementType &x) {
	if (empty())
		return false;
	else {
		x = data[t];
		return true;
	}
}

bool seqStack::full() {
	return (t == MAXLEN - 1);
}

bool seqStack::push(elementType x) {
	if (full()) {
		return false;
	}
	else {
		data[++t] = x;
		return true;
	}
}

bool seqStack::pop(elementType &x) {
	if (empty()) {
		return false;
	}
	else {
		x = data[t--];
		return true;
	}
}

void seqStack::convert(int n,int base) {
	init();
	static char digit[] = { '0','1','2','3','4','5','6','7','8','9',
						 'A','B','C','D','E','F' };
	while (n > 0) {
		int remainder = n%base;
		push(digit[remainder]); 
		n /= base;
	}
	//�½������ɸߵ��͵ĸ���λ���Զ����±�����ջ�У�
	cout << "�½����µ�����";
	while (!empty()) {
		elementType x;
		pop(x);
		cout <<char(x);
	}
	cout << endl;
}

bool seqStack::paren(const char exp[]) {
	init();
	elementType x;
	for (int i = 0; exp[i]; i++) {
		switch (exp[i]) {
			case '(':case '[':case '{':
				push(exp[i]);
				break;
			case ')':
				if (!pop(x) || '(' != x)
					return false;
				break;
			case ']':
				if (!pop(x) || '[' != x)
					return false;
				break;
			case '}':

				if (!pop(x) || '{' != x)
					return false;
				break;
			default: break;
		}
	}
	return empty();
}

bool seqStack::stackPermutation(const int B[],int n) {
	init();
	int i = 1;
	for (int k = 0; k < n; k++) {
		elementType x;
		while (!top(x)||B[k]!=x) {//ջ�ջ�ջ��Ԫ�ز����ڵ�ǰ�������Ԫ��
			if (i <= n) {
				push(i++);
			}
			else {
				return false;
			}
			
		}
		pop(x);
	}
	return true;
}

void dfs(bool sign,int n, int k, int i, seqStack S, string ans) {
	//nΪ���г��ȣ�kΪ��ǰ�������е�Ԫ��,iΪ��ǰ�Ѿ���ջ�����г���
	if (sign==true) { //��ջ
		elementType x;
		S.pop(x);
		ans += char( x+'0');
	}
	if (sign==false) {//��ջ
		S.push(k);
	}
	if (i == n) { //��ջ�������
		cout << ans << endl;
	}
	if (k+1 <= n) { //��֦���ⱬջ
		dfs(false, n, k + 1, i, S, ans);
	}
	if (i + 1 <= n&&!S.empty()) {
		dfs(true, n, k, i + 1, S, ans);
	}
}