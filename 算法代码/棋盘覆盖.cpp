#include<iostream>
using namespace std;
int **p;
int tile=0;
/*
#define lt 4;
#define rt 3;
#define lb 2;
#define rb 1;*/
const int lt=4;
const int rt=3;
const int lb=2;
const int rb=1;
int getm(int k)
{
    if(k==1)
        return 2;
    else
    {
        return 2*getm(k-1);
    }
    return 1;
}
int printchess(int k)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
           cout<<p[i][j]<<" ";
        cout<<endl;
    }
}
int test(int k)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
            p[i][j]=1;
    }
    return 0;
}
void coverchess(int tr,int tc,int dr,int dc,int sizes)
{
    if(sizes==1)
        return;
    int t;
    int s=sizes/2;  //分割子棋盘;
    if(dr<tr+s&&dc<tc+s)
        t=lt;
    else
    {
        if(dr<tr+s&&dc>=tc+s)
           t=rt;
        else
        {
            if(dr>=tr+s&&dc<tc+s)
                t=lb;
            else
            {
                if(dr>=tr+s&&dc>=tc+s)
                    t=rb;
            }
        }
    }
    //覆盖棋盘左上角的子棋盘；
    if(dr<tr+s&&dc<tc+s)
        //特殊方格在此棋盘中。
        coverchess(tr,tc,dr,dc,s);
    else//此棋盘中没有特殊的方格。
    {
        //用t号L型骨牌覆盖右下角。
        p[tr+s-1][tc+s-1]=t;
        //覆盖其余方格：
        coverchess(tr,tc,tr+s-1,tc+s-1,s);
    }
    //覆盖右上角子棋盘：
    if(dr<tr+s&&dc>=tc+s)
        //特殊方格在此棋盘中
        coverchess(tr,tc+s,dr,dc,s);
    else
    {
        //此棋盘中没有特殊方格。
        //用t号L型方格覆盖左下角。
        p[tr+s-1][tc+s]=t;
        //覆盖其余方格。
        coverchess(tr,tc+s,tr+s-1,tc+s,s);
    }
    //覆盖左下角棋盘;
    if(dr>=tr+s&&dc<tc+s)
        //特殊方格在此棋盘中。
        coverchess(tr+s,tc,dr,dc,s);
    else
    {
        //用t号L型骨牌覆盖右上角。
        p[tr+s][tc+s-1]=t;
        //覆盖其余方格：
        coverchess(tr+s,tc,tr+s,tc+s-1,s);
    }
    //覆盖右下角的棋盘。
    if(dr>=tr+s&&dc>=tc+s)
        //特殊方格在此棋盘中。
        coverchess(tr+s,tc+s,dr,dc,s);
    else{
        //用t号L型骨牌覆盖左上角。
        p[tr+s][tc+s]=t;
        //覆盖其余方格。
        coverchess(tr+s,tc+s,tr+s,tc+s,s);
    }
}
int main()
{
    int k,tr,tc;
    cout<<"输入棋盘的规模和特殊点的位置，注意左上角的点位置为（0 ，0）空格隔开"<<endl;
    cin>>k>>tr>>tc;
    k=getm(k);
    p=new int *[k];
    for(int i=0;i<k;i++)
    {
        p[i]=new int [k];
    }
    //标记特殊点。
    p[tr][tc]=0;
    coverchess(0,0,tr,tc,k);
    printchess(k);
    return 0;
}
