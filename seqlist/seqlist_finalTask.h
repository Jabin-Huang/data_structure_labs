#pragma once

elementType seqList::finalTask(seqList const& L){
    int i=0,j=0,t=0;
    while(t<length){ //�ϲ�����ԭlength��λ�þ�����λ����λ��
        if(data[i]<=L.data[j]){
            data[t++]=data[i++];
        }
        else if(data[i]>L.data[j]){
            data[t++]=data[j++];
        }
    }
    length=t;
    return data[t-1];
}// O��|L|��
