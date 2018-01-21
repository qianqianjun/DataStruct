#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include"link_queue.h"
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
void BFSTraverse(sqqueue *q,vertexnode vlist[vertexnum],int status[vertexnum])
{
    int i,k;
    for (i=0; i<vertexnum; ++i)
    {
       if(status[i]==0)
       {
            status[i] = 1;
            printf("%d ", vlist[i].data);
            addqueue(q,i);
            while (!emptyqueue(q))
            {
                k=delqueue(q);
                vertexnode *p = vlist[k].next;
                while (p)
                {
                    if (status[p->data]==0)
                    {
                        status[p->data] = 1;
                        printf("%d ", p->data);
                        addqueue(q, p->data);
                    }
                    p = p->next;
                }
            }
        }
    }
}
int main()
{
    vertexnode vlist[vertexnum];
    int square[vertexnum][vertexnum];
    int status[vertexnum];
    sqqueue *q;
    sqqueue que;
    q=&que;
    initqueue(q);
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
    //输入邻接矩阵。
    while(start>=0&&start<vertexnum&&ends<=vertexnum&&start>=0)
    {
        scanf("%d%d",&start,&ends);
        createsquare(square,start,ends);
    }
    //生成邻接表。
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
    printf("广度遍历结果为：\n");
    BFSTraverse(q,vlist,status);
}
