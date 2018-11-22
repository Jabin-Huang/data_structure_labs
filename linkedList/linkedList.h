#pragma once

typedef int elementType;

typedef struct Node{
    elementType data;
    struct Node* next;
}node;

class List{
private:
    int length;
    node *L; //ͷ�ڵ�
public:
    void init(); //�����ʼ��
    node* head() {return L;} //��ȡͷ�ڵ�
    void destroy();  //����
    void createList(); //β�巨����
    void createListH(); //ͷ�巨����
    void print(); //��ӡ
    int getLength(); //��������
    bool getElement(int i,elementType &x); //��ȡ��i��Ԫ�أ�ʧ�ܱ���
    bool insert(int i,elementType x); //�ڵ�i�����ǰ����ֵΪx�Ľ�㣬ʧ�ܱ���
    void insert(elementType x);
    node* find(elementType x); //����ֵΪx�Ľ�㣬�ɹ�����ָ�룬ʧ�ܱ���
    bool remove(int i); //ɾ����i�����
    void insertA(elementType x); //���������������Ԫ��x����������
    void decomposeOddEven();//��ż��ֽ�
    List intersect(List const& L);//��������Ԫ�أ������±�
    void unique(); //ȥ��
    void merge(List &L); //����ϲ�����ͷΪL1��ɾ��L2��ͷ��
    bool subsetJudge(List const& L);//�ж�A�Ƿ�ΪB���Ӽ�
    List subMergeA(List const& B);//C=A��B
    void subMergeB(List &B);//A=A��B
    List subIntersectA(List const& B);//C=A��B
    void subIntersectB(List const& B);//A=A��B
    List subTractionA(List const& B);//C=A-B
    void subTractionB(List const& B);//A=A-B
    elementType fun2011(List const& L,int n);
    elementType fun2009(int k);

};



#include"linkedList_functions.h"








