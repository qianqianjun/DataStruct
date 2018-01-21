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
        move(1,begins,ends);//ֻ��һ��������ֱ�ӽ������ϵ������ƶ���Ŀ�ĵ�
    else
    {
        hanoi(n-1,begins,ends,stop);//�Ƚ���ʼ����ǰn-1�����ӽ���Ŀ�����ƶ�����������
        move(n,begins,ends);              //��ʣ�µ�һ�������ƶ���Ŀ������
        hanoi(n-1,stop,begins,ends);//��󽫽������ϵ�n-1�������ƶ���Ŀ������
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
