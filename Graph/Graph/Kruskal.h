#pragma once

typedef struct edgetype {
	int vBegin;
	int vEnd;
	cellType eWeight;
}EdgeType;


//�����������£�
void GetEdges(Graph &G, EdgeType edges[]) { //��ȡ�ߵ������� ���ڽӾ���
	int k = 1;// �������±�
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
	//����Ȩֵ��С�ıߣ�nΪ��С����edges[]�е��±�
	EdgeType minEdge;
	cellType wMin = INF;//������СȨֵ
	int M; //����ѭ������
	if (G.gKind == UDG || G.gKind == UDN) //����ͼ������
		M = G.ArcNum * 2;
	else
		M = G.ArcNum;// ����ͼ������
	for (int i = 1; i <= M; i++) {
		if (!edgeUsed[i] && edges[i].eWeight < wMin) {
			//��δʹ�ã���Ȩֵ��С�ıߣ��ݶ�Ϊ��С�ߣ������������
			wMin = edges[i].eWeight;
			minEdge.eWeight = edges[i].eWeight;
			minEdge.vBegin = edges[i].vBegin;
			minEdge.vEnd = edges[i].vEnd;
			n = i;
		}
	}
	return minEdge;
}

//��ӡ���
void print_Kruskal(Graph &G, EdgeType treeEdges[], int ans) {
	printf("�������ı߳�֮�ͣ�%d\n", ans);
	printf("�ߵ�������Ϣ���£�\n");
	for (int i = 1; i < G.VerNum; i++) {
		printf("%c---%c :%d\n", G.Data[treeEdges[i].vBegin], G.Data[treeEdges[i].vEnd],treeEdges[i].eWeight);
	}
}

//Kruskal �㷨
void Kruskal(Graph &G) {
	int conVerID[MaxVerNum+1]; //�������ͨ�����������
	EdgeType edges[MaxVerNum*MaxVerNum + 1]; //������б���Ϣ
	EdgeType treeEdges[MaxVerNum]; //����������еı���Ϣ
	bool edgeUsed[MaxVerNum*MaxVerNum + 1]; //��Ǳ��Ƿ��ù�
	int ans=0; //��¼�������߳�֮��

	EdgeType minEdge;
	int k = 0;
	int conID; //�ߵ���ֹ����vEnd����ͨ�����ı��
	int n; //��С����edges[]���±�
	GetEdges(G, edges); //��ȡ����Ϣ������edges[]

	int M; //����ѭ������
	if (G.gKind == UDG || G.gKind == UDN)
		M = G.ArcNum * 2;
	else
		M = G.ArcNum;
	//��ʼ���������
	for (int i = 1; i <= M; i++) {
		edgeUsed[i] = false;
	}
	//��ʼ����ͨ�������
	for (int i = 1; i < G.VerNum; i++) {
		conVerID[i] = i;
	}

	for (int i = 1; i < G.VerNum; i++) {//ѡȡG.Vernum-1����
		minEdge = GetMinEdge(G, edges, edgeUsed, n); //��ȡһ����С��
		while (conVerID[minEdge.vBegin] == conVerID[minEdge.vEnd]) {//�������minEdge����ֻ�·
			edgeUsed[n] = true; //��Ǵ˱߲�����
			minEdge = GetMinEdge(G, edges, edgeUsed, n); //����ѡ��һ����
		}
		//����ѡȡ��һ����С���ñ�
		treeEdges[i] = minEdge;
		ans += minEdge.eWeight;
		conID = conVerID[minEdge.vEnd]; //ȡ����С�ߵ��յ���
		for (int j = 1; j <= G.VerNum; j++) { 
			//��������ͨ�������ΪconID�Ķ��㣬��ͨ������Ŷ���Ϊ����С����ʼ�������ͨ��
			if (conVerID[j] == conID) {
				conVerID[j] = conVerID[minEdge.vBegin];
			}
		}
		edgeUsed[n] = true; //��ǵ�ǰ�ı����ù�
	}
	print_Kruskal(G,treeEdges, ans);
}

