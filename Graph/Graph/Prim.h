#pragma once

typedef struct minEdgeType {
	int v; // ������ѡһ�˵Ķ�����
	cellType eWeight;// �ߵ�Ȩֵ
}MinEdgeType; //�������Ԫ������ 


//�����������£�
bool HasEdge(Graph &G, int vBegin, int vEnd, cellType &eWeight) { //����Ӿ��� �ж��Ƿ��бߣ����ش�Ȩֵ
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
bool HasEdge(Graph &G, int vBegin, int vEnd, eInfoType &eWeight) { //���ڽӱ��ж��Ƿ��бߣ����ش�Ȩֵ
	EdgeNode *p; //��������ָ��
	int f = FALSE; //�Ƿ��бߵı�־
	eWeight = INF;// ��Ȩֵ��ʼ��Ϊ�����
	p = G.VerList[vBegin].firstEdge; //��ȡvBegin�ı�����ͷָ��
	while (p) {
		if (p->adjVer == vEnd) { //vBegin��vEnd֮���б�
			f = true;
			eWeight = p->eInfo;
			break;
		}
	}
	p = p->next; //��������������һ�����
	return f;
}
*/

void  InitialTE(Graph &G, MinEdgeType TE[], int vID) { //vID����ʼ����
	//��ʼ��������TE[]��
	int i;
	cellType eWeight;
	for (int i =1; i <= G.VerNum; i++) {
		if (HasEdge(G, vID, i, eWeight)) { //��vID��i֮���б�
			//�����
			TE[i].v = vID;
			TE[i].eWeight = eWeight; 
		}
		else { //û�бߣ�Ȩֵ��Ϊ�����
			TE[i].v = i;
			TE[i].eWeight = INF;
		}
	}
}

int GetMinEdge(Graph &G, MinEdgeType TE[],int &ans) {
	cellType eMin = INF;
	int j = 0;
	for (int i = 1; i <= G.VerNum; i++) {
		//iδѡ����Ȩֵ��eMinС����ѡiΪ��ѡ���㣬��Ӧ��(T[i].v,i)Ϊ��ѡ��
		if (!visited[i] && TE[i].eWeight < eMin) {
			j = i;
			eMin = TE[i].eWeight;
		}
	}
	if (eMin != INF) {
		ans += eMin;
	}
	
	return j; //��ʱjΪѡ�е�Ȩֵ��С�ĺ�ѡ�ߵ�һ�����㣬��Ӧ�ߣ�T[j].v,j��Ϊѡ�еı�
}

void updateTE(Graph &G, MinEdgeType TE[], int vID) {//����ѡ���ı��ΪvID�ĵ㣬���º�ѡ�߼���
	cellType eWeight;
	for (int i = 1; i <= G.VerNum; i++) {
		if (!visited[i]) { //��i��δ��ѡ��������䣨vID��i��
			if (HasEdge(G, vID, i, eWeight) && eWeight < TE[i].eWeight) {
				TE[i].v = vID;
				TE[i].eWeight = eWeight;
			}
		}
	}

}

//��ӡ���
void print_prim(Graph &G, MinEdgeType TE[], int ans) {
	printf("�������ı߳�֮�ͣ�%d\n", ans);
	printf("��������Ϣ����:\n");
	for (int i = 1; i <= G.VerNum; i++) {
		if (G.Data[TE[i].v] != G.Data[i]) {
			printf("%c---%c :%d\n", G.Data[TE[i].v], G.Data[i],G.AdjMatrix[TE[i].v][i]);
		}
	}
}

//Prim�㷨
void Prim(Graph &G, int vID) { //����ʼ����vID��ʼPrim�㷨
	for (int i = 1; i <=G.VerNum; i++) { //��ʼ���������
		visited[i] = false;
	}

	int ans=0; //��¼�������ı߳�֮��
	MinEdgeType TE[MaxVerNum+1]; //0��Ԫ����
	//TE[i].v��ʾv->i���ڣ���ȨֵΪTE[i].eWeight
	int curID;	//��ǰѡ��Ķ�����
	InitialTE(G, TE, vID); //��ʼ��TE����
	visited[vID] = true; //���vID��ѡ
	for (int i = 1; i <= G.VerNum; i++) {
		curID = GetMinEdge(G, TE,ans); //���Ȩֵ��С�ĺ�ѡ�ߣ�����δѡһ�˵Ķ�����
		visited[curID] = true; //�����ѡ
		updateTE(G, TE, curID); //���º�ѡ�߼�
	}
	print_prim(G, TE, ans);
}

