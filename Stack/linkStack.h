#pragma once
 

typedef int elementType;

typedef struct Node {
	elementType data;
	struct Node *next;
}node;

class linkStack {
private:
	node *t;
public:
	void init();
	void push(elementType x);
	bool pop(elementType &x);
	bool top(elementType &x);
	bool empty();
	void convert(int n, int base);
	bool paren(const char exp[]);
};

void linkStack::init() {
	t = NULL;
}

void linkStack::push(elementType x) {
	node *s = new node;
	s->data = x;
	s->next = t;
	t = s;
}

bool linkStack::pop(elementType &x) {
	if (empty()) {
		cout << "栈空！";
		return false;
	}
	else {
		node *u;
		x = t->data;
		u = t;
		t = t->next;
		delete u;
		return true;
	}
}

bool linkStack::top(elementType &x) {
	if (empty()) {
		cout << "栈空！";
		return false;
	}
	else {
		x = t->data;		 
		return true;
	}
}

bool linkStack::empty() {
	return (t==NULL);
}

void linkStack::convert(int n, int base) {
	init();
	static char digit[] = { '0','1','2','3','4','5','6','7','8','9',
						 'A','B','C','D','E','F' };
	while (n > 0) {
		int remainder = n % base;
		push(digit[remainder]);
		n /= base;
	}
	//新进制下由高到低的各数位，自顶而下保存于栈中；
	while (!empty()) {
		elementType x;
		pop(x);
		cout << char(x);
	}
	cout << endl;
}

bool linkStack::paren(const char exp[]) {
	init();
	elementType x;
	for (int i = 0; exp[i]; i++) {
		switch (exp[i]) {
			case '(':case '[':case '{':
				push(exp[i]);
				break;
			case ')':
				if (!pop(x) || '(' != x )
					return false;
				break;
			case ']':
				if (!pop(x) ||  '[' != x)
					return false;
				break;
			case '}':
			 
				if (!pop(x)|| '{' != x)
					return false;
				break;
			default: break;
		}
	}
	return empty();
}