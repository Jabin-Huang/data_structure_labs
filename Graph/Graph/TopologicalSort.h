#pragma once

#include<stack>

void GetInDegree(Graph &G, int inds[]) {
	for (int i = 1; i <= G.VerNum; i++) {
		for (int j = 1; j <= G.VerNum; j++) {
			if (i != j && G.AdjMatrix[j][i] > 0 && G.AdjMatrix[j][i] < INF) {
				inds[i]++;
			}
		}
	}
}

int TopologicalSort(Graph &G,int topoList[]) {
	int inds[MaxVerNum + 1]; //�������
	stack<int> S; //�������Ϊ0�Ķ���
	int v;//�����ţ���1��ʼ
	int vCount = 0;//���Ϊ0�Ķ�����
	for (int i = 1; i <= G.VerNum; i++) { //��ʼ���������
		inds[i] = 0;
	}
	for (int i = 1; i <= G.VerNum; i++) { //��ʼ��������������
		topoList[i] = -1;
	}
	GetInDegree(G, inds); //��ȡ��������ĳ�ʼ���
	for (int i = 1; i <= G.VerNum; i++) {//���Ϊ0�Ķ�����ջ
		if (inds[i] == 0) {
			S.push(i);
		}
	}

	while (!S.empty()) {
		v=S.top();//��ջ������һ�����Ϊ0�Ķ�����
		S.pop();
		topoList[++vCount] = v; //������������
		for (int i = 1; i <= G.VerNum; i++) {
			if (G.AdjMatrix[v][i] >= 1 && G.AdjMatrix[v][i] < INF&&inds[i]>0) {
				inds[i]--; //�� v�ڽӵĶ���i���-1
				if (inds[i] == 0) {//�����Ϊ0����ջ
					S.push(i);
				}

			}
		}
	}
	if (vCount == G.VerNum) //�޻�·
		return 1;
	else
		return 0; //�л�·�����ܲ�����������
}