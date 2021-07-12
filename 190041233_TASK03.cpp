#include<bits/stdc++.h>
using namespace std;


class Coordinate
{
    private:
      int a;
      float b;
      float l;

    public:


        Coordinate(int x,float y):a(x),b(y)
        {

        }
        float getDistance(Coordinate c)
        {
          float p;
          p=sqrt(pow(a-(c.a),2)+pow(b-(c.b),2));


        }
        float getDistance()
        {


            l=sqrt((a*a)+(b*b));
            return l;

        }
        void move_x(float val)
        {
            a+=val;
        }
        void move_y(float val)
        {
            b+val;
        }
        void move(float val)
        {
            a+=val;
            b+=val;
        }

 bool operator <(const Coordinate &a)
 {
     return (l<a.l);
 }
  bool operator >(const Coordinate &a)
 {
     return (l>a.l);
 }
  bool operator =(const Coordinate &a)
 {
     return (l==a.l);
 }
Coordinate operator++()
{
    a++;
    b++;
}

Coordinate operator--()
{
    a--;
    b--;
}


};

int main()
{

Coordinate m(1,1);
Coordinate n(-1,-1);
//++m;
cout<<m.getDistance();
cout<<endl;
cout<<n.getDistance();
cout<<endl;
cout<< (m=n) <<endl;
cout<<(m<n)<<endl;
m.getDistance(n);
move(1);

}

