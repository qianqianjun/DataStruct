#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include"esquence_stack.h"
using namespace std;
#define vertexnum 9
typedef int vertextype;
typedef int infotype;
typedef struct arcnode
{
    int adjvex;
    struct arcnode *nextarc;
    infotype *info;
}arcnode;
typedef struct vnode
{
    vertextype data;
    arcnode *firstarc;
    int indegree;
}vnode,adjlist[vertexnum];
typedef struct
{
    adjlist vertices;
    adjlist nivertices;
    int vexnum,arcnum;
}ALgraph;
void createlist(ALgraph *G)
{
    int square[vertexnum][vertexnum];
    int i,j;
    cout<<"请您输入从那个节点到哪个节点之间有边,输入大于节点个数的数字结束输入"<<endl;
    int ends=1,start=1;
    for(i=0;i<vertexnum;i++)
    {
        G->vertices[i].indegree=0;
        for(j=0;j<vertexnum;j++)
            square[i][j]=0;
    }
    //创建邻接矩阵；
    while(start>0&&start<=vertexnum&&ends>0&&start<=vertexnum)
    {
        scanf("%d%d",&start,&ends);
        square[start-1][ends-1]=1;
    }
    for(i=0;i<vertexnum;i++)
    {
        G->vertices[i].data=i+1;
        G->vertices[i].firstarc=NULL;
        G->nivertices[i].firstarc=0;
    }
    arcnode *p,*p1;
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
        {
            if(square[i][j]==1)
            {
                if(G->vertices[i].firstarc==NULL)
                {
                    p1=(arcnode*)malloc(sizeof(arcnode));
                    p1->adjvex=j+1;
                    p1->nextarc=NULL;
                    G->vertices[i].firstarc=p1;
                }
                else
                {
                    p=G->vertices[i].firstarc;
                    while(p->nextarc!=NULL)
                    {
                        p=p->nextarc;
                    }
                    p1=(arcnode*)malloc(sizeof(arcnode));
                    p1->adjvex=j+1;
                    p1->nextarc=NULL;
                    p->nextarc=p1;
                }
            }
            //求逆邻接表；
            if(square[j][i]==1)
            {
                if(G->nivertices[i].firstarc==NULL)
                {
                    p1=(arcnode*)malloc(sizeof(arcnode));
                    p1->adjvex=j+1;
                    p1->nextarc=NULL;
                    G->nivertices[i].firstarc=p1;
                }
                else
                {
                    p=G->nivertices[i].firstarc;
                    while(p->nextarc!=NULL)
                    {
                        p=p->nextarc;
                    }
                    p1=(arcnode*)malloc(sizeof(arcnode));
                    p1->adjvex=j+1;
                    p1->nextarc=NULL;
                    p->nextarc=p1;
                }
            }
        }
    }
}
bool tupusort(ALgraph *G)
{
    int i;
    arcnode *p;
    struct sqstack *s;
    struct sqstack S;
    s=&S;
    initstack(s);
    for(i=0;i<vertexnum;i++)
    {
        p=G->nivertices[i].firstarc;
        if(p!=NULL)
        {
            while(p!=NULL)
            {
                G->vertices[i].indegree++;
                p=p->nextarc;
            }
        }
    }
    for(i=0;i<vertexnum;i++)
    {
        if(G->vertices[i].indegree==0)
        {
            push(s,i);
        }
    }
    int counts=0;
    int k;
    while(!isempty(s))
    {
        pop(s,&i);
        cout<<G->vertices[i].data<<' ';
        counts++;
        for(p=G->vertices[i].firstarc;p;p=p->nextarc)
        {
            k=p->adjvex-1;
            G->vertices[k].indegree--;
            if(G->vertices[k].indegree==0)
            {
                push(s,k);
            }
        }
    }
    cout<<endl;
    if(counts<vertexnum-1)
        return false;
    else
        return true;
}
int main()
{
    int i;
    ALgraph G;
    createlist(&G);
    cout<<"邻接矩阵为："<<endl;
    for(i=0;i<vertexnum;i++)
    {
        arcnode *p;
        p=G.vertices[i].firstarc;
        cout<<G.vertices[i].data<<':';
        while(p!=NULL)
        {
            cout<<p->adjvex<<' ';
            p=p->nextarc;
        }
        cout<<endl;
    }
    cout<<"逆邻接矩阵为："<<endl;
    for(i=0;i<vertexnum;i++)
    {
        arcnode *p;
        p=G.nivertices[i].firstarc;
        cout<<i+1<<':';
        while(p!=NULL)
        {
            cout<<p->adjvex<<' ';
            p=p->nextarc;
        }
        cout<<endl;
    }
    cout<<"拓扑序列为："<<endl;
    if(tupusort(&G))
        printf("是一个无环图\n");
    else
        printf("不是无环图\n");
}

/*
1 2
1 3
1 4
2 5
3 5
4 6
5 7
5 8
6 8
7 9
8 9
10 10
*/
