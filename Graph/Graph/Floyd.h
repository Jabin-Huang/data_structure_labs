#pragma once


void PrintFloyed(Graph &G, int path[][MaxVerNum + 1], int dist[][MaxVerNum + 1]) {
	for (int vID = 1; vID <= G.VerNum; vID++) {
		int sPath[MaxVerNum + 1]; //保存vID到i的最短路径顶点
		int vPre;		//前驱结点编号
		int top = -1; //保存最短路径上的顶点个数，以控制输出最短路径
		for (int i = 1; i <= G.VerNum; i++) {
			cout << G.Data[vID] << "--->" << G.Data[i];
			if (dist[vID][i] == INF) {
				cout << "无可达路径" << endl;
				continue;
			}
			else {
				cout << "最短距离：" << dist[vID][i] << endl;
				cout << " 路径：";
			}

			top++;
			sPath[top] = i; //sPath{0]保存目标顶点编号
			vPre = path[vID][i]; //取i的直接前驱
			//迭代求前驱，依次保存到sPath[]
			while (vPre != -1) {
				top++;
				sPath[top] = vPre;
				vPre = path[vID][vPre];
			}

			//最短路径存在则输出路径
			if (dist[vID][i] != INF) {
				for (int j = top; j >= 0; j--) {
					cout << G.Data[sPath[j]] << " ";
				}
			}
			top = -1;
			cout << endl;
		}
	}
}

void Floyed(Graph &G, cellType dist[MaxVerNum + 1][MaxVerNum + 1], int path[MaxVerNum + 1][MaxVerNum + 1]) {
	for (int i = 1; i <= G.VerNum; i++) {
		for (int j = 1; j <= G.VerNum; j++) {
			//初始化距离矩阵
			dist[i][j] = G.AdjMatrix[i][j];
			//初始化路径矩阵
			//path[i][j]表示从i到j路径上j顶点的直接前驱编号
			if (i != j && G.AdjMatrix[i][j] < INF)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}

	//Floyed算法核心
	for (int m = 1; m <= G.VerNum; m++) {
		//m作为跳点，i和j之间距离变小，接收m作为中转点
		for (int i = 1; i <= G.VerNum; i++) {
			for (int j = 1; j <= G.VerNum; j++) {
				if (i != j && dist[i][m] + dist[m][j] < dist[i][j]) {
					//更新最短距离和j的前驱
					dist[i][j] = dist[i][m] + dist[m][j];
					path[i][j] = path[m][j];
				}
			}
		}
	}
	PrintFloyed(G, path, dist);
}
