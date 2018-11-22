#include"linkedList.h"
#include<cstdlib>
#include<cstdio>

List l;

void task0(){
    if(l.head()){
        l.print();
    }
    else{
        cout<<"����Ϊ�գ����ȴ�������\n";
    }
    cin.get();
    cin.get();
}

void task1(){
    l.init();
    cout<<"β�巨��������\n";
    l.createList();
    cout<<"���������";
    l.print();
    cin.get();

}
void task2(){
    l.init();
    cout<<"ͷ�巨��������\n";
    l.createListH();
    cout<<"���������";
    l.print();
    cin.get();

}

void task3(){
    l.destroy();
    cout<<"���ٳɹ���\n";
    cin.get();
    cin.get();
}

void task4(){
     l.print();
     cout<<"�����ȣ�"<<l.getLength()<<endl;
     cin.get();
     cin.get();
}

void task5(){
    int i;
    l.print();
    elementType x;
    cout<<"����Ҫ��ȡ��Ԫ�ص����i��";
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
    cout<<"����ǰ: ";
    l.print();
    cout<<"����λ�����i�Ͳ���ֵx��";
    cin>>i>>x;
    l.insert(i,x);
    cout<<"�����";
    l.print();
    cin.get();
    cin.get();
}

void task7(){
    l.print();
    elementType x;
    cout<<"����Ҫ���ҵ�Ԫ��ֵx�� ";
    cin>>x;
    if(l.find(x)){
        cout<<"Ԫ��ֵΪx�Ľ���ַΪ��";
        cout<<l.find(x)<<endl;
    }
    cin.get();
    cin.get();

}

void task8(){
    int i;
    cout<<"ɾ��ǰ��";
    l.print();
    cout<<"����ɾ����Ԫ����ţ�";
    cin>>i;
    if(l.remove(i)){
        cout<<"ɾ����";
        l.print();
    }
    cin.get();
    cin.get();
}

void task9(){
    elementType x;
    cout<<"����ǰ��";
    l.print();
    cout<<"����Ҫ�����Ԫ��ֵx��";
    cin>>x;
    l.insertA(x);
    cout<<"�����";
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
    cout<<"ԭ��L1:";
    l.print();
    cout<<"������L2:";
    L2.init();
    L2.createList();
    L3=l.intersect(L2);
    cout<<"��L3:";
    L3.print();
    cin.get();
    cin.get();
    L2.destroy();
    L3.destroy();

}

void task12(){
    cout<<"ȥ��ǰ��"<<endl;
    l.print();
    l.unique();
    cout<<"ȥ�غ�: "<<endl;
    l.print();
    cin.get();
    cin.get();
}

void task13(){
    List L2;
    cout<<"L2δ������������L2:\n";
    L2.init();
    L2.createList();
    cout<<"��L1��";
    l.print();
    cout<<"��L2��";
    L2.print();
    l.merge(L2);
    cout<<"�ϲ���";
    l.print();
    cin.get();
    cin.get();
}

void task14(){
    List B;
    cout<<"����Bδ��������������B��\n";
    B.init();
    B.createList();
    cout<<"����A��";
    l.print();
    cout<<"����B: ";
    B.print();
    cout<<"ѡ�����㣺1.C=A��B   2.C=A��B    3.C=A-B\n";
    cout<<"          4.A=A��B   5.A=A��B    6.A=A-B\n\n";
    char ch=getchar();
    cin.get();
    List C;
    switch(ch){
    case '1':
             cout<<"C=A��B= ";
             C=l.subIntersectA(B);
             C.print();
             cin.get();
             cin.get();
             C.destroy();
             break;

    case '2':
             cout<<"C=A��B= ";
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
            cout<<"A=A��B= ";
            l.subIntersectB(B);
            l.print();
            cin.get();
            cin.get();
            break;
    case '5':
            cout<<"A=A��B= ";
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
    cout<<"����Bδ��������������B��\n";
    B.init();
    B.createList();
    cout<<"����A��";
    l.print();
    cout<<"����B: ";
    B.print();
    if(l.subsetJudge(B)){
        cout<<"A��B���Ӽ�\n";
    }else{
        cout<<"A����B���Ӽ�\n";
    }
    cin.get();
    cin.get();
    B.destroy();
}

void task16(){
    int k;
    l.print();
    cout<<"���뵹��λ��k��";
    cin>>k;
    cout<<"��λ������Ϊ��";
    cout<<l.fun2009(k);
    cin.get();
    cin.get();

}

void task17(){
    cout<<"��������S2��\n";
    List L2;
    L2.init();
    L2.createList();
    cout<<"��λ��Ϊ��";
    cout<<l.fun2011(L2,l.getLength());
    cin.get();
    cin.get();
}

int main(){
    while(true){
        int choose;
        cout<<"********************************************************���Բ˵�******************************************************\n";
        cout<<"0.��ӡ����\n\n";
        cout<<"1.����<1>:β�巨������������ӡ���������\n\n";
        cout<<"2.����<2>:ͷ�巨������������ӡ���������\n\n";
        cout<<"3.����<3>:���ٵ�����\n\n";
        cout<<"4.����<4>:�������ȡ�\n\n";
        cout<<"5.����<5>:�������е�i��Ԫ�أ����������������ڣ�����\n\n";
        cout<<"6.����<6>:�ڵ�i�����ǰ����ֵΪx�Ľ�㡣\n\n";
        cout<<"7.����<7>:�����в���Ԫ��ֵΪx�Ľ�㣬�ɹ����ؽ��ָ�룬ʧ�ܱ���\n\n";
        cout<<"8.����<8>:ɾ���������е�i��Ԫ�ؽ�㡣\n\n";
        cout<<"9.����<9>:��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�\n\n";
        cout<<"10.����<10>:����������е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µĵ������У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������\n\n";
        cout<<"11.����<11>:������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3�С�\n\n";
        cout<<"12.����<12>:ɾ���������������е��ظ�Ԫ�أ�Ҫ��ʱ��������á�\n\n";
        cout<<"13.����<13>:������������L1��L2���������½�㣬����ԭ�����2����кϲ�����ʹ�úϲ����Ϊһ�����ϣ��ϲ�����L1��ͷ�����Ϊͷ��㣬ɾ��L2��ͷ��㣬Ҫ��ʱ��������á�\n\n";
        cout<<"14.��չ����<1>�����������򣩵������ʾ����A��B��ʵ�֣�\n";
        cout<<"              C=A��B��C=A��B��C=A-B\n";
        cout<<"              A=A��B��A=A��B��A=A-B\n\n";
        cout<<"15.��չ����<2>: ����������˳����ʾ����A��B���ж�A�Ƿ�B���Ӽ���\n\n";
        cout<<"16.��չ����<3>\n\n";
        cout<<"17.��չ����<4>\n\n";
        cout<<"��������Բ��ԣ�";
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
