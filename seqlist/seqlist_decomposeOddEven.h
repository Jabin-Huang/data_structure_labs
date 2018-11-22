#pragma once

void seqList::decompose_odd_even(){
    seqList odd_L,even_L;
    for(int i=0;i<length;i++){
        if(data[i]%2){ //判断奇偶
            odd_L.insert(data[i]);
        }
        else{
            even_L.insert(data[i]);
        }
    }
    cout<<"原表：";
    for(int i=0;i<length;i++){
        cout<<data[i]<<' ';
    }
    cout<<endl;
    cout<<"奇数项：";
    for(int i=0;i<odd_L.length;i++){
        cout<<odd_L.data[i]<<' ';
    }
    cout<<endl;
    cout<<"偶数项：";
    for(int i=0;i<even_L.length;i++){
        cout<<even_L.data[i]<<' ';
    }
    cout<<endl;

}
