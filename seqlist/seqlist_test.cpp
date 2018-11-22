#include"seqlist.h"
#include<cstdlib>

void task1(){
    seqList L;
    int n,i;
    elementType x;
    cout<<"输入顺序表长度n:";
    cin>>n;
    cout<<"初始化表：";
    L.randInit(n);
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<"输入元素序号i（以-1结束）：";
    while(cin>>i&&i!=-1){
        if(L.getElement(i,x)){
            cout<<x<<endl;
        }
        cout<<"输入元素序号i（以-1结束）：";
    }
    cin.get();
    cin.get();
}

void task2(){
    seqList L;
    int n,i;
    elementType x;
    cout<<"输入顺序表长度n:";
    cin>>n;
    L.randInit(n);
    cout<<"初始化表: ";
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<"输入元素序号i和插入值x（以i=-1结束）：";
    while(cin>>i&&i!=-1){
        cin>>x;
        if(L.insert(i,x)){
            cout<<"插入成功!"<<endl;
            cout<<"插入后：";
            for(Rank j=1;j<=L.getLength();j++){
                L.getElement(j,x);
                cout<<x<<' ';
            }
            cout<<endl;
        }
        cout<<"输入元素序号i和插入值x（以i=-1结束）：";
    }
    cin.get();
    cin.get();
}

void task3(){
    seqList L;
    int n,i;
    elementType x;
    cout<<"输入顺序表长度n:";
    cin>>n;
    L.randInit(n);
    cout<<"初始化表: ";
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<"输入删除元素序号i（以-1结束）：";
    while(cin>>i&&i!=-1){
        if(L.remove(i)){
            cout<<"删除成功！"<<endl;
            cout<<"删除后：";
            for(Rank j=1;j<=L.getLength();j++){
                L.getElement(j,x);
                cout<<x<<' ';
            }
            cout<<endl;
        }
        cout<<"输入删除元素序号i（以-1结束）：";
    }
    cin.get();
    cin.get();
}

void task4(){
    seqList L;
    int j=0;
    elementType x;
    cout<<"初始化表: ";
    elementType ex[]={10,20,30,40,50,60,70,80,90,100,-1};
    while(ex[j]!=-1){
        L.insert(ex[j++]);
    }
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<"输入插入值x（以i=-1结束）：";
    while(cin>>x&&x!=-1){
        L.insertA(x);
        cout<<"插入后：";
        for(Rank j=1;j<=L.getLength();j++){
            L.getElement(j,x);
            cout<<x<<' ';
        }
        cout<<endl;
        cout<<"输入插入值x（以i=-1结束）：";
    }
    cin.get();
    cin.get();
}

void task5(){
    seqList L;
    elementType x;
    cout<<"输入测试数据(以-1结束)：\n";
    while(cin>>x&&x!=-1){
        L.insert(x);
    }
    L.decompose_odd_even();
    cin.get();
    cin.get();
}

void task6(){
    elementType x;
    seqList L1,L2,L3;
    cout<<"输入表L1（以-1结束）： ";
    while(cin>>x&&x!=-1){
        L1.insert(x);
    }
    cout<<"输入表L2（以-1结束）： ";
    while(cin>>x&&x!=-1){
        L2.insert(x);
    }
    L3=L1.intersect(L2);
    cout<<"L3: ";
    for(Rank j=1;j<=L3.getLength();j++){
        L3.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cin.get();
    cin.get();
}

void task7(){
    seqList L;
    elementType x;
    cout<<"输入测试数据（以-1结束）： ";
    while(cin>>x&&x!=-1){
        L.insert(x);
    }
    int cnt=L.unique();
    cout<<"去重后：\n";
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<"移动次数： "<<cnt<<endl;
    cin.get();
    cin.get();
}

void task8(){
    seqList L1,L2;
    elementType x;
    cout<<"输入L1元素（以-1结束）：";
    while(cin>>x&&x!=-1){
        L1.insert(x);
    }
    cout<<"输入L2元素（以-1结束）：";
    while(cin>>x&&x!=-1){
        L2.insert(x);
    }
    L1.mergeToSet(L2);
    cout<<"合并后成为一个集合：";
    for(Rank i=1;i<=L1.getLength();i++){
        L1.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cin.get();
    cin.get();
}
void task9(){
    seqList A,B,C;
    elementType x;
    cout<<"输入集合A(以-1结束):";
    while(cin>>x&&x!=-1){
        A.insert(x);
    }
    cout<<"输入集合B（以-1结束）:";
    while(cin>>x&&x!=-1){
        B.insert(x);
    }
    C=A.intersect(B);
    cout<<"C=A∩B=";
    for(Rank i=1;i<=C.getLength();i++){
        C.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    C=A._union(B);
    cout<<"C=A∪B=";
    for(Rank i=1;i<=C.getLength();i++){
        C.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    C=A.subtraction(B);
    cout<<"C=A-B=";
    for(Rank i=1;i<=C.getLength();i++){
        C.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    seqList t=A;
    A.intersectA(B);
    cout<<"A=A∩B=";
    for(Rank i=1;i<=A.getLength();i++){
        A.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    A=t; //将A还原
    A._unionA(B);
    cout<<"A=A∪B=";
    for(Rank i=1;i<=A.getLength();i++){
        A.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    A=t; //将A还原
    A.subtractionA(B);
    cout<<"A=A-B=";
    for(Rank i=1;i<=A.getLength();i++){
        A.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cin.get();
    cin.get();

}
void task10(){
    seqList A,B;
    elementType x;
    cout<<"输入集合A(以-1结束):";
    while(cin>>x&&x!=-1){
        A.insert(x);
    }
    cout<<"输入集合B（以-1结束）:";
    while(cin>>x&&x!=-1){
        B.insert(x);
    }
    if(A.subSetJudge(B)){
        cout<<"A是B的子集\n";
    }
    else{
        cout<<"A不是B的子集\n";
    }
    cin.get();
    cin.get();
}
void task11(){
    seqList L1,L2;
    elementType x;
    cout<<"输入表L1(以-1结束):";
    while(cin>>x&&x!=-1){
        L1.insert(x);
    }
    cout<<"输入表L2（以-1结束）:";
    while(cin>>x&&x!=-1){
        L2.insert(x);
    }
    elementType ans=L1.finalTask(L2);
    cout<<"合并后的中位数：";
    cout<<ans<<endl;
    cin.get();
    cin.get();
}

int main(){
    while(true){
        int choose;
        cout<<"********************************************************测试菜单******************************************************\n";
        cout<<"1.任务<1>:求顺序表中第i个元素（函数），若不存在，报错。\n\n";
        cout<<"2.任务<2>:在第i个结点前插入值为x的结点。\n\n";
        cout<<"3.任务<3>:删除顺序表中第i个元素结点。\n\n";
        cout<<"4.任务<4>:在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性。\n\n";
        cout<<"5.任务<5>:将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。\n\n";
        cout<<"6.任务<6>:求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。\n\n";
        cout<<"7.任务<7>:删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好。\n\n";
        cout<<"8.拓展任务<1>:递增有序顺序表L1、L2，对2表进行合并，并使得合并后成为一个集合，集合的元素放回L1表中保存，要求时间性能最好。\n\n";
        cout<<"9.拓展任务<2>:（递增有序）顺序表表示集合A、B，实现：\n";
        cout<<"              C=A∩B，C=A∪B，C=A-B\n";
        cout<<"              A=A∩B，A=A∪B，A=A-B\n\n";
        cout<<"10.拓展任务<3>:（递增有序）顺序表表示集合A、B，判定A是否B的子集。\n\n";
        cout<<"11.拓展任务<4>\n\n";
        cout<<endl;
        cout<<"输入序号以测试：";
        cin>>choose;
        switch(choose){
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
        }
        system("CLS");
    }
    return 0;
}


