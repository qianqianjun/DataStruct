#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define maxlength 200
int findnum(int num)
{
    int i=1;
    while(i<num)
    {
        i=2*i;
    }
    return i;
}
int GetBigInt(char *&s1,int *&a1,char *&s2,int *&a2)
{
    int maxnum1,maxnum2;
    char *temp1,*temp2;
    int num1,num2,maxnum;
    temp1=new char [maxlength];
    temp2=new char [maxlength];
    cin>>temp1;
    cin>>temp2;
    num1=strlen(temp1);
    maxnum1=findnum(num1);
    num2=strlen(temp2);
    maxnum2=findnum(num2);
    if(maxnum1>maxnum2)
        maxnum=maxnum1;
    else
        maxnum=maxnum2;
    s1=new char [maxnum];
    s2=new char [maxnum];
    for(int i=0;i<maxnum-num1;i++)
    {
        s1[i]='0';
    }
    for(int i=maxnum-num1,j=0;i<maxnum;i++,j++)
    {
        s1[i]=temp1[j];
    }
    for(int i=0;i<maxnum-num2;i++)
    {
        s2[i]='0';
    }
    for(int i=maxnum-num2,j=0;i<maxnum;i++,j++)
    {
        s2[i]=temp2[j];
    }
    delete [] temp1;
    delete [] temp2;
    a1=new int [maxnum];
    a2=new int [maxnum];
    for(int i=0;i<maxnum;i++)
    {
        a1[i]=s1[i]-'0';
        a2[i]=s2[i]-'0';
    }
    return maxnum;
}
int ADD(int *a,int *b,int *&c,int num)
{
    c[0]=0;
    for(int i=0,j=1;i<num;i++,j++)
    {
        c[j]=a[i]+b[i];
    }
    for(int i=num;i>=0;i--)
    {
        if(c[i]>=10)
        {
            c[i-1]++;
            c[i]=c[i]%10;
        }
    }
}
int SUB(int *a,int *b,int *c,int maxnum)
{
    for(int i=0;i<maxnum;i++)
    {
        if(a[i]>b[i])
        {
            c[0]=88;
            for(int j=1;j<=maxnum;j++)
            {
                c[j]=a[j-1]-b[j-1];
            }
            for(int k=maxnum;k>0;k--)
            {
                if(c[k]<0)
                {
                    c[k-1]--;
                    c[k]+=10;
                }
            }
            return 1;
        }
        if(a[i]<b[i])
        {
            c[0]=66;//表示数字是负的；
            for(int j=1;j<=maxnum;j++)
            {
                c[j]=b[j]-a[j];
            }
            for(int k=maxnum;k>0;k--)
            {
                if(c[k]<0)
                {
                    c[k-1]--;
                    c[k]+=10;
                }
            }
            return -1;
        }
    }
}
int MUL(int *&a,int *&b,int *&c,int maxnum)
{
    for(int i=0;i<2*maxnum;i++)
    {
        c[i]=0;
    }
    if(maxnum<=8) //如果位数小于8，不在进行递归，直接求出答案。
    {
        for(int i=maxnum-1;i>=0;i--)
        {
            for(int j=maxnum-1;j>=0;j--)
            {
                c[i+j+1]+=a[i]*b[j];
            }
        }
        for(int i=2*maxnum-1;i>0;i--)
        {
            if(c[i]>=10)
            {
                c[i-1]+=c[i]/10;
                c[i]=c[i]%10;
            }
        }
        return 0;
    }
    //如果比八位数字大，则要进行分治;
    else
    {
        int halfnum=maxnum/2;
        int *A=new int [halfnum];
        int *B=new int [halfnum];
        int *C=new int [halfnum];
        int *D=new int [halfnum];
        for(int i=0;i<halfnum;i++)
        {
            A[i]=a[i];
            C[i]=b[i];
            B[i]=a[i+halfnum];
            D[i]=b[i+halfnum];
        }
        int *AC=new int [maxnum]; //A*C;
        int *BD=new int [maxnum];  //B*D;
        int *AD=new int [maxnum];
        int *BC=new int [maxnum];
        MUL(A,C,AC,halfnum);
        MUL(B,D,BD,halfnum);
        MUL(A,D,AD,halfnum);
        MUL(B,C,BC,halfnum);
        int *ADJBC=new int [maxnum+1];
        ADD(AD,BC,ADJBC,maxnum);
        //将结果合并到c中;
        for(int i=0;i<maxnum;i++)
        {
            c[i]+=AC[i];
        }
        for(int i=0,j=halfnum-1;i<=maxnum;i++,j++)
        {
            c[j]+=ADJBC[i];
        }
        for(int i=maxnum;i<2*maxnum;i++)
        {
            c[i]+=BD[i-maxnum];
        }
        for(int i=2*maxnum-1;i>=0;i--)
        {
            if(c[i]>=10)
            {
                c[i-1]+=c[i]/10;
                c[i]=c[i]%10;
            }
        }
        delete [] A;
        delete [] B;
        delete [] C;
        delete [] B;
        delete [] BD;
        delete [] AC;
        delete [] AD;
        delete [] BC;
        delete [] ADJBC;
    }
    return 0;
}
void PrintResult(int *c,int n)
{
    int i;
    for(i=0;i<2*n;i++)
        if(c[i]!=0)
        break;
    for(int j=i;j<2*n;j++)
        cout<<c[j];
    cout<<endl;
}
int main()
{
    int maxnum;
    char *s1,*s2;
    int *a1,*a2,*rel;
    maxnum=GetBigInt(s1,a1,s2,a2);
    rel=new int [2*maxnum];
    MUL(a1,a2,rel,maxnum);
    PrintResult(rel,maxnum);
    delete [] a1;
    delete [] a2;
    delete [] s1;
    delete [] s2;
    delete [] rel;
    return 0;
}
