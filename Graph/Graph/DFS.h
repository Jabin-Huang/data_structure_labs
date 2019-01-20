#pragma once

void DFS(Graph &G, int v) { //�Ա��v�Ķ���Ϊ����������������ɱ���һ����ͨ����
	int w; //��ӵ�
	visit(G, v); //���ʵ�v
	visited[v] = true; //������ϣ����÷��ʱ�־
	w = firstAdj(G, v); //���һ����ӵ�
	while (w != 0) { //���������ڽӵ�
		if (visited[w] == false) { //��δ���ʹ����ڽӵ��������������ȱ���
			DFS(G, w); 
		}
		w = nextAdj(G, v, w); //��λ��w֮�����һ����ӵ�
	}
}

void DFSTraverse(Graph &G) {
	for (int i = 1; i <= G.VerNum; i++) {
		visited[i] = false; //��ʼ�����ʱ�־
	}
	for (int i = 1; i <= G.VerNum; i++) {
		if (visited[i] == false) { //�ӻ�δ���ʵĶ������������ȱ���
			DFS(G, i); //���ÿѭ��һ�Σ��ͱ�����һ����ͨ����
		}
	}
	printf("����");
	//�㷨��ɣ���ɶ�ȫͼ�ı���
}

void DFS_path(Graph &G, int v) { //�Ա��v�Ķ���Ϊ����������������ɱ���һ����ͨ����
	int w; //��ӵ�
	visit_path(G, v); //���ʵ�v
	visited[v] = true; //������ϣ����÷��ʱ�־
	w = firstAdj(G, v); //���һ����ӵ�
	while (w != 0) { //���������ڽӵ�
		if (visited[w] == false) { //��δ���ʹ����ڽӵ��������������ȱ���
			DFS_path(G, w);
		}
		w = nextAdj(G, v, w); //��λ��w֮�����һ����ӵ�
	}
}

void DFSTraverse_path(Graph &G,int v) {
	for (int i = 1; i <= G.VerNum; i++) {
		visited[i] = false; //��ʼ�����ʱ�־
	}
	for (int i = 0; i <= G.VerNum; i++) {
		if (visited[i] == false) { //�ӻ�δ���ʵĶ������������ȱ���
			if (i == 0) {
				DFS_path(G, v); //��㿪ʼ
				printf("����\n");
			}
			else {
				DFS_path(G, i); //���ÿѭ��һ�Σ��ͱ�����һ����ͨ����
				printf("����\n");
			}
		}
	}
	//�㷨��ɣ���ɶ�ȫͼ�ı���
}
