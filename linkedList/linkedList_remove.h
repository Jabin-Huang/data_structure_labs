#pragma once

bool List::remove(int i){ //ɾ����i��Ԫ��
    node *p=L;
    int j=0;
    while(j!=i-1&&p!=NULL){
        p=p->next;
        j++;
    }
    if(p==NULL){
        cout<<"��Ŵ���\n";
        return false;
    }
    node *u=p->next;
    p->next=u->next;
    delete u;
    length--;
    return true;
}


