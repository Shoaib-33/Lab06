#include<bits/stdc++.h>
using namespace std;
#define endl '\n'


///CODED BY SHOAIB




class Matrix3D
{
private:
    int a[3][3];
public:
    Matrix3D()
    {
        a[0][0] = 0;
        a[0][1] = 0;
        a[0][2] = 0;
        a[1][0] = 0;
        a[1][1] = 0;
        a[1][2] = 0;
        a[2][0] = 0;
        a[2][1] = 0;
        a[2][2] = 0;
    }
    Matrix3D(int m[3][3])
    {
        a[0][0] = m[0][0];
        a[0][1] = m[0][1];
        a[0][2] = m[0][2];
        a[1][0] = m[1][0];
        a[1][1] = m[1][1];
        a[1][2] = m[1][2];
        a[2][0] = m[2][0];
        a[2][1] = m[2][1];
        a[2][2] = m[2][2];
    }
    ~Matrix3D()
    {

    }
    void showMatrix()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    Matrix3D operator + (Matrix3D);
    Matrix3D operator - (Matrix3D);
    Matrix3D operator * (Matrix3D);
    void getCoFactor(int p, int q, int temp[2][2]);
    double det();
    Matrix3D inverse();
};

Matrix3D Matrix3D::operator + (Matrix3D m)
{
    int temp[3][3];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp[i][j] = a[i][j] + m.a[i][j];
        }
    }
    return Matrix3D(temp);
}

Matrix3D Matrix3D::operator - (Matrix3D m)
{
    int temp[3][3];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp[i][j] = a[i][j] - m.a[i][j];
        }
    }
    return Matrix3D(temp);
}

Matrix3D Matrix3D::operator * (Matrix3D m)
{
    int temp[3][3];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp[i][j] = a[i][0]*m.a[j][0] + a[i][1]*m.a[j][1] + a[i][2]*m.a[j][2];
        }
    }
    return Matrix3D(temp);
}

void Matrix3D::getCoFactor(int p, int q, int temp[2][2])
{
    int r = 0, c = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i!=p && j!=q)
            {
                temp[r][c] = a[i][j];
                c++;
                if(c==2)
                {
                    r++;
                    c=0;
                }
            }
        }
    }
}

double Matrix3D::det()
{
    int temp[2][2];
    double d = 0;
    int sign = 1;
    for(int i=0; i<3; i++)
    {
        getCoFactor(i, 0, temp);
        d += sign*(temp[0][0]*temp[1][1] - temp[0][1]*temp[1][0])*a[i][0];
        sign= -sign;
    }
    return d;
}

Matrix3D Matrix3D::inverse()
{
    int adj[3][3], temp[2][2];
    int sign;
    double d = det();
    if(d==0)
    {
        cout<<"Singular matrix, cannot be inverted.\n";
        exit(1);
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            getCoFactor(i, j, temp);
            sign = ((i+j)%2==0) ? 1:-1;
            adj[i][j] = sign*(temp[0][0]*temp[1][1] - temp[0][1]*temp[1][0])/d;
        }
    }
    return Matrix3D(adj);
}

int main()
{
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Matrix3D m1(mat1), m2(mat2), m3, m4;
    m3 = m1+m2;
    m3.showMatrix();
    m3 = m1-m2;
    m3.showMatrix();
    m3 = m1*m2;
    m3.showMatrix();
    cout<<m1.det()<<"\n";
    m4 = m2.inverse();
    m4.showMatrix();
    m1.inverse();
}
