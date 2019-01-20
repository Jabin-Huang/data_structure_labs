#pragma once
 
 
//cnt1��¼�Ƚϴ�����cnt2��¼�ƶ�����
void partition(elementType A[], int s, int t, int &cutPoint) {
	elementType x = A[s]; //�ڳ���λ
	int i = s, j = t; //��ʼ������λ��
	while (i != j) {  //����������λ��δ�غ�ʱ
		cnt1++;
		while (i < j&&A[j].key > x.key) {//�Ӻ����ҵ���һ�����м�Ԫ��С��Ԫ��
			j--;
			cnt1++; 
		}
		if (i < j) {  //�ҵ��󣬽������ǰ��Ŀ�λ��ͬʱ�����ڳ���λ
			A[i] = A[j];
			i++;
			cnt2++;
			//print_dy(A);
		}
		
		cnt1++;
		while (i < j&&A[i].key < x.key) {//��ǰ���ҵ���һ�����м�Ԫ�ش��Ԫ��
			i++;
			cnt1++;
		}
		if (i < j) {  //�ҵ��󣬽����������Ŀ�λ��ͬʱ�����ڳ���λ
			A[j] = A[i];
			j--;
			cnt2++;
			//print_dy(A);
		}
	}
	A[i] = x;
	cutPoint = i;//���м�Ԫ�ص�λ�ûش�
}


void quickSort(elementType A[], int s, int t) {
	//��A�е��±��s��t��Ԫ����ɵ��ӱ���п�������
	int i;
	if (s < t) {
		partition(A, s, t, i);
		quickSort(A, s, i - 1);
		quickSort(A, i + 1, t);
	}
}

void partition_dy(elementType A[], int s, int t, int &cutPoint) {
	elementType x = A[s]; //�ڳ���λ
	int i = s, j = t; //��ʼ������λ��
	while (i != j) {  //����������λ��δ�غ�ʱ
		cnt1++;
		while (i < j&&A[j].key > x.key) {//�Ӻ����ҵ���һ�����м�Ԫ��С��Ԫ��
			j--;
			cnt1++;
		}
		if (i < j) {  //�ҵ��󣬽������ǰ��Ŀ�λ��ͬʱ�����ڳ���λ
			A[i] = A[j];
			i++;
			cnt2++;
			print_dy(A);
		}

		cnt1++;
		while (i < j&&A[i].key < x.key) {//��ǰ���ҵ���һ�����м�Ԫ�ش��Ԫ��
			i++;
			cnt1++;
		}
		if (i < j) {  //�ҵ��󣬽����������Ŀ�λ��ͬʱ�����ڳ���λ
			A[j] = A[i];
			j--;
			cnt2++;
			print_dy(A);
		}
	}
	A[i] = x;
	cutPoint = i;//���м�Ԫ�ص�λ�ûش�
}


void quickSort_dy(elementType A[], int s, int t) {
	//��A�е��±��s��t��Ԫ����ɵ��ӱ���п�������
	int i;
	if (s < t) {
		partition_dy(A, s, t, i);
		quickSort_dy(A, s, i - 1);
		quickSort_dy(A, i + 1, t);
	}
}

