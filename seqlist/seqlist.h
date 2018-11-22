#pragma once

#define MAX 1000
typedef int elementType;
typedef int Rank;
//Rank 为元素序号
//elementType 为元素类型


class seqList{
private:
    int length=0;
    elementType data[MAX]={0};
public:
    //seqList();
    //~seqList();
    void randInit(int n);
    int getLength(){return length;}
    bool getElement(Rank i,elementType &x); //任务<1>，获取元素
    bool insert(Rank i,elementType x); //任务<2>,指定位置插入
    void insert(elementType x);     //将x插入顺序表末尾
    bool remove(Rank i);         //任务<3>，删除指定位置元素
    Rank find(elementType x);    //无序顺序表的查找，返回等于x的最后一个元素的序号,不存在返回-1
    Rank search(elementType x);         //有序顺序表的二分查找,返回不大于x的最后一个元素的序号
    void insertA(elementType x); //任务<4>,递增有序的顺序表插入
    void decompose_odd_even();   //任务<5>，分解奇数项和偶数项
    seqList intersect(seqList const &L); //任务<6>， 求两个递增有序顺序表的公共元素，返回公共元素组成的顺序表 / C=A∩B
    void intersectA(seqList const &L); //A=A∩B
    seqList _union(seqList const &L); //C=A∪B
    void _unionA(seqList const &L); //A=A∪B
    seqList subtraction(seqList const &L);//C=A-B
    void subtractionA(seqList const &L);//A=A-B
    int unique();               //任务<7>， 递增有序顺序表删除重复元素,返回移动次数
    void mergeToSet(seqList const &L);  //拓展任务<1>
    bool subSetJudge(seqList const &L); //拓展任务<3>
    elementType finalTask(seqList const& L);//拓展任务<4>

};

#include"seqlist_functions.h"


