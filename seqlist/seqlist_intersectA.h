#pragma once

void seqList::intersectA(seqList const& L){//A=A¡ÉB
    int i=0,j=0,t=0;
    while(i<length&&j<L.length){
        if(data[i]<L.data[j]){
            i++;
        }
        else if(data[i]>L.data[j]){
            j++;
        }
        else if(data[i]==L.data[j]){
            data[t++]=data[i++];
        }
    }
    length=t;
}
