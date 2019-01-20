#pragma once

#include<queue>

void BFS(Graph &G, int v) { //从编号为v的顶点出发广度遍历一个连通分量
	int w;//邻接点
	queue<elementType> Q;
	visit(G, v); //访问v
	visited[v] = true;//访问v完毕，设置访问标志
	Q.push(v);//v入队
	while (!Q.empty()) {
		v = Q.front(); //将v出队，开始访问其邻接点
		Q.pop();
		w = firstAdj(G, v); // 求v的第一个邻接点
		while (w != 0) {
			if (!visited[w]) {//w还未访问,则将其访问，并入队
				visit(G,w); //访问w
				visited[w] = true; //访问w完毕，设置访问标志
				Q.push(w); //将w入队
			}
			w = nextAdj(G, v,w);// 求下一个领结点
		}
	}
}

void BFSTraverse(Graph &G) {
	for (int i = 1; i <= G.VerNum; i++) {
		visited[i] = false; //初始化访问标志
	}
	for (int i = 1; i <= G.VerNum; i++) { 
		if (!visited[i]) {
			BFS(G, i); //每调用一次，访问一个连通分支
		}
	}
	printf("结束");
}


void BFS_path(Graph &G, int v) { //从编号为v的顶点出发广度遍历一个连通分量
	int w;//邻接点
	queue<elementType> Q;
	visit_path(G, v); //访问v
	visited[v] = true;
	Q.push(v);//v入队
	while (!Q.empty()) {
		v = Q.front(); //将v出队，开始访问其邻接点
		Q.pop();
		w = firstAdj(G, v); // 求v的第一个邻接点
		while (w != 0) {
			if (!visited[w]) {//w还未访问,则将其访问，并入队
				visit_path(G, w); //访问w
				visited[w] = true; //访问w完毕，设置访问标志
				Q.push(w); //将w入队
			}
			w = nextAdj(G, v, w);// 求下一个领结点
		}
	}
	printf("结束\n");
}

void BFSTraverse_path(Graph &G,int v) {
	for (int i = 1; i <= G.VerNum; i++) {
		visited[i] = false; //初始化访问标志
	}
	for (int i = 0; i <= G.VerNum; i++) {
		if (!visited[i]) {
			if (i == 0) {
				BFS_path(G, v); //v为起点
			}
			else {
				BFS_path(G, i); //每调用一次，访问一个连通分支
			}
		}
	}
}

