#include<iostream>
#include"Graph.h"
#include<cstdlib>

using namespace std;

Graph G;

void test0() {
	char filename[100];
	cout << "�����ļ���:";
	cin >> filename;
	cin.get();
	if (CreateGrpFromFile(filename, G)) {
		cout << "�����ɹ���" << endl;
	}
	cin.get();
	cin.get();
}

void test1() {
	cout << "DFS������";
	DFSTraverse(G);
	printf("\n");
	cout << "BFS������";
	BFSTraverse(G);
	printf("\n");
	cin.get();
	cin.get();
}

void test2() {
	cout << "������" << G.ArcNum << endl;
	cin.get();
	cin.get();
}

void test3() {
	int v;
	cout << "��������ţ�";
	cin >> v;
	cin.get();
	cout << "������:";
	DFSTraverse_path(G, v);
	cin.get();
	cin.get();

}

void test4() {
	int v;
	cout << "��������ţ�";
	cin >> v;
	cin.get();
	cout << "������:";
	BFSTraverse_path(G, v);
	cin.get();
	cin.get();
}

void test5() {
	int v;
	cout << "���뿪ʼPrim����㣺";
	cin >> v;
	Prim(G, v);
	cin.get();
	cin.get();
}
void test6() {
	Kruskal(G);
	cin.get();
	cin.get();
}

void test7() {
	int vID;
	cout << "��������ţ�";
	cin >> vID;
	int path[MaxVerNum+1];
	int dist[MaxVerNum + 1];
	memset(path, 0, sizeof(path));
	memset(dist, 0, sizeof(dist));
	Dijkstra(G, path, dist, vID);
	cin.get();
	cin.get();
}

void test8() {
	int path[MaxVerNum + 1][MaxVerNum + 1];
	int dist[MaxVerNum + 1][MaxVerNum + 1];
	memset(path, 0, sizeof(path));
	memset(dist, 0, sizeof(dist));
	Floyed(G, dist, path);
	cin.get();
	cin.get();
}

void test9() {
	int topoList[MaxVerNum + 1];
	if (TopologicalSort(G, topoList)) {
		printf("�������У�");
		for (int i = 1; i<=G.VerNum; i++) {
			printf("%c---", G.Data[topoList[i]]);
		}
		printf("end\n");
	}
	else printf("�������������У�\n");
	cin.get();
	cin.get();
}

void test10() {
	int topoList[MaxVerNum + 1];
	TopologicalSort(G, topoList);
	KeyPath(G, topoList);
	cin.get();
	cin.get();
}

int main() {
	int choose;
	while (true) {
		system("CLS");
		cout << "0.����ͼ(��)" << "\n\n";
		cout << "1.��ӡ��ͼ�����������ֱ�����" << "\n\n";
		cout << "2.�����ͼ�еıߣ��򻡣�����Ŀ" << "\n\n";
		cout << "3.�Ը�����ͼG��������v0����V0����������ȱ���ͼG�����������Ӧ��������������ɭ��" << "\n\n";
		cout << "4.�Ը�����ͼG��������v0,��V0����������ȱ���ͼG�����������Ӧ��������������ɭ�� " << "\n\n";
		cout << "5.Prim�㷨�����ͼG����С������" << "\n\n";
		cout << "6.Kruska�㷨�����ͼG����С������" << "\n\n";
		cout << "7.Dijkstra�㷨�����ͼGָ�����㵽���ඥ��֮������·��" << "\n\n";
		cout << "8.Floyd�㷨�����ͼG������֮������·����" << "\n\n";
		cout << "9.�����ͼG����������" << "\n\n";
		cout << "10.�����AOE���Ĺؼ�·��" << "\n\n";
		cin >> choose;
		cin.get();
		switch (choose) {
		case 0:test0(); break;
		case 1:test1(); break;
		case 2:test2(); break;
		case 3:test3(); break;
		case 4:test4(); break;
		case 5:test5(); break;
		case 6:test6(); break;
		case 7:test7(); break;
		case 8:test8(); break;
		case 9:test9(); break;
		case 10:test10(); break;
		default:
			break;
		}
	}
	return 0;
}