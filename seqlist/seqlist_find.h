#pragma once

Rank seqList::find(elementType x){  //��˳����в��ҵ���x�����һ��Ԫ�ص�λ�ã��������ڷ���-1
    for(int i=length-1;i>-1;i--){
        if(data[i]==x){
            return i+1;
        }
    }
    return -1;
}
