#pragma once



void PrintDijkstra(Graph &G, int path[], int dist[], int vID) {
	int sPath[MaxVerNum]; //保存vID到i的最短路径顶点
	int vPre;		//前驱结点编号
	int top = -1; //保存最短路径上的顶点个数，以控制输出最短路径
	for (int i = 1; i <= G.VerNum; i++) {
		cout << G.Data[vID] << " --->" << G.Data[i];
		if (dist[i] == INF) {
			cout << "无可达路径" << endl;
			continue;
		}
		else {
			cout << "最短距离：" << dist[i] << endl;
			cout << "   路径：";
		}

		top++;
		sPath[top] = i; //sPath{0]保存目标顶点编号
		vPre = path[i]; //取i的直接前驱
		//迭代求前驱，依次保存到sPath[]
		while (vPre != -1) {
			top++;
			sPath[top] = vPre;
			vPre = path[vPre];
		}

		//最短路径存在则输出路径
		if (dist[i] != INF) {
			for (int j = top; j >= 0; j--) {
				cout << G.Data[sPath[j]] << " ";
			}
		}
		top = -1;
		cout << endl;
	}
}

void Dijkstra(Graph &G, int path[], int dist[], int vID) {
	//path[]保存最短路径信息 path[i]=j表示i的前驱是j
	//dist[]保存最短路径距离值  dist[i]表示从vID到i的距离
	//vID为指定起始顶点编号

	bool solved[MaxVerNum];
	cellType minDist;
	//初始化dist[]和solved[]
	for (int i = 1; i <= G.VerNum; i++) {
		solved[i] = false;
		dist[i] = G.AdjMatrix[vID][i];
		if (dist[i] != INF)
			path[i] = vID; //第i顶点的前驱为vID
		else
			path[i] = -1; //当前顶点i无前驱
	}
	//更新起点有关信息
	solved[vID] = true; 
	dist[vID] = 0;
	path[vID] = -1;

	int v;
	//依次找出其他n-1个顶点
	for (int i = 1; i < G.VerNum; i++) {
		minDist = INF; //暂定最短距离初始化为无穷大
		//在未解顶点中寻找距vID距离最近的顶点，编号存到v
		for (int j = 1; j <= G.VerNum; j++) {
			if (!solved[j] && dist[j] < minDist) {
				v = j;
				minDist = dist[j];
			}
		}
		if (minDist == INF)//走到尽头
			return;
		//输出本次选择的顶点距离
		//cout << "选择顶点：" << G.Data[v] << "--距离：" << minDist << endl;
		solved[v] = true;
		//更新dist[]和path[]
		for (int j = 1; j <= G.VerNum; j++) {
			if (!solved[j] && minDist + G.AdjMatrix[v][j] < dist[j]) {
				dist[j] = minDist + G.AdjMatrix[v][j];
				path[j] = v;
			}
		}

	}
	PrintDijkstra(G, path, dist, vID);
}
