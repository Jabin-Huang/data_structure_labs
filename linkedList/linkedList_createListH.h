#pragma once

void List::createListH(){ //ͷ�巨����
    node *p=L;
    elementType x;
    cout<<"����Ԫ�أ���-1��������";
    while(cin>>x&&x!=-1){
        node *u=new node;
        u->data=x;
        u->next=p->next;
        p->next=u;
        length++;
    }
    cin.get();
}
