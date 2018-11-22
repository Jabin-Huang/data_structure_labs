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
    cout<<"原表：";
    print();
    cout<<"奇数项表：";
    odd.print();
    cout<<"偶数项表：";
    even.print();
    odd.destroy();
    even.destroy();
}
