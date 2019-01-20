#pragma once

#include<stack>

void GetInDegree(Graph &G, int inds[]) {
	for (int i = 1; i <= G.VerNum; i++) {
		for (int j = 1; j <= G.VerNum; j++) {
			if (i != j && G.AdjMatrix[j][i] > 0 && G.AdjMatrix[j][i] < INF) {
				inds[i]++;
			}
		}
	}
}

int TopologicalSort(Graph &G,int topoList[]) {
	int inds[MaxVerNum + 1]; //入度数组
	stack<int> S; //保存入度为0的顶点
	int v;//顶点编号，从1开始
	int vCount = 0;//入度为0的顶点数
	for (int i = 1; i <= G.VerNum; i++) { //初始化入度数组
		inds[i] = 0;
	}
	for (int i = 1; i <= G.VerNum; i++) { //初始化拓扑序列数组
		topoList[i] = -1;
	}
	GetInDegree(G, inds); //获取各个顶点的初始入度
	for (int i = 1; i <= G.VerNum; i++) {//入度为0的顶点入栈
		if (inds[i] == 0) {
			S.push(i);
		}
	}

	while (!S.empty()) {
		v=S.top();//从栈顶弹出一个入度为0的顶点编号
		S.pop();
		topoList[++vCount] = v; //加入拓扑序列
		for (int i = 1; i <= G.VerNum; i++) {
			if (G.AdjMatrix[v][i] >= 1 && G.AdjMatrix[v][i] < INF&&inds[i]>0) {
				inds[i]--; //与 v邻接的顶点i入度-1
				if (inds[i] == 0) {//入度已为0，入栈
					S.push(i);
				}

			}
		}
	}
	if (vCount == G.VerNum) //无回路
		return 1;
	else
		return 0; //有回路，不能产生拓扑序列
}