#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int **a;
float getweight(int v1,int v2,int v3)
{
    int A=(a[v1][0]-a[v2][0])*(a[v1][0]-a[v2][0])+(a[v1][1]-a[v2][1])*(a[v1][1]-a[v2][1]);
    int B=(a[v1][0]-a[v3][0])*(a[v1][0]-a[v3][0])+(a[v1][1]-a[v3][1])*(a[v1][1]-a[v3][1]);
    int C=(a[v3][0]-a[v2][0])*(a[v3][0]-a[v2][0])+(a[v3][1]-a[v2][1])*(a[v3][1]-a[v2][1]);
    return sqrt(A)+sqrt(B)+sqrt(C);
}
int MinWeightTreeDiv(int n,float **t,int **s)
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<n+1;j++)
            t[i][j]=0;
    for(int r=1;r<n;r++)
    {
        for(int i=1;i<= n-r;i++)
        {
            int j=i+r;
            t[i][j]=t[i+1][j]+getweight(i-1,i,j);
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int u=t[i][k]+t[k+1][j]+getweight(i-1,k,j);
                if(u<t[i][j])
                {
                    t[i][j]=u;
                    s[i][j]=k;
                }
            }
        }
    }
}
void PrintResult(int i,int j,int **s)
{
    if(i==j)
        return;
    PrintResult(i,s[i][j],s);
    PrintResult(s[i][j]+1,j,s);
    cout<<"三角剖分顶点：V"<<i-1<<",V"<<j<<",V"<<s[i][j]<<endl;
}
int main()
{
    int num,**s;
    float **t;
    cout<<"请输入多边形点的个数"<<endl;
    cin>>num;
    a=new int *[num+1];
    t=new float *[num+1];
    s=new int *[num+1];
    for(int i=0;i<num+1;i++)
    {
        a[i]=new int [2];
        t[i]=new float [num+1];
        s[i]=new int [num+1];
    }
    cout<<"请输入点的坐标位置"<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    MinWeightTreeDiv(num,t,s);
    PrintResult(1,num-1,s);
    for(int i=0;i<num+1;i++)
    {
        delete [] a[i];
        delete [] t[i];
        delete [] s[i];
    }
    delete [] s;
    delete [] t;
    delete [] a;
    return 0;
}
