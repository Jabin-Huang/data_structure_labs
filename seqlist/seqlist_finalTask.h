#pragma once

elementType seqList::finalTask(seqList const& L){
    int i=0,j=0,t=0;
    while(t<length){ //合并后在原length的位置就是中位数的位置
        if(data[i]<=L.data[j]){
            data[t++]=data[i++];
        }
        else if(data[i]>L.data[j]){
            data[t++]=data[j++];
        }
    }
    length=t;
    return data[t-1];
}// O（|L|）
