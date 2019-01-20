#include<iostream>
#include"Graph.h"
#include<cstdlib>

using namespace std;

Graph G;

void test0() {
	char filename[100];
	cout << "输入文件名:";
	cin >> filename;
	cin.get();
	if (CreateGrpFromFile(filename, G)) {
		cout << "创建成功！" << endl;
	}
	cin.get();
	cin.get();
}

void test1() {
	cout << "DFS遍历序：";
	DFSTraverse(G);
	printf("\n");
	cout << "BFS遍历序：";
	BFSTraverse(G);
	printf("\n");
	cin.get();
	cin.get();
}

void test2() {
	cout << "边数：" << G.ArcNum << endl;
	cin.get();
	cin.get();
}

void test3() {
	int v;
	cout << "输入起点编号：";
	cin >> v;
	cin.get();
	cout << "生成树:";
	DFSTraverse_path(G, v);
	cin.get();
	cin.get();

}

void test4() {
	int v;
	cout << "输入起点编号：";
	cin >> v;
	cin.get();
	cout << "生成树:";
	BFSTraverse_path(G, v);
	cin.get();
	cin.get();
}

void test5() {
	int v;
	cout << "输入开始Prim的起点：";
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
	cout << "输入起点编号：";
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
		printf("拓扑序列：");
		for (int i = 1; i<=G.VerNum; i++) {
			printf("%c---", G.Data[topoList[i]]);
		}
		printf("end\n");
	}
	else printf("不存在拓扑序列！\n");
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
		cout << "0.创建图(网)" << "\n\n";
		cout << "1.打印出图（网）的两种遍历序" << "\n\n";
		cout << "2.求给定图中的边（或弧）的数目" << "\n\n";
		cout << "3.对给定的图G及出发点v0，从V0出发深度优先遍历图G，并构造出相应的生成树或生成森林" << "\n\n";
		cout << "4.对给定的图G及出发点v0,从V0出发广度优先遍历图G，并构造出相应的生成树或生成森林 " << "\n\n";
		cout << "5.Prim算法求给定图G的最小生成树" << "\n\n";
		cout << "6.Kruska算法求给定图G的最小生成树" << "\n\n";
		cout << "7.Dijkstra算法求给定图G指定顶点到其余顶点之间的最短路径" << "\n\n";
		cout << "8.Floyd算法求给定图G各顶点之间的最短路径。" << "\n\n";
		cout << "9.求给定图G的拓扑序列" << "\n\n";
		cout << "10.求给定AOE网的关键路径" << "\n\n";
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