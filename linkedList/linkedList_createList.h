#pragma once

void List::createList(){ //β�巨����
    node *p=L;
    elementType x;
    cout<<"����Ԫ�أ���-1��������";
    while(cin>>x&&x!=-1){
        while(p->next!=NULL){
            p=p->next;
        }
        node *u=new node;
        u->data=x;
        u->next=NULL;
        p->next=u;
        length++;
    }
    cin.get();
}
