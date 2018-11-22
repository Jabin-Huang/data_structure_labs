#pragma once


void List::merge(List &L2){
    node *p1=L,*p2=L2.L->next;
    while(p1->next&&p2){
        if(p1->next->data==p2->data){
            p1=p1->next;
            node *t=p2->next;
            delete p2;
            p2=t;
        }
        else if(p1->next->data<p2->data){
            p1=p1->next;
        }
        else if(p1->next->data>p2->data){
            node *u=p1->next;
            node *v=p2->next;
            p1->next=p2;
            p1->next->next=u;
            p2=v;
        }
    }
    if(p2) p1->next=p2;
    delete L2.L;
    L2.L=NULL;
}
