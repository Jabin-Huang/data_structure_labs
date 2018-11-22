#pragma once

bool List::insert(int i,elementType x){
    node *p=L;
    int k=0;
    while(k!=i-1&&p!=NULL){
        p=p->next;
        k++;
    } //此时p指向第i-1个结点
    if(p==NULL) {
        cout<<"序号错误!\n";
        return false;
    }
    else{
        node *u=new node;
        u->data=x;
        u->next=p->next;
        p->next=u;
        return true;
    }
}
void List::insert(elementType x){
    insert(getLength()+1,x);
}
