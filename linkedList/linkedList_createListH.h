#pragma once

void List::createListH(){ //头插法创建
    node *p=L;
    elementType x;
    cout<<"输入元素（以-1结束）：";
    while(cin>>x&&x!=-1){
        node *u=new node;
        u->data=x;
        u->next=p->next;
        p->next=u;
        length++;
    }
    cin.get();
}
