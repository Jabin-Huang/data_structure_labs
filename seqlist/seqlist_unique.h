#pragma once

int seqList::unique(){
    int cnt=0;
    if(length<=1) return 0;
    int j=0;
    for(int i=1;i<length;i++){
        if(data[i]!=data[j]){
            data[++j]=data[i];
            if(i!=j) cnt++;
        }
    }
    length=j+1;
    return cnt;
}
