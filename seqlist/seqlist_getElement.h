#pragma once

bool seqList::getElement(Rank i,elementType& x){
    if(i>length||i<1){
        cout<<"ÐòºÅ´íÎó£¡\n";
        return false;
    }
    x=data[i-1];
    return true;
}



