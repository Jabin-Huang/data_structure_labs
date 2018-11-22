#pragma once

seqList seqList::intersect(seqList const& L){//C=A¡ÉB
    Rank i=0,j=0;
    seqList T;
    while(i<length&&j<L.length){
        if(data[i]<L.data[j]){
            i++;
        }
        else if(data[i]>L.data[j]){
            j++;
        }
        else if(data[i]==L.data[j]){
            T.insert(data[i++]);
        }
    }
    return T;
}
