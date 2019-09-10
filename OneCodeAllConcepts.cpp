//  By Alkesh Shah

#include <iostream>
using namespace std;

class A
{
    protected:
    int a1,a2;
    public:
    A(){ cout << "This is default constructor of A\n"; }
    A(int w, int x):a1(w),a2(x){ cout << "This is parameterised constructor of A\n"; }
};

class B: virtual public A
{
    protected:
    int b;
    public:
    B(){ cout << "This is default constructor of B\n"; }
    B(int w,int x, int y):A(w,x),b(y){ cout << "This is parameterised constructor of B\n"; }
};

class C: virtual public A
{
    protected:
    int c;
    public:
    C(){ cout << "This is default constructor of C\n"; }
    C(int w,int x,int y):A(w,x),c(y){ cout << "This is parameterised constructor of C\n"; }
};

class D: public B, public C
{
    protected:
    int d;
    public:
    D(){ cout << "This is default constructor of D\n"; }
    D(int w,int x, int y, int z):C(w,x,y),B(w,x,y),A(w,x),d(z){ cout << "This is parameterised constructor of C\n"; }
    D operator+(D &obj)
    {
        D result;
        result.a1 = a1 + obj.a1;
        result.a2 = a2 + obj.a2;
        result.b = b + obj.b;
        result.c = c + obj.c;
        result.d = d + obj.d;
        
        return result;
    }
    void showData()
    {
        cout << "For Class-A\t:" << "a1 = " << a1 << ", a2 = " << a2 << endl;
        cout << "For Class-B\t:" << "b = " << b << endl;
        cout << "For Class-C\t:" << "c = " << c << endl;
        cout << "For Class-D\t:" << "d = " << d << endl;
    }
};

int main()
{
    D o1(1,2,3,4);
    o1.showData();
    D o2(10,20,30,40);
    o2.showData();
    
    D o3 = o1 + o2;
    o3.showData();
    
    return 0;
}
