#include"linkedList.h"
#include<cstdlib>
#include<cstdio>

List l;

void task0(){
    if(l.head()){
        l.print();
    }
    else{
        cout<<"链表为空！请先创建链表。\n";
    }
    cin.get();
    cin.get();
}

void task1(){
    l.init();
    cout<<"尾插法创建链表\n";
    l.createList();
    cout<<"创建结果：";
    l.print();
    cin.get();

}
void task2(){
    l.init();
    cout<<"头插法创建链表\n";
    l.createListH();
    cout<<"创建结果：";
    l.print();
    cin.get();

}

void task3(){
    l.destroy();
    cout<<"销毁成功！\n";
    cin.get();
    cin.get();
}

void task4(){
     l.print();
     cout<<"链表长度："<<l.getLength()<<endl;
     cin.get();
     cin.get();
}

void task5(){
    int i;
    l.print();
    elementType x;
    cout<<"输入要获取的元素的序号i：";
    cin>>i;
    if(l.getElement(i,x)){
        cout<<x<<endl;
    }
    cin.get();
    cin.get();
}

void task6(){
    int i;
    elementType x;
    cout<<"插入前: ";
    l.print();
    cout<<"输入位置序号i和插入值x：";
    cin>>i>>x;
    l.insert(i,x);
    cout<<"插入后：";
    l.print();
    cin.get();
    cin.get();
}

void task7(){
    l.print();
    elementType x;
    cout<<"输入要查找的元素值x： ";
    cin>>x;
    if(l.find(x)){
        cout<<"元素值为x的结点地址为：";
        cout<<l.find(x)<<endl;
    }
    cin.get();
    cin.get();

}

void task8(){
    int i;
    cout<<"删除前：";
    l.print();
    cout<<"输入删除的元素序号：";
    cin>>i;
    if(l.remove(i)){
        cout<<"删除后：";
        l.print();
    }
    cin.get();
    cin.get();
}

void task9(){
    elementType x;
    cout<<"插入前：";
    l.print();
    cout<<"输入要插入的元素值x：";
    cin>>x;
    l.insertA(x);
    cout<<"插入后：";
    l.print();
    cin.get();
    cin.get();

}

void task10(){
    l.decomposeOddEven();
    cin.get();
    cin.get();
}

void task11(){
    List L2,L3;
    cout<<"原表L1:";
    l.print();
    cout<<"创建表L2:";
    L2.init();
    L2.createList();
    L3=l.intersect(L2);
    cout<<"表L3:";
    L3.print();
    cin.get();
    cin.get();
    L2.destroy();
    L3.destroy();

}

void task12(){
    cout<<"去重前："<<endl;
    l.print();
    l.unique();
    cout<<"去重后: "<<endl;
    l.print();
    cin.get();
    cin.get();
}

void task13(){
    List L2;
    cout<<"L2未创建，创建表L2:\n";
    L2.init();
    L2.createList();
    cout<<"表L1：";
    l.print();
    cout<<"表L2：";
    L2.print();
    l.merge(L2);
    cout<<"合并后：";
    l.print();
    cin.get();
    cin.get();
}

void task14(){
    List B;
    cout<<"集合B未创建，创建集合B：\n";
    B.init();
    B.createList();
    cout<<"集合A：";
    l.print();
    cout<<"集合B: ";
    B.print();
    cout<<"选择运算：1.C=A∩B   2.C=A∪B    3.C=A-B\n";
    cout<<"          4.A=A∩B   5.A=A∪B    6.A=A-B\n\n";
    char ch=getchar();
    cin.get();
    List C;
    switch(ch){
    case '1':
             cout<<"C=A∩B= ";
             C=l.subIntersectA(B);
             C.print();
             cin.get();
             cin.get();
             C.destroy();
             break;

    case '2':
             cout<<"C=A∪B= ";
             C=l.subMergeA(B);
             C.print();
             cin.get();
             cin.get();
             C.destroy();
             break;
    case '3':
            cout<<"C=A-B= ";
            C=l.subTractionA(B);
            C.print();
            cin.get();
            cin.get();
            C.destroy();
            break;
    case '4':
            cout<<"A=A∩B= ";
            l.subIntersectB(B);
            l.print();
            cin.get();
            cin.get();
            break;
    case '5':
            cout<<"A=A∪B= ";
            l.subMergeB(B);
            l.print();
            cin.get();
            cin.get();
            break;
    case '6':
            cout<<"A=A-B= ";
            l.subTractionB(B);
            l.print();
            cin.get();
            cin.get();
            break;
    default: break;
    }

    B.destroy();

}

void task15(){
    List B;
    cout<<"集合B未创建，创建集合B：\n";
    B.init();
    B.createList();
    cout<<"集合A：";
    l.print();
    cout<<"集合B: ";
    B.print();
    if(l.subsetJudge(B)){
        cout<<"A是B的子集\n";
    }else{
        cout<<"A不是B的子集\n";
    }
    cin.get();
    cin.get();
    B.destroy();
}

void task16(){
    int k;
    l.print();
    cout<<"输入倒数位置k：";
    cin>>k;
    cout<<"该位置数据为：";
    cout<<l.fun2009(k);
    cin.get();
    cin.get();

}

void task17(){
    cout<<"创建序列S2：\n";
    List L2;
    L2.init();
    L2.createList();
    cout<<"中位数为：";
    cout<<l.fun2011(L2,l.getLength());
    cin.get();
    cin.get();
}

int main(){
    while(true){
        int choose;
        cout<<"********************************************************测试菜单******************************************************\n";
        cout<<"0.打印链表\n\n";
        cout<<"1.任务<1>:尾插法创建单链表，打印创建结果。\n\n";
        cout<<"2.任务<2>:头插法创建单链表，打印创建结果。\n\n";
        cout<<"3.任务<3>:销毁单链表。\n\n";
        cout<<"4.任务<4>:求链表长度。\n\n";
        cout<<"5.任务<5>:求单链表中第i个元素（函数），若不存在，报错。\n\n";
        cout<<"6.任务<6>:在第i个结点前插入值为x的结点。\n\n";
        cout<<"7.任务<7>:链表中查找元素值为x的结点，成功返回结点指针，失败报错。\n\n";
        cout<<"8.任务<8>:删除单链表中第i个元素结点。\n\n";
        cout<<"9.任务<9>:在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性。\n\n";
        cout<<"10.任务<10>:将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的单链表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。\n\n";
        cout<<"11.任务<11>:求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中。\n\n";
        cout<<"12.任务<12>:删除递增有序单链表中的重复元素，要求时间性能最好。\n\n";
        cout<<"13.任务<13>:递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并，并使得合并后成为一个集合，合并后用L1的头结点作为头结点，删除L2的头结点，要求时间性能最好。\n\n";
        cout<<"14.拓展任务<1>：（递增有序）单链表表示集合A、B，实现：\n";
        cout<<"              C=A∩B，C=A∪B，C=A-B\n";
        cout<<"              A=A∩B，A=A∪B，A=A-B\n\n";
        cout<<"15.拓展任务<2>: （递增有序）顺序表表示集合A、B，判定A是否B的子集。\n\n";
        cout<<"16.拓展任务<3>\n\n";
        cout<<"17.拓展任务<4>\n\n";
        cout<<"输入序号以测试：";
        cin>>choose;
        switch(choose){
            case 0:   task0();break;
            case 1:   task1();break;
            case 2:   task2();break;
            case 3:   task3();break;
            case 4:   task4();break;
            case 5:   task5();break;
            case 6:   task6();break;
            case 7:   task7();break;
            case 8:   task8();break;
            case 9:   task9();break;
            case 10:  task10();break;
            case 11:  task11();break;
            case 12:  task12();break;
            case 13:  task13();break;
            case 14:  task14();break;
            case 15:  task15();break;
            case 16:  task16();break;
            case 17:  task17();break;
            default: break;
        }
        system("CLS");
    }
    return 0;
}
