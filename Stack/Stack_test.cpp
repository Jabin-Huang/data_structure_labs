#include"Stack.h"

int main() {
	while (true) {
		system("CLS");
		cout << "===========================================\n";
		cout << "1.利用顺序栈实现将10进制数转换为16进制数。\n\n";
		cout << "2.顺序栈 括号匹配\n\n";
		cout << "3.利用链栈实现将10进制数转换为16进制数。\n\n";
		cout << "4.链栈 括号匹配\n\n";
		cout << "5.判断合法输出序列\n\n";
		cout << "6.输出合法输出序列\n\n";
		//cout << "7.表达式求值\n\n";
		cout << "===========================================\n";
		seqStack S;
		linkStack lS;
		string ans;
		int n;
		char str[100];
		int choose;
		cin >> choose;
		cin.get();
		switch (choose) {
			case 1:
				cout << "输入原数:";
				cin >> n;
				cin.get();
				S.convert(n, 16);
				cin.get();
				break;
			case 2:
				char str[100];
				cin >> str;
				cin.get();
				if (S.paren(str)) {
					cout << "匹配！" << endl;
				}
				else {
					cout << "不匹配！" << endl;
				}
				cin.get();
				break;
			case 3:
				cout << "输入原数:";
				cin >> n;
				cin.get();
				lS.convert(n, 16);
				cin.get();
				break;
			case 4:
				cin >> str;
				cin.get();
				if (lS.paren(str)) {
					cout << "匹配！" << endl;
				}
				else {
					cout << "不匹配！" << endl;
				}
				cin.get();
				break;
			case 5:
				int B[100];
				cout << "输入n：" << endl;
				cin >> n;
				cin.get();
				cout << "输入要判断的输出序列：" << endl;
				for (int i = 0; i < n; i++) {
					cin >> B[i];
				}
				cin.get();
				if (S.stackPermutation(B, n)) {
					cout << "合法！" << endl;
				}
				else {
					cout << "不合法！" << endl;
				}
				cin.get();
				break;
			case 6:
				S.init();
				cout << "输入n：" << endl;
				cin >> n;
				cin.get();
				cout << "所有合法输出序列为：" << endl;
				dfs(false, n, 1, 0, S, ans);
				//cout << "共" << cnt << "个" << endl;
				cin.get();
				break;
			default:
				break;
		}
		
	}
	return 0;
 }
