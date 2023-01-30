#include <iostream>
using namespace std;

class A{
public:
    A(int i){
        a=i;
        pa=new int;
        *pa= i;
        cout<<"构造函数"<<endl;
    }

    A(const A& other){
        a=other.a;
        pa=new int(*(other.pa));
         cout<<"拷贝构造"<<endl;
    }

    A(A&& other){
        a=other.a;
        pa=other.pa;
        other.pa=nullptr;
         cout<<"移动构造"<<endl;
    }

    A& operator =(const A& other){
        a=other.a;
        if(pa)delete(pa);
        pa=new int(*(other.pa));
        cout<<"拷贝赋值"<<endl;
        return *this;
    }

        A& operator =(A&& other){
        a=other.a;
        if(pa)delete(pa);
        pa=other.pa;
        other.pa=nullptr;
        cout<<"移动赋值"<<endl;
        return *this;
    }

    ~A(){
        cout<<"析构函数";
        cout<<a<<endl;

        if(pa)delete pa ;
    
         
    }


  
  int a;
  int * pa;



};


int main(){
A a1{1};
A a2=a1;
a2=a1;
a2.a=2;



A a3=move(a1);
a3.a=3;
a3=move(a2);



return 0;
}

 