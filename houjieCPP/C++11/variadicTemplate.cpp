#include<iostream>
#include<bitset>
using namespace std;

void print()
{
}
template<typename T,typename... Types>
void print(const T& firstArg,const Types&...args)
{
    cout<<firstArg<<endl;
    print(args...);
}
int main()
{
    print(2.4,"hello world",bitset<16>(344),43);
    system("pause");
}