#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void lamda()
{
    vector<int> vi{65,6,48,69,99,156,18,1635,748,4,35,23,54,456};
    int x=20;
    int y=100;
    vi.erase(remove_if(vi.begin(),
           vi.end(),
           [x,y](int n){return x<n&&n<y;}));
           for(auto i:vi)
             cout<<i<<",";
           cout<<endl;
}

int main(void)
{
    cout<<__cplusplus<<endl;
    int id=0;
    auto f=[id]()mutable{
        std::cout<<"id:"<<id<<endl;
        ++id;
    };
    id=34;
    f();
    f();
    f();
    cout<<id<<endl;
    lamda();
    system("pause");
}