#pragma once

typedef int elementType;

typedef struct Node{
    elementType data;
    struct Node* next;
}node;

class List{
private:
    int length;
    node *L; //头节点
public:
    void init(); //链表初始化
    node* head() {return L;} //获取头节点
    void destroy();  //销毁
    void createList(); //尾插法创建
    void createListH(); //头插法创建
    void print(); //打印
    int getLength(); //求链表长度
    bool getElement(int i,elementType &x); //获取第i个元素，失败报错
    bool insert(int i,elementType x); //在第i个结点前插入值为x的结点，失败报错
    void insert(elementType x);
    node* find(elementType x); //查找值为x的结点，成功返回指针，失败报错
    bool remove(int i); //删除第i个结点
    void insertA(elementType x); //递增有序链表插入元素x并保持有序
    void decomposeOddEven();//奇偶项分解
    List intersect(List const& L);//求两表公共元素，放入新表
    void unique(); //去重
    void merge(List &L); //两表合并，表头为L1，删除L2表头；
    bool subsetJudge(List const& L);//判断A是否为B的子集
    List subMergeA(List const& B);//C=A∪B
    void subMergeB(List &B);//A=A∪B
    List subIntersectA(List const& B);//C=A∩B
    void subIntersectB(List const& B);//A=A∩B
    List subTractionA(List const& B);//C=A-B
    void subTractionB(List const& B);//A=A-B
    elementType fun2011(List const& L,int n);
    elementType fun2009(int k);

};



#include"linkedList_functions.h"








