#pragma once

int List::getLength(){ //获取长度
    node *p=L;
    int len=0;
    while(p->next){
        len++;
        p=p->next;
    }
    length=len;
    return len;
}
