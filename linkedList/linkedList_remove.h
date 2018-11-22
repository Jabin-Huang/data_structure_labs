#pragma once

bool List::remove(int i){ //É¾³ýµÚi¸öÔªËØ
    node *p=L;
    int j=0;
    while(j!=i-1&&p!=NULL){
        p=p->next;
        j++;
    }
    if(p==NULL){
        cout<<"ÐòºÅ´íÎó£¡\n";
        return false;
    }
    node *u=p->next;
    p->next=u->next;
    delete u;
    length--;
    return true;
}


