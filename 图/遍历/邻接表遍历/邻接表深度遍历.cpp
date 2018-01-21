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
    cout<<"深度遍历结果为"<<endl;
    for(i=0;i<vertexnum;i++)
    {
        DFScore(vlist,status,i);
    }
}
int main()
{
    //定义表头节点；
    vertexnode vlist[vertexnum];
    //初始化邻接矩阵；
    int square[vertexnum][vertexnum];
    //访问状态数组；
    int status[vertexnum];
    int start=0,ends=0;
    int i,j;
    //初始化状态数组为都没有访问过的状态；并且初始化邻接矩阵；
    for(i=0;i<vertexnum;i++)
    {
        status[i]=0;
        for(j=0;j<vertexnum;j++)
        {
            square[i][j]=0;
        }
    }
    cout<<"请您输入边的起点和终点，输入大于节点个数的数字结束输入"<<endl;
    //创建一个邻接矩阵。
    while(start>=0&&start<vertexnum&&ends<=vertexnum&&start>=0)
    {
        scanf("%d%d",&start,&ends);
        createsquare(square,start,ends);
    }
    cout<<"生成邻接矩阵为"<<endl;
    for(i=0;i<vertexnum;i++)
    {
         for(j=0;j<vertexnum;j++)
            cout<<square[i][j]<<' ';
         cout<<endl;
    }
    //有生成的邻接矩阵和初始化后的邻接表创建一个图的对应邻接表。
    createlist(vlist,square);
    cout<<"生成的邻接表为"<<endl;
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
    //对邻接表进行深度遍历；
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
5个节点
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
4个节；
0 1
0 2
2 3
3 0
*/

