#pragma once

node* List::find(elementType x){
    node *p=L->next;
    while(p!=NULL&&p->data!=x){
        p=p->next;
    }
    if(p==NULL){
        cout<<"������Ԫ��x!\n";
        return NULL;
    }
    else return p;
}
