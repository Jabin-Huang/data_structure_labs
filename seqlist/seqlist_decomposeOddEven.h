#pragma once

void seqList::decompose_odd_even(){
    seqList odd_L,even_L;
    for(int i=0;i<length;i++){
        if(data[i]%2){ //�ж���ż
            odd_L.insert(data[i]);
        }
        else{
            even_L.insert(data[i]);
        }
    }
    cout<<"ԭ��";
    for(int i=0;i<length;i++){
        cout<<data[i]<<' ';
    }
    cout<<endl;
    cout<<"�����";
    for(int i=0;i<odd_L.length;i++){
        cout<<odd_L.data[i]<<' ';
    }
    cout<<endl;
    cout<<"ż���";
    for(int i=0;i<even_L.length;i++){
        cout<<even_L.data[i]<<' ';
    }
    cout<<endl;

}
