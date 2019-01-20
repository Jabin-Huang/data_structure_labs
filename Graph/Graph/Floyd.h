#pragma once


void PrintFloyed(Graph &G, int path[][MaxVerNum + 1], int dist[][MaxVerNum + 1]) {
	for (int vID = 1; vID <= G.VerNum; vID++) {
		int sPath[MaxVerNum + 1]; //����vID��i�����·������
		int vPre;		//ǰ�������
		int top = -1; //�������·���ϵĶ���������Կ���������·��
		for (int i = 1; i <= G.VerNum; i++) {
			cout << G.Data[vID] << "--->" << G.Data[i];
			if (dist[vID][i] == INF) {
				cout << "�޿ɴ�·��" << endl;
				continue;
			}
			else {
				cout << "��̾��룺" << dist[vID][i] << endl;
				cout << " ·����";
			}

			top++;
			sPath[top] = i; //sPath{0]����Ŀ�궥����
			vPre = path[vID][i]; //ȡi��ֱ��ǰ��
			//������ǰ�������α��浽sPath[]
			while (vPre != -1) {
				top++;
				sPath[top] = vPre;
				vPre = path[vID][vPre];
			}

			//���·�����������·��
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
			//��ʼ���������
			dist[i][j] = G.AdjMatrix[i][j];
			//��ʼ��·������
			//path[i][j]��ʾ��i��j·����j�����ֱ��ǰ�����
			if (i != j && G.AdjMatrix[i][j] < INF)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}

	//Floyed�㷨����
	for (int m = 1; m <= G.VerNum; m++) {
		//m��Ϊ���㣬i��j֮������С������m��Ϊ��ת��
		for (int i = 1; i <= G.VerNum; i++) {
			for (int j = 1; j <= G.VerNum; j++) {
				if (i != j && dist[i][m] + dist[m][j] < dist[i][j]) {
					//������̾����j��ǰ��
					dist[i][j] = dist[i][m] + dist[m][j];
					path[i][j] = path[m][j];
				}
			}
		}
	}
	PrintFloyed(G, path, dist);
}
