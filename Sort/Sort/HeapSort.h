#pragma once


void sift(elementType  A[], int k, int m) {
	//���������±�Ϊ1~n�е�Ԫ���е���Ų�����m����kΪ���������е���
	//������2k��2k+1Ϊ���������������Ƕ�
	elementType x = A[k]; //��ʱ���浱ǰ��ֵ���ճ�λ�ã�����δ������־
	bool finished = false;
	int i = k, j = 2 * i; //iָʾ��λ��j��ָ���ӽ��
	while (j <= m && !finished) {
		cnt1++;
		if (j < m&&A[j].key < A[j + 1].key) {
			j = j + 1;//��jָ�����Һ����е������
		}
		cnt1++;
		if (x.key >= A[j].key) { //ԭ����Ϊ��󣬿��Խ���ɸѡ
			finished = true;
		}
		else {
			cnt2++;
			A[i] = A[j];//��ĺ���������
			i = j; //��������ɸѡ
			j = 2 * j;
		}
	}
	cnt2++;
	A[i] = x; //��ԭ��ֵ��䵽���պϷ�λ��

}

void heapSort(elementType A[], int n) {
	printf("��ʼ����...\n");
	for (int i = n / 2; i >= 1; i--) {
		print_dy(A);
		sift(A, i, n); //����ʼ��
	}
	printf("������ɣ���ʼ�����...\n");
	for (int i = n; i >= 2; i--) {
		swap(A[i], A[1]); //�����
		print_dy(A);
		sift(A,1,i-1);//����������A[1]~A[i-1]Ϊ��
		print_dy(A);
	}
}