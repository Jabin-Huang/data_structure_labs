#pragma once

void List::createList(){ //尾插法创建
    node *p=L;
    elementType x;
    cout<<"输入元素（以-1结束）：";
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
