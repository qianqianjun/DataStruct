#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define vertexnum 5
typedef int vertextype;
typedef struct vnodes
{
    vertextype data;
    struct vnodes*next;
}vertexnode;
typedef struct nodes
{
    vertextype node[vertexnum];
    int length;
}childnode;
childnode child;
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
        child.node[child.length]=vlist[i].data;
        child.length++;
       // cout<<vlist[i].data<<' ';
        status[i]=1;
        vertexnode *p=vlist[i].next;
        while(p!=NULL)
        {
            DFScore(vlist,status,p->data);
            p=p->next;
        }
    }
}
void DFS(vertexnode vlist[vertexnum],int status[vertexnum])
{
    int i,j;
    cout<<"连通分量为:"<<endl;
    for(i=0;i<vertexnum;i++)
    {
        DFScore(vlist,status,i);
        if(child.length!=0)
        {
            for(j=0;j<child.length;j++)
                cout<<child.node[j]<<' ';
            cout<<endl;
        }
        child.length=0;
    }
}
int main()
{
    vertexnode vlist[vertexnum];
    int square[vertexnum][vertexnum];
    int status[vertexnum];
    child.length=0;
    cout<<"请您输入边的起点和终点，输入大于节点个数的数字结束输入"<<endl;
    int start=0,ends=0;
    int i,j;
    for(i=0;i<vertexnum;i++)
    {
        status[i]=0;
        for(j=0;j<vertexnum;j++)
        {
            square[i][j]=0;
        }
    }
    while(start>=0&&start<vertexnum&&ends<=vertexnum&&start>=0)
    {
        scanf("%d%d",&start,&ends);
        createsquare(square,start,ends);
    }
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
    DFS(vlist,status);
}

/*
4节点；
0 1
1 0
0 2
2 0
2 3
3 2
3 0
0 3
6 6
五个节点；
0 1
1 0
0 3
3 0
1 2
2 1
1 4
4 1
2 3
3 2
2 4
4 2
9 9
*/
