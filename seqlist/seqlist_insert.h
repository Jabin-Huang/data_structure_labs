#pragma once

bool seqList::insert(Rank i, elementType x){
    if(i<1||i>length+1){
        cout<<"ÐòºÅ´íÎó!\n";
        return false;
    }
    for(int j=length-1;j>i-2;j--){
        data[j+1]=data[j];
    }
    data[i-1]=x;
    length++;
    return true;
}

void seqList::insert(elementType x){
    insert(length+1,x);
}
