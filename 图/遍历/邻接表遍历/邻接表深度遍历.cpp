#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define vertexnum 4
typedef int vertextype;
typedef struct vnodes
{
    vertextype data;
    struct vnodes*next;
}vertexnode;
void createsquare(int square[vertexnum][vertexnum],int start,int ends)
{
    square[start][ends]=1;
}
void createlist(vertexnode vlist[vertexnum],int square[vertexnum][vertexnum])
{
    int i,j;
    vertexnode *p,*p1;
    for(i=0;i<vertexnum;i++)
    {
        vlist[i].data=i;
        vlist[i].next=NULL;
    }
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
        {
            if(square[i][j]==1)
            {
                p=&vlist[i];
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                p1=(vertexnode*)malloc(sizeof(vertexnode));
                p1->data=j;
                p1->next=NULL;
                p->next=p1;
            }
        }
    }
}
void DFScore(vertexnode vlist[vertexnum],int status[vertexnum],int i)
{
    if(status[i]==0)
    {
        cout<<vlist[i].data<<' ';
        status[i]=1;
        vertexnode *p=vlist[i].next;
        while(p!=NULL)
        {
         //   cout<<'<'<<p->data<<'>'<<' ';
            DFScore(vlist,status,p->data);
            p=p->next;
        }
    }
}
void DFS(vertexnode vlist[vertexnum],int status[vertexnum])
{
    int i,j;
    cout<<"��ȱ������Ϊ"<<endl;
    for(i=0;i<vertexnum;i++)
    {
        DFScore(vlist,status,i);
    }
}
int main()
{
    //�����ͷ�ڵ㣻
    vertexnode vlist[vertexnum];
    //��ʼ���ڽӾ���
    int square[vertexnum][vertexnum];
    //����״̬���飻
    int status[vertexnum];
    int start=0,ends=0;
    int i,j;
    //��ʼ��״̬����Ϊ��û�з��ʹ���״̬�����ҳ�ʼ���ڽӾ���
    for(i=0;i<vertexnum;i++)
    {
        status[i]=0;
        for(j=0;j<vertexnum;j++)
        {
            square[i][j]=0;
        }
    }
    cout<<"��������ߵ������յ㣬������ڽڵ���������ֽ�������"<<endl;
    //����һ���ڽӾ���
    while(start>=0&&start<vertexnum&&ends<=vertexnum&&start>=0)
    {
        scanf("%d%d",&start,&ends);
        createsquare(square,start,ends);
    }
    cout<<"�����ڽӾ���Ϊ"<<endl;
    for(i=0;i<vertexnum;i++)
    {
         for(j=0;j<vertexnum;j++)
            cout<<square[i][j]<<' ';
         cout<<endl;
    }
    //�����ɵ��ڽӾ���ͳ�ʼ������ڽӱ���һ��ͼ�Ķ�Ӧ�ڽӱ�
    createlist(vlist,square);
    cout<<"���ɵ��ڽӱ�Ϊ"<<endl;
    for(i=0;i<vertexnum;i++)
    {
        vertexnode *p;
        p=&vlist[i];
        while(p!=NULL)
        {
            cout<<p->data<<' ';
            p=p->next;
        }
        cout<<endl;
    }
    //���ڽӱ������ȱ�����
    DFS(vlist,status);
}
/*
    for(i=0;i<vertexnum;i++)
    {
         for(j=0;j<vertexnum;j++)
            cout<<square[i][j]<<' ';
         cout<<endl;
    }


        for(i=0;i<vertexnum;i++)
    {
        vertexnode *p;
        p=&vlist[i];
        while(p!=NULL)
        {
            cout<<p->data<<' ';
            p=p->next;
        }
        cout<<endl;
    }
*/
/*
5���ڵ�
0 1
0 3
1 0
1 2
1 4
2 1
2 3
2 4
3 0
3 2
4 1
4 2
9 9
*/
/*
4���ڣ�
0 1
0 2
2 3
3 0
*/

