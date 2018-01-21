#include<iostream>
using namespace std;
int MinValue(int a,int b)
{
    return a>=b?b:a;
}
int MaxValue(int a,int b)
{
    return a>=b?a:b;
}
template <class type>
void Knapsack(type *v,int *w,int c,int n,type **m)
{
    int jMax=MinValue(w[n]-1,c);
    for(int j=0;j<=jMax;j++)
        m[n][j]=0;
    for(int j=w[n];j<=c;j++)
        m[n][j]=v[n];
    for(int i=n-1;i>1;i--)
    {
        jMax=MinValue(w[i]-1,c);
        for(int j=0;j<=jMax;j++)
            m[i][j]=m[i+1][j];
        for(int j=w[i];j<=c;j++)
            m[i][j]=MaxValue(m[i+1][j],m[i+1][j-w[i]]+v[i]);
    }
    m[1][c]=m[2][c];
    if(c>=w[1])
        m[1][c]=MaxValue(m[1][c],m[2][c-w[1]]+v[1]);
}
template <class type>
void PrintResult(type **m,int *w,int c,int n,int *x)
{
    for(int i=1;i<n;i++)
    {
        if(m[i][c]==m[i+1][c])
            x[i]=0;
        else
        {
            x[i]=1;
            c-=w[i];
        }
    }
    x[n]=(m[n][c])?1:0;
}
int main()
{
    int **m,c,*w,n,*v,*x;
    cout<<"请输入背包的容量，和物品的个数"<<endl;
    cin>>c>>n;
    w=new int [n+1];
    v=new int [n+1];
    m=new int *[n+1];
    x=new int [n+1];
    for(int i=0;i<n+1;i++)
    {
        m[i]=new int [c+1];
    }
    cout<<"输入物品的重量"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    cout<<"输入物品的价值"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    Knapsack(v,w,c,n,m);
    PrintResult(m,w,c,n,x);
    for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
    //释放内存操作:
    delete [] w;
    delete [] v;
    delete [] x;
    for(int i=0;i<n+1;i++)
    {
        delete [] m[i];
    }
    delete [] m;
    return 0;
}
