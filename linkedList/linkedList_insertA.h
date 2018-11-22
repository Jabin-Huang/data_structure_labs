#pragma once

void List::insertA(elementType x){
    node *p=L;
    while(p->next!=NULL&&p->next->data<=x){
        p=p->next;
    }
    node *u=new node;
    u->data=x;
    u->next=p->next;
    p->next=u;
}
