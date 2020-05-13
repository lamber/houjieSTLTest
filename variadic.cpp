#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;

void print()
{}
template<typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
  cout<<firstArg<<endl;
  print(args...);
}
int main()
{
    print(7.5,"hello",bitset<16>(377),42);
    cout<<max({string("dfd"),string("wefd"),string("bfd"),string("oifd")})<<endl;
    for(int i:{54,55,45,78,65,69,465,645,897,987,351,654})
      cout<<i<<",";
    system("pause");
}