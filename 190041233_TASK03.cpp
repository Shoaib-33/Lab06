#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

/// CODED BY SHOAIB
class Coordinate
{
private:
    float x, y;
public:
    Coordinate(): x(0), y(0)
    {

    }
    Coordinate(float a, float b): x(a), y(b)
    {

    }
    ~Coordinate()
    {

    }
    float getDistance()
    {
        return sqrt(x*x + y*y);
    }
    float getDistance(Coordinate c)
    {
        float a = pow((x - c.x),2)+pow((y - c.y),2);
        float e=sqrt(a);
        return e;
    }
    void move_x(float val)
    {
        x+=val;
    }
    void move_y(float val)
    {
        y+=val;
    }
    void move(float val)
    {
        x+=val;
        y+=val;
    }
    void showPosition()
    {
        cout<<"Abscissa: "<<x<<"\n";
        cout<<"Ordinate: "<<y<<"\n";
    }
    bool operator > (Coordinate &c);
    bool operator < (Coordinate &c);
    bool operator >= (Coordinate &c);
    bool operator <= (Coordinate &c);
    bool operator == (Coordinate &c);
    bool operator != (Coordinate &c);
    Coordinate operator ++ ();
    Coordinate operator ++ (int);
    Coordinate operator -- ();
    Coordinate operator -- (int);
};

bool Coordinate::operator > (Coordinate &c)
{
    float a = getDistance();
    float b = c.getDistance();
    return (a > b);
}

bool Coordinate::operator < (Coordinate &c)
{
    float a = getDistance();
    float b = c.getDistance();
    return (a < b);
}

bool Coordinate::operator >= (Coordinate &c)
{
    float a = getDistance();
    float b = c.getDistance();
    return (a >= b);
}

bool Coordinate::operator <= ( Coordinate &c)
{
    float a = getDistance();
    float b = c.getDistance();
    return (a <= b) ;
}

bool Coordinate::operator == (Coordinate &c)
{
    float a = getDistance();
    float b = c.getDistance();
    return (a == b);
}

bool Coordinate::operator != (Coordinate &c)
{
    float a = getDistance();
    float b = c.getDistance();
    return (a != b);
}

Coordinate Coordinate::operator ++ ()
{
    return Coordinate(++x, ++y);
}

Coordinate Coordinate::operator ++ (int)
{
    return Coordinate(x++, y++);
}

Coordinate Coordinate::operator -- ()
{
    return Coordinate(--x, --y);
}

Coordinate Coordinate::operator -- (int)
{
    return Coordinate(x--, y--);
}

int main()
{
    Coordinate c1(2,3), c2(-4,5);
    c1.showPosition();
    c2.showPosition();
    cout<<c1.getDistance()<<"\n";
    cout<<c2.getDistance()<<"\n";
    cout<<c1.getDistance(c2)<<"\n";
    cout<<c2.getDistance(c1)<<"\n";
    c1.move(2);
    c2.move(4);
    c1.showPosition();
    c2.showPosition();
    cout<<c1.getDistance()<<"\n";
    cout<<c2.getDistance()<<"\n";
    cout<<c1.getDistance(c2)<<"\n";
    cout<<c2.getDistance(c1)<<"\n";
    Coordinate c3 = c1;
    cout<<(c1>c3)<<"\n";
    cout<<(c1<c3)<<"\n";
    cout<<(c1>=c3)<<"\n";
    cout<<(c1<=c3)<<"\n";
    cout<<(c1==c3)<<"\n";
    cout<<(c1!=c3)<<"\n";
    ++c1;
    ++c3;
    c1.showPosition();
    c3.showPosition();
    c1++;
    c3++;
    c1.showPosition();
    c3.showPosition();
    --c1;
    --c3;
    c1.showPosition();
    c3.showPosition();
    c1--;
    c3--;
    c1.showPosition();
    c3.showPosition();
}
