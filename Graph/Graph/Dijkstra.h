#pragma once



void PrintDijkstra(Graph &G, int path[], int dist[], int vID) {
	int sPath[MaxVerNum]; //����vID��i�����·������
	int vPre;		//ǰ�������
	int top = -1; //�������·���ϵĶ���������Կ���������·��
	for (int i = 1; i <= G.VerNum; i++) {
		cout << G.Data[vID] << " --->" << G.Data[i];
		if (dist[i] == INF) {
			cout << "�޿ɴ�·��" << endl;
			continue;
		}
		else {
			cout << "��̾��룺" << dist[i] << endl;
			cout << "   ·����";
		}

		top++;
		sPath[top] = i; //sPath{0]����Ŀ�궥����
		vPre = path[i]; //ȡi��ֱ��ǰ��
		//������ǰ�������α��浽sPath[]
		while (vPre != -1) {
			top++;
			sPath[top] = vPre;
			vPre = path[vPre];
		}

		//���·�����������·��
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
	//path[]�������·����Ϣ path[i]=j��ʾi��ǰ����j
	//dist[]�������·������ֵ  dist[i]��ʾ��vID��i�ľ���
	//vIDΪָ����ʼ������

	bool solved[MaxVerNum];
	cellType minDist;
	//��ʼ��dist[]��solved[]
	for (int i = 1; i <= G.VerNum; i++) {
		solved[i] = false;
		dist[i] = G.AdjMatrix[vID][i];
		if (dist[i] != INF)
			path[i] = vID; //��i�����ǰ��ΪvID
		else
			path[i] = -1; //��ǰ����i��ǰ��
	}
	//��������й���Ϣ
	solved[vID] = true; 
	dist[vID] = 0;
	path[vID] = -1;

	int v;
	//�����ҳ�����n-1������
	for (int i = 1; i < G.VerNum; i++) {
		minDist = INF; //�ݶ���̾����ʼ��Ϊ�����
		//��δ�ⶥ����Ѱ�Ҿ�vID��������Ķ��㣬��Ŵ浽v
		for (int j = 1; j <= G.VerNum; j++) {
			if (!solved[j] && dist[j] < minDist) {
				v = j;
				minDist = dist[j];
			}
		}
		if (minDist == INF)//�ߵ���ͷ
			return;
		//�������ѡ��Ķ������
		//cout << "ѡ�񶥵㣺" << G.Data[v] << "--���룺" << minDist << endl;
		solved[v] = true;
		//����dist[]��path[]
		for (int j = 1; j <= G.VerNum; j++) {
			if (!solved[j] && minDist + G.AdjMatrix[v][j] < dist[j]) {
				dist[j] = minDist + G.AdjMatrix[v][j];
				path[j] = v;
			}
		}

	}
	PrintDijkstra(G, path, dist, vID);
}
