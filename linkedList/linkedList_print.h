#pragma once

void List::print(){ //��ӡ
    node *p=L->next;
    while(p!=NULL){
       cout<<p->data<<' ';
       p=p->next;
    }
    cout<<endl;
}
