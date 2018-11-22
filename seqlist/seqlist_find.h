#pragma once

Rank seqList::find(elementType x){  //在顺序表中查找等于x的最后一个元素的位置，若不存在返回-1
    for(int i=length-1;i>-1;i--){
        if(data[i]==x){
            return i+1;
        }
    }
    return -1;
}
