#pragma once

//����˳���Ķ��ֲ���

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
    return --lo+1; //���ز�����x�����һ��Ԫ�����
}
