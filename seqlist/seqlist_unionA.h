#pragma once

void seqList::_unionA(seqList const&L){ //A=A∪B
    int i=0,j=0,t=0;
    seqList T=*this; //临时变量，存储A的副本，防止A元素被覆盖导致信息丢失
    while(i<length||j<L.length){
        if((j>=L.length)||(i<length&&T.data[i]<L.data[j])){
            data[t++]=T.data[i++];
        }
        else if((i>=length)||(j<L.length&&T.data[i]>L.data[j])){
            data[t++]=L.data[j++];
        }
        else {
            data[t++]=T.data[i++];
            j++;
        }
    }
    length=t;
}
