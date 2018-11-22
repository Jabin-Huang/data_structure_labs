#pragma once

bool List::subsetJudge(List const& B){
    node *p1=L->next,*p2=B.L->next;
    while(p1&&p2){
        if(p1->data<p2->data){
            return false;
        }
        else if(p1->data==p2->data){
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->data>p2->data){
            p2=p2->next;
        }
    }
    if(p1) return false;
    return true;
}
