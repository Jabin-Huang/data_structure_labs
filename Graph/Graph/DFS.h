#pragma once

void DFS(Graph &G, int v) { //以编号v的顶点为起点进行深度搜索，可遍历一个连通分量
	int w; //领接点
	visit(G, v); //访问点v
	visited[v] = true; //访问完毕，设置访问标志
	w = firstAdj(G, v); //求第一个领接点
	while (w != 0) { //当还存在邻接点
		if (visited[w] == false) { //从未访问过的邻接点出发继续进行深度遍历
			DFS(G, w); 
		}
		w = nextAdj(G, v, w); //求位于w之后的下一个领接点
	}
}

void DFSTraverse(Graph &G) {
	for (int i = 1; i <= G.VerNum; i++) {
		visited[i] = false; //初始化访问标志
	}
	for (int i = 1; i <= G.VerNum; i++) {
		if (visited[i] == false) { //从还未访问的顶点出发进行深度遍历
			DFS(G, i); //如此每循环一次，就遍历了一个连通分量
		}
	}
	printf("结束");
	//算法完成，完成对全图的遍历
}

void DFS_path(Graph &G, int v) { //以编号v的顶点为起点进行深度搜索，可遍历一个连通分量
	int w; //领接点
	visit_path(G, v); //访问点v
	visited[v] = true; //访问完毕，设置访问标志
	w = firstAdj(G, v); //求第一个领接点
	while (w != 0) { //当还存在邻接点
		if (visited[w] == false) { //从未访问过的邻接点出发继续进行深度遍历
			DFS_path(G, w);
		}
		w = nextAdj(G, v, w); //求位于w之后的下一个领接点
	}
}

void DFSTraverse_path(Graph &G,int v) {
	for (int i = 1; i <= G.VerNum; i++) {
		visited[i] = false; //初始化访问标志
	}
	for (int i = 0; i <= G.VerNum; i++) {
		if (visited[i] == false) { //从还未访问的顶点出发进行深度遍历
			if (i == 0) {
				DFS_path(G, v); //起点开始
				printf("结束\n");
			}
			else {
				DFS_path(G, i); //如此每循环一次，就遍历了一个连通分量
				printf("结束\n");
			}
		}
	}
	//算法完成，完成对全图的遍历
}
