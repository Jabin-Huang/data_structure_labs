#pragma once

bool List::getElement(int i,elementType &x){
    node *p=L->next;
    int j=1;
    while(j!=i&&p!=NULL){
        p=p->next;
        j++;
    }
    if(p!=NULL) {
        x=p->data;
        return true;
    }
    else{
        cout<<"ĞòºÅ´íÎó£¡\n";
        return false;
    }

}
