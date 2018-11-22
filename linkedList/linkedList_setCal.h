#pragma once

List List::subMergeA(List const& B){//C=A¡ÈB
        node *p1=L->next,*p2=B.L->next;
        List C;
        C.init();
        while(p1&&p2){
            if(p1->data<p2->data){
                C.insert(p1->data);
                p1=p1->next;
            }
            else if(p1->data>p2->data){
                C.insert(p2->data);
                p2=p2->next;
            }
            else if(p1->data==p2->data){
                C.insert(p1->data);
                p1=p1->next;
                p2=p2->next;
            }
        }
        while(p1){
            C.insert(p1->data);
            p1=p1->next;
        }
        while(p2){
            C.insert(p2->data);
            p2=p2->next;
        }
        return C;
}

void List::subMergeB(List & B){//A=A¡ÈB
   merge(B);
}

List List::subIntersectA(List const& B){//C=A¡ÉB
    return intersect(B);
}

void List::subIntersectB(List const& B){//A=A¡ÉB
    node *p1=L,*p2=B.L->next;
    while(p1->next&&p2){
        if(p1->next->data<p2->data){
            node *u=p1->next;
            p1->next=p1->next->next;
            delete u;
        }
        else if(p1->next->data==p2->data){
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->next->data>p2->data){
            p2=p2->next;
        }
    }
    if(p1->next) p1->next=NULL;

}

List List::subTractionA(List const& B){//C=A-B
    node *p1=L->next,*p2=B.L->next;
    List C;
    C.init();
    while(p1&&p2){
        if(p1->data<p2->data){
            C.insert(p1->data);
            p1=p1->next;
        }
        else if(p1->data==p2->data){
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data>p2->data){
            p2=p2->next;
        }
    }
    while(p1){
        C.insert(p1->data);
        p1=p1->next;
    }
    return C;
}

void List::subTractionB(List const& B){//A=A-B
    node *p1=L->next,*p2=B.L->next;
    int i=1;
    while(p1&&p2){
        if(p1->data<p2->data){
            p1=p1->next;
            i++;
        }
        else if(p1->data==p2->data){
            p1=p1->next;
            remove(i);
        }
        else if(p1->data>p2->data){
            p2=p2->next;
        }
    }
}
