#include<iostream>
using namespace std;
int GetMaxLength(int m,int n,char *x,char *y,int **c,int **b)
{
    for(int i=0;i<=m;i++) c[i][0]=0;
    for(int j=0;j<=n;j++) c[0][j]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else
            {
                if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]=2;
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]=3;
                }
            }
        }
    }
}
void PrintResult(int i,int j,char *x,int **b)
{
    if(i==0||j==0)
        return ;
    if(b[i][j]==1)
    {
        PrintResult(i-1,j-1,x,b);
        cout<<x[i]<<" ";
    }
    else
    {
        if(b[i][j]==2)
            PrintResult(i-1,j,x,b);
        else
            PrintResult(i,j-1,x,b);
    }
}
int main()
{
    int **c,**b,n,m;
    char *x,*y;
    cout<<"输入x和y序列的元素个数"<<endl;
    cin>>m>>n;
    x=new char [m+1];
    y=new char [n+1];
    c=new int *[m+1];
    b=new int *[m+1];
    for(int i=0;i<=m;i++)
    {
        b[i]=new int [n+1];
        c[i]=new int [n+1];
    }
    cout<<"输入序列x和y"<<endl;
    for(int i=1;i<=m;i++)
        cin>>x[i];
    for(int i=1;i<=n;i++)
        cin>>y[i];
    GetMaxLength(m,n,x,y,c,b);
    PrintResult(m,n,x,b);
    delete [] x;
    delete [] y;
    for(int i=0;i<m;i++)
    {
        delete [] b[i];
        delete [] c[i];
    }
    delete [] b;
    delete [] c;
    return 0;
}
