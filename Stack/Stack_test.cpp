#include"Stack.h"

int main() {
	while (true) {
		system("CLS");
		cout << "===========================================\n";
		cout << "1.����˳��ջʵ�ֽ�10������ת��Ϊ16��������\n\n";
		cout << "2.˳��ջ ����ƥ��\n\n";
		cout << "3.������ջʵ�ֽ�10������ת��Ϊ16��������\n\n";
		cout << "4.��ջ ����ƥ��\n\n";
		cout << "5.�жϺϷ��������\n\n";
		cout << "6.����Ϸ��������\n\n";
		//cout << "7.���ʽ��ֵ\n\n";
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
				cout << "����ԭ��:";
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
					cout << "ƥ�䣡" << endl;
				}
				else {
					cout << "��ƥ�䣡" << endl;
				}
				cin.get();
				break;
			case 3:
				cout << "����ԭ��:";
				cin >> n;
				cin.get();
				lS.convert(n, 16);
				cin.get();
				break;
			case 4:
				cin >> str;
				cin.get();
				if (lS.paren(str)) {
					cout << "ƥ�䣡" << endl;
				}
				else {
					cout << "��ƥ�䣡" << endl;
				}
				cin.get();
				break;
			case 5:
				int B[100];
				cout << "����n��" << endl;
				cin >> n;
				cin.get();
				cout << "����Ҫ�жϵ�������У�" << endl;
				for (int i = 0; i < n; i++) {
					cin >> B[i];
				}
				cin.get();
				if (S.stackPermutation(B, n)) {
					cout << "�Ϸ���" << endl;
				}
				else {
					cout << "���Ϸ���" << endl;
				}
				cin.get();
				break;
			case 6:
				S.init();
				cout << "����n��" << endl;
				cin >> n;
				cin.get();
				cout << "���кϷ��������Ϊ��" << endl;
				dfs(false, n, 1, 0, S, ans);
				//cout << "��" << cnt << "��" << endl;
				cin.get();
				break;
			default:
				break;
		}
		
	}
	return 0;
 }
