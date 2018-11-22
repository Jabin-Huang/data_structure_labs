#include"seqlist.h"
#include<cstdlib>

void task1(){
    seqList L;
    int n,i;
    elementType x;
    cout<<"����˳�����n:";
    cin>>n;
    cout<<"��ʼ����";
    L.randInit(n);
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<"����Ԫ�����i����-1��������";
    while(cin>>i&&i!=-1){
        if(L.getElement(i,x)){
            cout<<x<<endl;
        }
        cout<<"����Ԫ�����i����-1��������";
    }
    cin.get();
    cin.get();
}

void task2(){
    seqList L;
    int n,i;
    elementType x;
    cout<<"����˳�����n:";
    cin>>n;
    L.randInit(n);
    cout<<"��ʼ����: ";
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<"����Ԫ�����i�Ͳ���ֵx����i=-1��������";
    while(cin>>i&&i!=-1){
        cin>>x;
        if(L.insert(i,x)){
            cout<<"����ɹ�!"<<endl;
            cout<<"�����";
            for(Rank j=1;j<=L.getLength();j++){
                L.getElement(j,x);
                cout<<x<<' ';
            }
            cout<<endl;
        }
        cout<<"����Ԫ�����i�Ͳ���ֵx����i=-1��������";
    }
    cin.get();
    cin.get();
}

void task3(){
    seqList L;
    int n,i;
    elementType x;
    cout<<"����˳�����n:";
    cin>>n;
    L.randInit(n);
    cout<<"��ʼ����: ";
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<"����ɾ��Ԫ�����i����-1��������";
    while(cin>>i&&i!=-1){
        if(L.remove(i)){
            cout<<"ɾ���ɹ���"<<endl;
            cout<<"ɾ����";
            for(Rank j=1;j<=L.getLength();j++){
                L.getElement(j,x);
                cout<<x<<' ';
            }
            cout<<endl;
        }
        cout<<"����ɾ��Ԫ�����i����-1��������";
    }
    cin.get();
    cin.get();
}

void task4(){
    seqList L;
    int j=0;
    elementType x;
    cout<<"��ʼ����: ";
    elementType ex[]={10,20,30,40,50,60,70,80,90,100,-1};
    while(ex[j]!=-1){
        L.insert(ex[j++]);
    }
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<"�������ֵx����i=-1��������";
    while(cin>>x&&x!=-1){
        L.insertA(x);
        cout<<"�����";
        for(Rank j=1;j<=L.getLength();j++){
            L.getElement(j,x);
            cout<<x<<' ';
        }
        cout<<endl;
        cout<<"�������ֵx����i=-1��������";
    }
    cin.get();
    cin.get();
}

void task5(){
    seqList L;
    elementType x;
    cout<<"�����������(��-1����)��\n";
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
    cout<<"�����L1����-1�������� ";
    while(cin>>x&&x!=-1){
        L1.insert(x);
    }
    cout<<"�����L2����-1�������� ";
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
    cout<<"����������ݣ���-1�������� ";
    while(cin>>x&&x!=-1){
        L.insert(x);
    }
    int cnt=L.unique();
    cout<<"ȥ�غ�\n";
    for(Rank j=1;j<=L.getLength();j++){
        L.getElement(j,x);
        cout<<x<<' ';
    }
    cout<<"�ƶ������� "<<cnt<<endl;
    cin.get();
    cin.get();
}

void task8(){
    seqList L1,L2;
    elementType x;
    cout<<"����L1Ԫ�أ���-1��������";
    while(cin>>x&&x!=-1){
        L1.insert(x);
    }
    cout<<"����L2Ԫ�أ���-1��������";
    while(cin>>x&&x!=-1){
        L2.insert(x);
    }
    L1.mergeToSet(L2);
    cout<<"�ϲ����Ϊһ�����ϣ�";
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
    cout<<"���뼯��A(��-1����):";
    while(cin>>x&&x!=-1){
        A.insert(x);
    }
    cout<<"���뼯��B����-1������:";
    while(cin>>x&&x!=-1){
        B.insert(x);
    }
    C=A.intersect(B);
    cout<<"C=A��B=";
    for(Rank i=1;i<=C.getLength();i++){
        C.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    C=A._union(B);
    cout<<"C=A��B=";
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
    cout<<"A=A��B=";
    for(Rank i=1;i<=A.getLength();i++){
        A.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    A=t; //��A��ԭ
    A._unionA(B);
    cout<<"A=A��B=";
    for(Rank i=1;i<=A.getLength();i++){
        A.getElement(i,x);
        cout<<x<<' ';
    }
    cout<<endl;
    A=t; //��A��ԭ
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
    cout<<"���뼯��A(��-1����):";
    while(cin>>x&&x!=-1){
        A.insert(x);
    }
    cout<<"���뼯��B����-1������:";
    while(cin>>x&&x!=-1){
        B.insert(x);
    }
    if(A.subSetJudge(B)){
        cout<<"A��B���Ӽ�\n";
    }
    else{
        cout<<"A����B���Ӽ�\n";
    }
    cin.get();
    cin.get();
}
void task11(){
    seqList L1,L2;
    elementType x;
    cout<<"�����L1(��-1����):";
    while(cin>>x&&x!=-1){
        L1.insert(x);
    }
    cout<<"�����L2����-1������:";
    while(cin>>x&&x!=-1){
        L2.insert(x);
    }
    elementType ans=L1.finalTask(L2);
    cout<<"�ϲ������λ����";
    cout<<ans<<endl;
    cin.get();
    cin.get();
}

int main(){
    while(true){
        int choose;
        cout<<"********************************************************���Բ˵�******************************************************\n";
        cout<<"1.����<1>:��˳����е�i��Ԫ�أ����������������ڣ�����\n\n";
        cout<<"2.����<2>:�ڵ�i�����ǰ����ֵΪx�Ľ�㡣\n\n";
        cout<<"3.����<3>:ɾ��˳����е�i��Ԫ�ؽ�㡣\n\n";
        cout<<"4.����<4>:��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�\n\n";
        cout<<"5.����<5>:��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳����У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������\n\n";
        cout<<"6.����<6>:��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�\n\n";
        cout<<"7.����<7>:ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ��������á�\n\n";
        cout<<"8.��չ����<1>:��������˳���L1��L2����2����кϲ�����ʹ�úϲ����Ϊһ�����ϣ����ϵ�Ԫ�طŻ�L1���б��棬Ҫ��ʱ��������á�\n\n";
        cout<<"9.��չ����<2>:����������˳����ʾ����A��B��ʵ�֣�\n";
        cout<<"              C=A��B��C=A��B��C=A-B\n";
        cout<<"              A=A��B��A=A��B��A=A-B\n\n";
        cout<<"10.��չ����<3>:����������˳����ʾ����A��B���ж�A�Ƿ�B���Ӽ���\n\n";
        cout<<"11.��չ����<4>\n\n";
        cout<<endl;
        cout<<"��������Բ��ԣ�";
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


