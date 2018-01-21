#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;
class pointX
{
public:
    int operator <=(pointX a) const
    {
        return (x<=a.x);
    }
    int id;
    float x,y;
};
class pointY
{
public:
    int operator <=(pointY a)
    {
        return (y<=a.y);
    }
    int p;
    float x,y;
};
template <class type>
int mergesort(type &T,int n)
{
    type t;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(T[j]<=T[j+1])
                continue;
            else
            {
                *t=T[j];
                T[j]=T[j+1];
                T[j+1]=*t;
            }
        }
    }
}
template <class numtype>
float Distance(const numtype& u,const numtype& v)
{
    float dx=u.x-v.x;
    float dy=u.y-v.y;
    return sqrt(dx*dx+dy*dy);
}
void closet(pointX x[],pointY y[],pointY z[],int l,int r,pointX& a,pointX& b,float &d)
{
    if(r-l==1)//只有两个点的时候。
    {
        a=x[l];
        b=x[r];
        d=Distance(x[l],x[r]);
        return;
    }
    if(r-l==2)//有三个点的时候：
    {
        float d1=Distance(x[l],x[l+1]);
        float d2=Distance(x[l+1],x[r]);
        float d3=Distance(x[l],x[r]);
        //找出三个距离中的最小值。
        if(d1<=d2&&d1<=d3)
        {
            a=x[l];
            b=x[l+1];
            d=d1;
            return ;
        }
        if(d2<=d3&&d2<=d1)
        {
            a=x[l+1];
            b=x[r];
            d=d2;
            return;
        }
        if(d3<=d1&&d3<=d2)
        {
            a=x[l];
            b=x[r];
            d=d3;
            return;
        }
    }
    //多于三个点的情况：要用到分治的方法。
    int m=(l+r)/2;
    int f=l,g=m+1;
    for(int i=l;i<=r;i++)
    {
        if(y[i].p>m)
            z[g++]=y[i];
        else
            z[f++]=y[i];
    }
    pointY *Y=new pointY [r-l+1];
    for(int i=0;i<r-l+1;i++)
    {
        Y[i]=y[i+l];
    }

    closet(x,z,y,l,m,a,b,d);
    float dr;
    pointX ar,br;
    closet(x,z,y,m+1,r,ar,br,dr);
    if(dr<d)
    {
        a=ar;
        b=br;
        d=dr;
    }
    for(int i=l;i<r+1;i++)
    {
        y[i]=Y[i-l];
    }
    delete [] Y;
    //Merge(z,y,l,m,r);//重构数组Y;
    //d矩形条内的点置于Z中。
    int k=l;
    for(int i=l;i<=r;i++)
    {
        if(fabs(y[m].x-y[i].x)<d)
            z[k++]=y[i];
    }
    for(int i=l;i<k;i++)
    {
        for(int j=i+1;j<k&&z[j].y-z[i].y<d;j++)
        {
            float dp=Distance(z[i],z[j]);
            if(dp<d)
            {
                d=dp;
                a=x[z[i].p];
                b=x[z[j].p];
            }
        }
    }
}
bool cpair2(pointX x[],int n,pointX &a,pointX& b,float &d)
{
    if(n<2)
        return false;
    pointY *y=new pointY [n];
    mergesort(x,n);
    for(int i=0;i<n;i++)
    {
        y[i].p=i;
        y[i].x=x[i].x;
        y[i].y=x[i].y;
    }
    mergesort(y,n);
    pointY *z=new pointY [n];
    closet(x,y,z,0,n-1,a,b,d);
    delete [] y;
    delete [] z;
    return true;
}
int main()
{
    int n;
    cin>>n;
    pointX *x=new pointX [n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i].x>>x[i].y;
    }
    pointX a;
    pointX b;
    float d;
    cpair2(x,n,a,b,d);
    cout<<"最接近点对为:"<<"<"<<a.x<<","<<a.y<<">"<<"和"<<"<"<<b.x<<","<<b.y<<">"<<endl;
    cout<<"距离为:"<<d<<endl;
    return 0;
}
