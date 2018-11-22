#pragma once

#include<cstdlib>

void seqList::randInit(int n){
    for(int i=0;i<n;i++){
        insert(rand()%100);
    }
}
