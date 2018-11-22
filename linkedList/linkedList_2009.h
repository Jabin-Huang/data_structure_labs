#pragma once


elementType List::fun2009(int k){
    node *p=L,*q=L;
    int i=0;
    while(p->next&&i<k-1){
        p=p->next;
        i++;
    }
    while(p->next){
        p=p->next;
        q=q->next;
    }
    return q->data;
}
