#pragma once

int List::getLength(){ //��ȡ����
    node *p=L;
    int len=0;
    while(p->next){
        len++;
        p=p->next;
    }
    length=len;
    return len;
}
