#pragma once

void List::decomposeOddEven(){
    node *p=L->next;
    List odd,even;
    odd.init();
    even.init();
    while(p){
        if(p->data%2){
            odd.insert(p->data);
        }
        else{
            even.insert(p->data);
        }
        p=p->next;
    }
    cout<<"ԭ��";
    print();
    cout<<"�������";
    odd.print();
    cout<<"ż�����";
    even.print();
    odd.destroy();
    even.destroy();
}
