#pragma once

seqList seqList::_union(seqList const&L){ //C=A¡ÈB
    int i=0,j=0;
    seqList T;
    while(i<length||j<L.length){
        if((j>=L.length)||(i<length&&data[i]<L.data[j])){
            T.insert(data[i]);
            i++;
        }
        else if((i>=length)||(j<length&&data[i]>L.data[j])){
            T.insert(L.data[j]);
            j++;
        }
        else {
            T.insert(data[i]);
            i++;
            j++;
        }
    }
    return T;
}
