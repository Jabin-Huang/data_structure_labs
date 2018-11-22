#pragma once

List List::intersect(List const &L2){
    node *p1=L->next,*p2=L2.L->next;
    List  L3;
    L3.init();
    while(p1&&p2){
        if(p1->data<p2->data){
            p1=p1->next;
        }
        else if(p1->data==p2->data){
            L3.insert(p1->data);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data>p2->data){
            p2=p2->next;
        }
    }
    return L3;
}
