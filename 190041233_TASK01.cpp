#include<bits/stdc++.h>
using namespace std;



class Counter
{
private:
    int x;
    int count;


public:
    Counter():count(0)
    {

    }
    void setIncrementStep(int step_val)
    {
        x=step_val;
    }
    int getCount()
    {
        return count;
    }
 Counter(int c) : count(c)
    {

    }
    void increment()
    {
        count+=x;
    }
    void resetCount()
    {
        count=0;
    }
    Counter operator ++ ()
    {
        return Counter(++count);
    }
    Counter operator++(int)
    {
        return Counter(count++);
    }
    Counter operator+ (int a) const
    {
        return Counter(count+a);
    }
     Counter operator+ (Counter a) const
    {
        return Counter(count+a.count);
    }
    friend Counter operator+(int,Counter);

};
///nonmember
Counter operator+(int c, Counter a)
{
    return Counter(a.count+c);
}

int main()
{
    Counter a,b,c;

    a++;
    b++;
    c=++a;
    c=a+b;
    b=b+5;
    a=a+b;
    a=5+b;
    cout<<b.getCount()<<endl;
   cout<<a.getCount();


}




