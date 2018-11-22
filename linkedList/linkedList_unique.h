#pragma once


void List::unique(){
    node *p=L->next;
    int i=2;
    while(p){
        while(p->next&&p->next->data==p->data){
            remove(i);
        }
        i++;
        p=p->next;
    }
}
