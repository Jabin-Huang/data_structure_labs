#pragma once

void shellSort(elementType A[], int dh) {
	//dhΪ��ʼ������Լ��1<dh<=n/2
	while (dh >= 1) { //ͨ���������������ִ�й���,������Ϊ1ʱ�����һ�ε�ֱ�Ӳ�������
		for (int i = dh + 1; i <= n; i++) { //���β���Ԫ�ص�ǰ����������
			elementType temp = A[i];	//�ڳ���λ
			int j = i;					//jָʾ��λ��
			cnt1++;
			while (j > dh&&temp.key < A[j - dh].key) {
				A[j] = A[j - dh]; //�ƶ�Ԫ��
				cnt2++;
				//print_dy(A);
				j = j - dh; //jǰ��
				cnt1++;
			}
			A[j] = temp; //����Ԫ��
			cnt2++;
			//print_dy(A);
		}
		dh = dh / 2; //����ÿ������һ��
	}
}
	