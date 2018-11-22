#pragma once

//有序顺序表的二分查找

Rank seqList::search(elementType x){
    int lo=0,hi=length;
    while(hi>lo){
        Rank mi=(lo+hi)>>1;
        if(data[mi]>x){
            hi=mi;
        }
        else{
            lo=mi+1;
        }
    }
    return --lo+1; //返回不大于x的最后一个元素序号
}
