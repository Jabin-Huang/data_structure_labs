#pragma once

bool seqList::remove(Rank i){
    if(i>length||i<1){
        cout<<"ÐòºÅ´íÎó£¡\n";
        return false; //ÐòºÅ·Ç·¨£¬·µ»Øfalse
    }
    for(int j=i-1;j<length-1;j++){
        data[j]=data[j+1];
    }
    length--;
    return true; //É¾³ý³É¹¦£¬·µ»Øtrue
}
