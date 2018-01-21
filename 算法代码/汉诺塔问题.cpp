#include <stdio.h>
#include<iostream>
using namespace std;
int i=1;
void move(int n,char from,char to)
{
    printf("%2d. Move disk %d from %c to %c\n",i++,n,from,to);
}
void hanoi(int n,char begins,char stop,char ends)
{
    if (n==1)
        move(1,begins,ends);//只有一个盘子是直接将初塔上的盘子移动到目的地
    else
    {
        hanoi(n-1,begins,ends,stop);//先将初始塔的前n-1个盘子借助目的塔移动到借用塔上
        move(n,begins,ends);              //将剩下的一个盘子移动到目的塔上
        hanoi(n-1,stop,begins,ends);//最后将借用塔上的n-1个盘子移动到目的塔上
    }
}
int main()
{
     int n;
     char x='X',y='Y',z='Z';
     while(cin>>n)
     {
         hanoi(n,x,y,z);
         i=1;
         cout<<endl;
     }
     return 0;
}
