#include"Stack.h"

int main() {
	while (true) {
		system("CLS");
		cout << "===========================================\n";
		cout << "1.利用顺序栈实现将10进制数转换为16进制数。\n\n";
		cout << "2.顺序栈 括号匹配\n\n";
		cout << "3.利用链栈实现将10进制数转换为16进制数。\n\n";
		cout << "3.链栈 括号匹配\n\n";
		cout << "===========================================\n";
		seqStack S;
		linkStack lS;
		int n;
		char s[100];
		int choose;
		cin >> choose;
		cin.get();
		switch (choose) {
			case 1:
				cin >> n;
				S.convert(n, 16);
				cin.get();
				cin.get();
				break;
			case 2:
				char s[100];
				cin >> s;
				if (S.paren(s)) {
					cout << "匹配！" << endl;
				}
				else {
					cout << "不匹配！" << endl;
				}
				cin.get();
				cin.get();
				break;
			case 3:
				cin >> n;
				lS.convert(n, 16);
				cin.get();
				cin.get();
				break;
			case 4:
				cin >> s;
				if (lS.paren(s)) {
					cout << "匹配！" << endl;
				}
				else {
					cout << "不匹配！" << endl;
				}
				cin.get();
				cin.get();
				break;
			default:
				break;
		}
		
	}
	

	return 0;
 }
