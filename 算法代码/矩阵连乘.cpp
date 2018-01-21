#include<iostream>
using namespace std;
void MartixMultiply(int *p,int n,int **m,int **s)
{
    for(int i=0;i<=n;i++)
        m[i][i]=0;
    for(int r=1;r<n;r++)
    {
        for(int i=1;i<=n-r;i++)
        {
            int j=i+r;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}
void printresult(int i,int j,bool q,int **s)
{
    if(i==j)
    {
        cout<<"A"<<i-1;
        return;
    }
    if(q)
        cout<<"(";
    printresult(i,s[i][j],true,s);
    printresult(s[i][j]+1,j,true,s);
    if(q)
        cout<<")";
}
int main()
{
    int *p,**s,**m;
    int n;
    while(cin>>n&&n)
    {
        p=new int [n+1];
        for(int i=0;i<=n;i++)
        {
            cin>>p[i];
        }
        s=new int *[n+1];
        m=new int *[n+1];
        for(int i=0;i<n+1;i++)
        {
            s[i]=new int [n+1];
            m[i]=new int [n+1];
        }
        MartixMultiply(p,n,m,s);
        printresult(1,n,false,s);
        cout<<endl;
        for(int i=0;i<n+1;i++)
        {
            delete [] s[i];
            delete [] m[i];
        }
        delete [] s;
        delete [] m;
        delete [] p;
    }
    return 0;
}
