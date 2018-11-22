#pragma once

void seqList::mergeToSet(seqList const& L){
    int i=0,j=0;
    seqList temp;
    while(i<length&&j<L.length){
        if(data[i]<=L.data[j]){
            temp.insert(data[i]);
            i++;
        }
        else if(data[i]>L.data[j]){
            temp.insert(L.data[j]);
            j++;
        }
    }
    if(i<length) while(i<length) temp.insert(data[i++]);
    if(j<L.length) while(j<L.length) temp.insert(data[j++]);
    temp.unique();
    *this=temp;
}
