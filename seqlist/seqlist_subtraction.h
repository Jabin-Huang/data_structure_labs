#pragma once

seqList seqList::subtraction(seqList const& L){ //C=A-B
    int i=0,j=0;
    seqList T;
    while(i<length){
        if((j>=L.length)||(j<L.length&&data[i]<L.data[j])){
            T.insert(data[i]);
            i++;
        }
        else if(j<L.length&&data[i]>L.data[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    return T;
}
