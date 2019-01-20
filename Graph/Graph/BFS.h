#pragma once

#include<queue>

void BFS(Graph &G, int v) { //�ӱ��Ϊv�Ķ��������ȱ���һ����ͨ����
	int w;//�ڽӵ�
	queue<elementType> Q;
	visit(G, v); //����v
	visited[v] = true;//����v��ϣ����÷��ʱ�־
	Q.push(v);//v���
	while (!Q.empty()) {
		v = Q.front(); //��v���ӣ���ʼ�������ڽӵ�
		Q.pop();
		w = firstAdj(G, v); // ��v�ĵ�һ���ڽӵ�
		while (w != 0) {
			if (!visited[w]) {//w��δ����,������ʣ������
				visit(G,w); //����w
				visited[w] = true; //����w��ϣ����÷��ʱ�־
				Q.push(w); //��w���
			}
			w = nextAdj(G, v,w);// ����һ������
		}
	}
}

void BFSTraverse(Graph &G) {
	for (int i = 1; i <= G.VerNum; i++) {
		visited[i] = false; //��ʼ�����ʱ�־
	}
	for (int i = 1; i <= G.VerNum; i++) { 
		if (!visited[i]) {
			BFS(G, i); //ÿ����һ�Σ�����һ����ͨ��֧
		}
	}
	printf("����");
}


void BFS_path(Graph &G, int v) { //�ӱ��Ϊv�Ķ��������ȱ���һ����ͨ����
	int w;//�ڽӵ�
	queue<elementType> Q;
	visit_path(G, v); //����v
	visited[v] = true;
	Q.push(v);//v���
	while (!Q.empty()) {
		v = Q.front(); //��v���ӣ���ʼ�������ڽӵ�
		Q.pop();
		w = firstAdj(G, v); // ��v�ĵ�һ���ڽӵ�
		while (w != 0) {
			if (!visited[w]) {//w��δ����,������ʣ������
				visit_path(G, w); //����w
				visited[w] = true; //����w��ϣ����÷��ʱ�־
				Q.push(w); //��w���
			}
			w = nextAdj(G, v, w);// ����һ������
		}
	}
	printf("����\n");
}

void BFSTraverse_path(Graph &G,int v) {
	for (int i = 1; i <= G.VerNum; i++) {
		visited[i] = false; //��ʼ�����ʱ�־
	}
	for (int i = 0; i <= G.VerNum; i++) {
		if (!visited[i]) {
			if (i == 0) {
				BFS_path(G, v); //vΪ���
			}
			else {
				BFS_path(G, i); //ÿ����һ�Σ�����һ����ͨ��֧
			}
		}
	}
}

