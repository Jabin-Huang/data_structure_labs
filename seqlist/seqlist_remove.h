#pragma once

bool seqList::remove(Rank i){
    if(i>length||i<1){
        cout<<"��Ŵ���\n";
        return false; //��ŷǷ�������false
    }
    for(int j=i-1;j<length-1;j++){
        data[j]=data[j+1];
    }
    length--;
    return true; //ɾ���ɹ�������true
}
