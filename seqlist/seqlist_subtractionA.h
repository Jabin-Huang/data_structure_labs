#pragma once

void seqList::subtractionA(seqList const& L){ //A=A-B
    int i=0,j=0,t=0;
    while(i<length){
        if((j>=L.length)||(j<L.length&&data[i]<L.data[j])){
            data[t++]=data[i++];
        }
        else if(j<L.length&&data[i]>L.data[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    length=t;
}
