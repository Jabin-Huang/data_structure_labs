#pragma once

typedef struct edgetype {
	int vBegin;
	int vEnd;
	cellType eWeight;
}EdgeType;


//辅助函数如下：
void GetEdges(Graph &G, EdgeType edges[]) { //读取边到边数组 （邻接矩阵）
	int k = 1;// 边数组下标
	for (int i = 1; i <= G.VerNum; i++) {
		for (int j = 1; j <= G.VerNum; j++) {
			if (G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] != INF) {
				edges[k].vBegin = i;
				edges[k].vEnd = j;
				edges[k].eWeight = G.AdjMatrix[i][j];
				k++;
			}
		}
	}
}

EdgeType GetMinEdge(Graph &G, EdgeType edges[], bool edgeUsed[], int &n) {
	//返回权值最小的边，n为最小边在edges[]中的下标
	EdgeType minEdge;
	cellType wMin = INF;//保存最小权值
	int M; //控制循环次数
	if (G.gKind == UDG || G.gKind == UDN) //无向图（网）
		M = G.ArcNum * 2;
	else
		M = G.ArcNum;// 有向图（网）
	for (int i = 1; i <= M; i++) {
		if (!edgeUsed[i] && edges[i].eWeight < wMin) {
			//对未使用，且权值较小的边，暂定为最小边，更新相关数组
			wMin = edges[i].eWeight;
			minEdge.eWeight = edges[i].eWeight;
			minEdge.vBegin = edges[i].vBegin;
			minEdge.vEnd = edges[i].vEnd;
			n = i;
		}
	}
	return minEdge;
}

//打印结果
void print_Kruskal(Graph &G, EdgeType treeEdges[], int ans) {
	printf("生成树的边长之和：%d\n", ans);
	printf("边的连接信息如下：\n");
	for (int i = 1; i < G.VerNum; i++) {
		printf("%c---%c :%d\n", G.Data[treeEdges[i].vBegin], G.Data[treeEdges[i].vEnd],treeEdges[i].eWeight);
	}
}

//Kruskal 算法
void Kruskal(Graph &G) {
	int conVerID[MaxVerNum+1]; //顶点的连通分量编号数组
	EdgeType edges[MaxVerNum*MaxVerNum + 1]; //存放所有边信息
	EdgeType treeEdges[MaxVerNum]; //存放生成树中的边信息
	bool edgeUsed[MaxVerNum*MaxVerNum + 1]; //标记边是否用过
	int ans=0; //记录生成树边长之和

	EdgeType minEdge;
	int k = 0;
	int conID; //边的终止顶点vEnd的连通分量的编号
	int n; //最小边在edges[]的下标
	GetEdges(G, edges); //获取边信息，存入edges[]

	int M; //控制循环次数
	if (G.gKind == UDG || G.gKind == UDN)
		M = G.ArcNum * 2;
	else
		M = G.ArcNum;
	//初始化标记数组
	for (int i = 1; i <= M; i++) {
		edgeUsed[i] = false;
	}
	//初始化连通分量编号
	for (int i = 1; i < G.VerNum; i++) {
		conVerID[i] = i;
	}

	for (int i = 1; i < G.VerNum; i++) {//选取G.Vernum-1条边
		minEdge = GetMinEdge(G, edges, edgeUsed, n); //获取一条最小边
		while (conVerID[minEdge.vBegin] == conVerID[minEdge.vEnd]) {//如果加入minEdge会出现回路
			edgeUsed[n] = true; //标记此边不可用
			minEdge = GetMinEdge(G, edges, edgeUsed, n); //继续选下一条边
		}
		//至此选取了一条最小可用边
		treeEdges[i] = minEdge;
		ans += minEdge.eWeight;
		conID = conVerID[minEdge.vEnd]; //取得最小边的终点编号
		for (int j = 1; j <= G.VerNum; j++) { 
			//将所有连通分量编号为conID的顶点，连通分量编号都改为该最小边起始顶点的连通号
			if (conVerID[j] == conID) {
				conVerID[j] = conVerID[minEdge.vBegin];
			}
		}
		edgeUsed[n] = true; //标记当前的边已用过
	}
	print_Kruskal(G,treeEdges, ans);
}

