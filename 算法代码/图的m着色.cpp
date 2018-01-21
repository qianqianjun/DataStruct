#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class color
{
public:
    int *x,m,n,**a,sum;
    bool ok(int k)
    {
        for(int i=1;i<=n;i++)
            if((a[k][i]==1)&&(x[i]==x[k]))
               return false;
        return true;
    }
    void Backtrack(int t)
    {
        if(t>n)
        {
            sum++;
            for(int i=1;i<=n;i++)
                cout<<x[i]<<" ";
            cout<<endl;
        }
        else
        {
            for(int i=1;i<=m;i++)
            {
                x[t]=i;
                if(ok(t))
                    Backtrack(t+1);
                x[t]=0;
            }
        }
    }
};
using namespace std;
int main()
{
    color col;
    cout<<"input the number of the graph and the number of the color"<<endl;
    cin>>col.n>>col.m;
    col.a=new int *[col.n+1];
    for(int i=0;i<=col.n;i++)
        col.a[i]=new int [col.n+1];
    cout<<"input the linjie matrix"<<endl;
    for(int i=1;i<=col.n;i++)
    {
        for(int j=1;j<=col.n;j++)
            cin>>col.a[i][j];
    }
    col.sum=0;
    col.x=new int [col.n+1];
    for(int i=0;i<=col.n;i++)
        col.x[i]=0;
    cout<<"the result is:"<<endl;
    col.Backtrack(1);
    delete [] col.x;
    for(int i=0;i<=col.n;i++)
        delete [] col.a[i];
    delete [] col.a;
    return 0;
}

//text number
/*
0 1 1 1 0
1 0 1 1 1
1 1 0 1 0
1 1 1 0 1
0 1 0 1 0
*/
