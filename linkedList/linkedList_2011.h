#pragma once

List::fun2011(List const &L2,int Len){
    node *p1=L->next,*p2=L2.L->next;
    int i=0;
    while(p1&&p2){
        if(p1->data==p2->data){
            i+=2;
            if(i>=Len) return p1->data;
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data<p2->data){

            i++;
            if(i==Len) return p1->data;
            p1=p1->next;
        }
        else if(p1->data>p2->data){

            i++;
            if(i==Len) return p2->data;
            p2=p2->next;
        }
    }

}
