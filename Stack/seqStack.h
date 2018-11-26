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
	//新进制下由高到低的各数位，自顶而下保存于栈中；
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

