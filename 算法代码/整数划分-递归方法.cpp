/*#include<iostream>
#include<stdio.h>
using namespace std;
int mark[10];
int number;
//now记录当前长度,deep为当前的深度，forwardvalue表示前一个的值。
int Divid(int now,int deep,int forwardvalue)
{
    int i;
    if(now > number)
        return 0;  //设置递归的出口。
    if(now == number)
    {
        for(i = 0; i < deep-1; i++)
            cout<<mark[i]<<"+";
        cout<<mark[i]<<endl;
    }
    else
    {
        for(i = forwardvalue; i > 0; i--)
        {
            if(i <= forwardvalue)  //必须比前一个要小
            {
                mark[deep]=i;
                now+=i;
                Divid(now,deep+1,i);
                now-=i;
            }
        }
    }
}
int main()
{
    cin>>number;
    Divid(0,0,number-1);
    return 0;
}*/
#include<iostream>
using namespace std;
#include<stdio.h>
int equationCount(int n,int m)
{
    if(n==1||m==1)
        return 1;
    else if(n<m)
        return equationCount(n,n);
    else if(n==m)
        return 1+equationCount(n,n-1);
    else
        return equationCount(n,m-1)+equationCount(n-m,m);
}
int main()
{
    int n;
    cin>>n;
    printf("%d",equationCount(n,n));
    return 0;
}
