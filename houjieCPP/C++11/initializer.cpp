#include<iostream>
#include<initializer_list>
using namespace std;
class p
{
    public:
    p(int a,int b)
    {
        cout<<"p=(int,int),a="<<a<<",b="<<b<<endl;

    }
    p(initializer_list<int> initlist)
    {
        cout<<"p(initlizer_list<int>),values=";
        for(auto i:initlist)
          cout<<i<<' ';
          cout<<endl;

    }
};
struct Complex
{
    int real,imag;
    explicit  Complex(int re,int im=0):real(re),imag(im)
    {}
    Complex operator+(const Complex& x)
    {
        return Complex(real+x.real,imag+x.imag);
    }
};

int main()
{
    p s(55,12);
    p q{45,22};
    p r{75,88,66,96};
    p g={56,46};
    Complex c1(3,6);
    Complex c2=c1+4;
    cout<<c2.imag<<" ,"<<c2.real;
    system("pause");
}