#pragma once



void PrintKeyPath(Graph &G, int topoList[], int vet[], int vlt[]) {	//判定关键路径并输出
	int w, v;
	cout << " 关键路径：";
	v = topoList[1];
	cout << G.Data[v] << "\t";    //输出源点	
	while (v != 0) {
		w = firstAdj(G, v);          //搜索v的第一个邻接点
		while (w != 0) {
			if (vet[w] == vlt[w])   //输出关键活动关联的顶点
			{
				cout << G.Data[w] << "\t";
				break;
			}
			else
				w = nextAdj(G, v, w);  //搜索下一个邻接点
		}
		v = w;
	}
}


void KeyPath(Graph &G,int topoList[]) {
	int i, j;
	int vPre;  //保存顶点的前驱顶点编号
	int vSuc;  //保存顶点的后继顶点编号
	int vet[MaxVerNum+1]; //顶点最早发生时间
	int vlt[MaxVerNum+1]; //顶点最迟发生时间
	//初始化AOE网中各个顶点的最早发生时间为0
	for (i = 1; i <= G.VerNum; i++)
		vet[i] = 0;   //vet[0]单元不用
	//按拓扑次序求各个顶点（事件）的最早发生时间，
	//存放vet[]数组中
	for (i = 1; i <= G.VerNum; i++) {    //取出拓扑序列中的第一个顶点（编号）vPre
			//更新vPre所有邻接顶点的最早发生时间
		vPre = topoList[i];
		for (j = 1; j <= G.VerNum; j++) {                      //vPre与j 相邻
			if (G.AdjMatrix[vPre][j] >= 1 && G.AdjMatrix[vPre][j] < INF)
				if (vet[j] < vet[vPre] + G.AdjMatrix[vPre][j])
					vet[j] = vet[vPre] + G.AdjMatrix[vPre][j];
			//更新顶点j的最早发生时间
		}
	}
	//初始化每个顶点的最迟发生时间，初始值全部置为vet[G.VerNum] 
	//即：拓扑序列汇点的最早发生时间
	for (i = 1; i <= G.VerNum; i++)
		vlt[i] = vet[G.VerNum];
	//按逆拓扑次序求每个顶点（事件）的最迟发生时间
   //顶点vSuc的最迟发生时间已经确定，
   //更新vSuc每个前驱的最迟发生时间
	for (i = G.VerNum; i >= 1; i--) {
		vSuc = topoList[i];
		for (j = G.VerNum; j >= 1; j--) {                      //j与vSuc相邻
			if (G.AdjMatrix[j][vSuc] >= 1 && G.AdjMatrix[j][vSuc] < INF) 		
				if (vlt[j] > vlt[vSuc] - G.AdjMatrix[j][vSuc])
					vlt[j] = vlt[vSuc] - G.AdjMatrix[j][vSuc];
					//更新j的最迟发生时间 
		}
	}
	PrintKeyPath(G, topoList, vet, vlt);
}

