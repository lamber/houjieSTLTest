#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstring>
#include<typeinfo>
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
class MyString;
template<typename T>
void output_static_data(const T& myStr)
{
    cout<<typeid(myStr).name()<<"--"<<endl;
    cout<<"CCtor="<<T::CCtor
    <<"MCtor="<<T::MCtor
    <<"CAsgn="<<T::CAsgn
    <<"MAsgn="<<T::MAsgn
    <<"DCtor="<<T::DCtor
    <<"Ctor="<<T::Ctor
    <<"Dtor="<<T::Dtor
    <<endl;
}
template<typename M>
void test_moveable(M c,long &value)
{
    char buf[10];
    typedef typename
     iterator_traits<typename M::iterator>::value_type Vtype;
     clock_t timeStart=clock();
     for(long i=0;i<value;++i)
     {
         snprintf(buf,10,"%d",rand());
         auto ite=c.end();
         c.insert(ite,Vtype(buf));
     }
     cout<<"milli-seconds:"<<(clock()-timeStart)<<endl;
     cout<<"size()="<<c.size()<<endl;
    output_static_data(*(c.begin()));
     M c1(c);
     M c2(std::move(c1));
     c1.swap(c2);

}
class MyString
{
public:
    static size_t DCtor; // 记录默认构造的调用次数
    static size_t Ctor;  // 记录ctor的调用次数
    static size_t CCtor; // 记录copy ctor的调用次数
    static size_t CAsgn; // 记录copy asgn的调用次数
    static size_t MCtor; // 记录move-ctor的调用次数
    static size_t MAsgn; // 记录move-asgn的调用次数
    static size_t Dtor;  // 记录dtor的调用次数
private:
    char* _data;
    size_t _len;
    void _init_data(const char *s) {
        _data = new char[_len+1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }
public:
    // 默认构造
    MyString():_data(NULL), _len(0) {++DCtor;}
    // 构造 
    MyString(const char* p) : _len(strlen(p)) {
        ++MyString::Ctor;
        _init_data(p);
    }
    // 拷贝构造
    MyString(const MyString& str): _len(str._len) {
        ++CCtor;
        _init_data(str._data);
    }
    // copy assignment 拷贝赋值
    MyString& operator=(const MyString& str){
        ++CAsgn;
        if(this==&str) {
            return *this;
        }
        if(_data) delete _data;
        _len = str._len;
        _init_data(str._data);
        return *this;
    }
    // move 构造 with noexcept
    MyString(MyString&& str) noexcept 
        // 把指针拷贝一下 长度拷贝一下
        :_data(str._data), _len(str._len){
        ++MCtor;
        // 删除指针，如果不删除的话 如果右值被析构的时候编译器会调用析构函数把move的数据给回收
        // 配合析构函数来看
        str._len = 0;
        str._data = NULL; // 重要
    }
    // move assignment
    MyString& operator=(MyString&& str) noexcept{
        ++MAsgn;
        // move
        if(this!=&str) {
            if(_data) delete _data;
            _len = str._len;
            _data = str._data;
            str._len = 0;
            str._data = NULL; // 重要
        }
        return *this;
    }

    // 析构函数
    virtual ~MyString() {
        ++DCtor;
        if(_data) delete _data;
    }

    bool operator < (const MyString& rhs) const {
        return string(this->_data) < string(rhs._data);
    }

    bool operator==(const MyString& rhs) const {
        return string(this->_data) == string(rhs._data);
    }

    char* get() const {
        return _data;
    }
};
   size_t  MyString::DCtor=0; // 记录默认构造的调用次数
   size_t  MyString::Ctor=0;  // 记录ctor的调用次数
   size_t  MyString::CCtor=0; // 记录copy ctor的调用次数
   size_t MyString::CAsgn=0; // 记录copy asgn的调用次数
   size_t  MyString::MCtor=0; // 记录move-ctor的调用次数
   size_t MyString::MAsgn=0; // 记录move-asgn的调用次数
   size_t MyString::Dtor=0;  // 记录dtor的调用次数
int main(void)
{
    cout<<__cplusplus<<endl;
   /* int id=0;
    auto f=[id]()mutable{
        std::cout<<"id:"<<id<<endl;
        ++id;
    };
    id=34;
    f();
    f();
    f();
    cout<<id<<endl;
    lamda();*/
    long value=10000;
    test_moveable(vector<MyString>(),value);
    system("pause");
}