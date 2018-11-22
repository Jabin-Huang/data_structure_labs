#pragma once

#define MAX 1000
typedef int elementType;
typedef int Rank;
//Rank ΪԪ�����
//elementType ΪԪ������


class seqList{
private:
    int length=0;
    elementType data[MAX]={0};
public:
    //seqList();
    //~seqList();
    void randInit(int n);
    int getLength(){return length;}
    bool getElement(Rank i,elementType &x); //����<1>����ȡԪ��
    bool insert(Rank i,elementType x); //����<2>,ָ��λ�ò���
    void insert(elementType x);     //��x����˳���ĩβ
    bool remove(Rank i);         //����<3>��ɾ��ָ��λ��Ԫ��
    Rank find(elementType x);    //����˳���Ĳ��ң����ص���x�����һ��Ԫ�ص����,�����ڷ���-1
    Rank search(elementType x);         //����˳���Ķ��ֲ���,���ز�����x�����һ��Ԫ�ص����
    void insertA(elementType x); //����<4>,���������˳������
    void decompose_odd_even();   //����<5>���ֽ��������ż����
    seqList intersect(seqList const &L); //����<6>�� ��������������˳���Ĺ���Ԫ�أ����ع���Ԫ����ɵ�˳��� / C=A��B
    void intersectA(seqList const &L); //A=A��B
    seqList _union(seqList const &L); //C=A��B
    void _unionA(seqList const &L); //A=A��B
    seqList subtraction(seqList const &L);//C=A-B
    void subtractionA(seqList const &L);//A=A-B
    int unique();               //����<7>�� ��������˳���ɾ���ظ�Ԫ��,�����ƶ�����
    void mergeToSet(seqList const &L);  //��չ����<1>
    bool subSetJudge(seqList const &L); //��չ����<3>
    elementType finalTask(seqList const& L);//��չ����<4>

};

#include"seqlist_functions.h"


