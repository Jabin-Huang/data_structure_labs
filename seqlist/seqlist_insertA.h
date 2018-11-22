#pragma once

void seqList::insertA(elementType x){
    Rank i=search(x);
    insert(i+1,x);
}
