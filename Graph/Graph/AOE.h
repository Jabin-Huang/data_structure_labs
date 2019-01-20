#pragma once



void PrintKeyPath(Graph &G, int topoList[], int vet[], int vlt[]) {	//�ж��ؼ�·�������
	int w, v;
	cout << " �ؼ�·����";
	v = topoList[1];
	cout << G.Data[v] << "\t";    //���Դ��	
	while (v != 0) {
		w = firstAdj(G, v);          //����v�ĵ�һ���ڽӵ�
		while (w != 0) {
			if (vet[w] == vlt[w])   //����ؼ�������Ķ���
			{
				cout << G.Data[w] << "\t";
				break;
			}
			else
				w = nextAdj(G, v, w);  //������һ���ڽӵ�
		}
		v = w;
	}
}


void KeyPath(Graph &G,int topoList[]) {
	int i, j;
	int vPre;  //���涥���ǰ��������
	int vSuc;  //���涥��ĺ�̶�����
	int vet[MaxVerNum+1]; //�������緢��ʱ��
	int vlt[MaxVerNum+1]; //������ٷ���ʱ��
	//��ʼ��AOE���и�����������緢��ʱ��Ϊ0
	for (i = 1; i <= G.VerNum; i++)
		vet[i] = 0;   //vet[0]��Ԫ����
	//�����˴�����������㣨�¼��������緢��ʱ�䣬
	//���vet[]������
	for (i = 1; i <= G.VerNum; i++) {    //ȡ�����������еĵ�һ�����㣨��ţ�vPre
			//����vPre�����ڽӶ�������緢��ʱ��
		vPre = topoList[i];
		for (j = 1; j <= G.VerNum; j++) {                      //vPre��j ����
			if (G.AdjMatrix[vPre][j] >= 1 && G.AdjMatrix[vPre][j] < INF)
				if (vet[j] < vet[vPre] + G.AdjMatrix[vPre][j])
					vet[j] = vet[vPre] + G.AdjMatrix[vPre][j];
			//���¶���j�����緢��ʱ��
		}
	}
	//��ʼ��ÿ���������ٷ���ʱ�䣬��ʼֵȫ����Ϊvet[G.VerNum] 
	//�����������л������緢��ʱ��
	for (i = 1; i <= G.VerNum; i++)
		vlt[i] = vet[G.VerNum];
	//�������˴�����ÿ�����㣨�¼�������ٷ���ʱ��
   //����vSuc����ٷ���ʱ���Ѿ�ȷ����
   //����vSucÿ��ǰ������ٷ���ʱ��
	for (i = G.VerNum; i >= 1; i--) {
		vSuc = topoList[i];
		for (j = G.VerNum; j >= 1; j--) {                      //j��vSuc����
			if (G.AdjMatrix[j][vSuc] >= 1 && G.AdjMatrix[j][vSuc] < INF) 		
				if (vlt[j] > vlt[vSuc] - G.AdjMatrix[j][vSuc])
					vlt[j] = vlt[vSuc] - G.AdjMatrix[j][vSuc];
					//����j����ٷ���ʱ�� 
		}
	}
	PrintKeyPath(G, topoList, vet, vlt);
}

