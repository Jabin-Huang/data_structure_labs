#pragma once

void List::destroy(){ //����
    node *p=L;
    node *q; //��ʱ�������洢��һ��delete����ĵ�ַ
    while(p!=NULL){
        q=p->next;
        delete p;
        p=q;
    }
    L=NULL;

}
