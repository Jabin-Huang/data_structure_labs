#pragma once

bool seqList::subSetJudge(seqList const&L){
    int i=0,j=0;
    while(i<length){
        if(data[i]<L.data[j]){
            return false;
        }
        else if(data[i]>L.data[j]){
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    return true;
}
