#pragma once

void List::destroy(){ //销毁
    node *p=L;
    node *q; //临时变量，存储下一个delete对象的地址
    while(p!=NULL){
        q=p->next;
        delete p;
        p=q;
    }
    L=NULL;

}
