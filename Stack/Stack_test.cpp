#include"Stack.h"

int main() {
	while (true) {
		system("CLS");
		cout << "===========================================\n";
		cout << "1.����˳��ջʵ�ֽ�10������ת��Ϊ16��������\n\n";
		cout << "2.˳��ջ ����ƥ��\n\n";
		cout << "3.������ջʵ�ֽ�10������ת��Ϊ16��������\n\n";
		cout << "3.��ջ ����ƥ��\n\n";
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
					cout << "ƥ�䣡" << endl;
				}
				else {
					cout << "��ƥ�䣡" << endl;
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
					cout << "ƥ�䣡" << endl;
				}
				else {
					cout << "��ƥ�䣡" << endl;
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
