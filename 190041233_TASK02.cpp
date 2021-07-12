#include<bits/stdc++.h>
using namespace std;

class matrix3D
{
private:
  int del;

  public:
 double det()
 {
     int z[100][100];
  for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cin>>z[i][j];
    }

}
del=(z[0][0]*((z[1][1]*z[2][2])-(z[1][2]*z[2][1])))-((z[0][1])*((z[1][0]*z[2][2])-(z[1][2]*z[2][0]))+((z[0][2])*((z[2][0]*z[1][1])-(z[1][0]*z[2][1])));



 }



};





int main()

{

}
