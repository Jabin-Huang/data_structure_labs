#pragma once

typedef struct minEdgeType {
	int v; // 边中已选一端的顶点编号
	cellType eWeight;// 边的权值
}MinEdgeType; //边数组的元素类型 


//辅助函数如下：
bool HasEdge(Graph &G, int vBegin, int vEnd, cellType &eWeight) { //（领接矩阵） 判断是否有边，并回传权值
	if (G.AdjMatrix[vBegin][vEnd] != INF&&G.AdjMatrix[vBegin][vEnd]>0) {
		eWeight = G.AdjMatrix[vBegin][vEnd];
		return true;
	}
	else {
		eWeight = INF;
		return false;
	}
}

/*
bool HasEdge(Graph &G, int vBegin, int vEnd, eInfoType &eWeight) { //（邻接表）判断是否有边，并回传权值
	EdgeNode *p; //边链表结点指针
	int f = FALSE; //是否有边的标志
	eWeight = INF;// 边权值初始化为无穷大
	p = G.VerList[vBegin].firstEdge; //获取vBegin的边链表头指针
	while (p) {
		if (p->adjVer == vEnd) { //vBegin和vEnd之间有边
			f = true;
			eWeight = p->eInfo;
			break;
		}
	}
	p = p->next; //搜索边链表中下一个结点
	return f;
}
*/

void  InitialTE(Graph &G, MinEdgeType TE[], int vID) { //vID是起始点编号
	//初始化边数组TE[]，
	int i;
	cellType eWeight;
	for (int i =1; i <= G.VerNum; i++) {
		if (HasEdge(G, vID, i, eWeight)) { //若vID与i之间有边
			//保存边
			TE[i].v = vID;
			TE[i].eWeight = eWeight; 
		}
		else { //没有边，权值置为无穷大
			TE[i].v = i;
			TE[i].eWeight = INF;
		}
	}
}

int GetMinEdge(Graph &G, MinEdgeType TE[],int &ans) {
	cellType eMin = INF;
	int j = 0;
	for (int i = 1; i <= G.VerNum; i++) {
		//i未选，且权值比eMin小，暂选i为候选顶点，对应边(T[i].v,i)为侯选边
		if (!visited[i] && TE[i].eWeight < eMin) {
			j = i;
			eMin = TE[i].eWeight;
		}
	}
	if (eMin != INF) {
		ans += eMin;
	}
	
	return j; //此时j为选中的权值最小的侯选边的一个顶点，对应边（T[j].v,j）为选中的边
}

void updateTE(Graph &G, MinEdgeType TE[], int vID) {//对新选出的编号为vID的点，更新侯选边集合
	cellType eWeight;
	for (int i = 1; i <= G.VerNum; i++) {
		if (!visited[i]) { //若i还未被选，则更新其（vID，i）
			if (HasEdge(G, vID, i, eWeight) && eWeight < TE[i].eWeight) {
				TE[i].v = vID;
				TE[i].eWeight = eWeight;
			}
		}
	}

}

//打印结果
void print_prim(Graph &G, MinEdgeType TE[], int ans) {
	printf("生成树的边长之和：%d\n", ans);
	printf("边连接信息如下:\n");
	for (int i = 1; i <= G.VerNum; i++) {
		if (G.Data[TE[i].v] != G.Data[i]) {
			printf("%c---%c :%d\n", G.Data[TE[i].v], G.Data[i],G.AdjMatrix[TE[i].v][i]);
		}
	}
}

//Prim算法
void Prim(Graph &G, int vID) { //从起始顶点vID开始Prim算法
	for (int i = 1; i <=G.VerNum; i++) { //初始化标记数组
		visited[i] = false;
	}

	int ans=0; //记录生成树的边长之和
	MinEdgeType TE[MaxVerNum+1]; //0单元不用
	//TE[i].v表示v->i存在，且权值为TE[i].eWeight
	int curID;	//当前选择的顶点编号
	InitialTE(G, TE, vID); //初始化TE数组
	visited[vID] = true; //标记vID已选
	for (int i = 1; i <= G.VerNum; i++) {
		curID = GetMinEdge(G, TE,ans); //获得权值最小的侯选边，返回未选一端的顶点编号
		visited[curID] = true; //标记已选
		updateTE(G, TE, curID); //更新侯选边集
	}
	print_prim(G, TE, ans);
}

