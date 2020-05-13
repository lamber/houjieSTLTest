template<typename T1>
class MySwap
{
private:
    T1 a1,a2;
public:
    MySwap(T1 a,T1 b):a1(a),a2(b){}
    ~MySwap();
    T1 maxVal()
    {
        a1>a2?a1:a2;
    }

};


