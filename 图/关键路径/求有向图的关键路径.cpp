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
    infotype info;
}arcnode;
typedef struct vnode
{
    vertextype data;
    arcnode *firstarc;
    int indegree;
}vnode,adjlist[vertexnum];
typedef struct
{
    adjlist vertices;//邻接表节点；
    adjlist nivertices;//逆邻接表；
    int weight[vertexnum][vertexnum];
    int vexnum,arcnum;//节点数，边数；
}ALgraph;
int ve[vertexnum];
int vl[vertexnum];
struct sqstack S,T;
struct sqstack *s,*t;
//创建图的邻接表和逆邻接表；
void createlist(ALgraph *G)
{
    int square[vertexnum][vertexnum];
    int i,j;
    //用于创建邻接矩阵；
    cout<<"请您输入从那个节点到哪个节点之间有边,以及该边的权值。输入大于节点个数的数字结束输入"<<endl;
    int ends=1,start=1,weight;
    for(i=0;i<vertexnum;i++)
    {
        G->vertices[i].indegree=0;
        for(j=0;j<vertexnum;j++)
        {
            square[i][j]=0;
            G->weight[i][j]=0;
        }
    }
    //创建邻接矩阵；
    while(start>0&&start<=vertexnum&&ends>0&&start<=vertexnum)
    {
        scanf("%d%d%d",&start,&ends,&weight);
        square[start-1][ends-1]=1;
        G->weight[start-1][ends-1]=weight;
    }
    //初始化每个节点；
    for(i=0;i<vertexnum;i++)
    {
        G->vertices[i].data=i+1;
        G->vertices[i].firstarc=NULL;
        G->nivertices[i].firstarc=NULL;
    }
    arcnode *p,*p1;
    //创建邻接表和逆邻接表
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
//拓扑排序；
bool topusort(ALgraph *G)
{
    int i;
    arcnode *p;
    s=&S;
    t=&T;
    initstack(s);
    initstack(t);
    //求出每个节点的出度；
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
    //初始化每一个节点事件的最早发生时间
    for(i=0;i<vertexnum;i++)
    {
        ve[i]=0;
        //将入度为零的节点压栈；
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
     //   cout<<i+1;
        push(t,i);
        counts++;
        for(p=G->vertices[i].firstarc;p;p=p->nextarc)
        {
            k=p->adjvex-1;
            p->info=G->weight[i][k];
            G->vertices[k].indegree--;
            if(G->vertices[k].indegree==0)
                push(s,k);
            if(ve[i]+p->info>ve[k])
                ve[k]=ve[i]+p->info;
        }
    }
  /*  cout<<endl;
    for(i=0;i<vertexnum;i++)
    {
        cout<<ve[i]<<endl;
    }*/
    //如果没有输出全部节点；
    if(counts<vertexnum-1)
        return false;
    else
        return true;
}
void criticalpath(ALgraph *G)
{
    //前提为：G为有向无环网；
    bool g=topusort(G);
    arcnode *p;
    int j,i,k;
    if(g!=true)
    {
        printf("不是五环图");
        exit(0);
    }
    for(i=0;i<vertexnum;i++)
        vl[i]=ve[vertexnum-1];
    while(!isempty(t))
    {
        pop(t,&j);
       for(p=G->vertices[j].firstarc;p;p=p->nextarc)
       {
           k=p->adjvex-1;
           p->info=G->weight[j][k];
           if(vl[k]-p->info<vl[j])
              vl[j]=vl[k]-p->info;
       }
    }
  //  for(i=0;i<vertexnum;i++)
  //      printf("%d  %d\n",ve[i],vl[i]);
    cout<<"关键边为："<<endl;
    for(j=0;j<vertexnum;j++)
    {
        for(p=G->vertices[j].firstarc;p;p=p->nextarc)
        {
           if(ve[j]==vl[j])
           {
               k=p->adjvex-1;
               if(ve[k]==vl[k])
               {
                   int weight=G->weight[j][k];
                   printf("%d---%d---%d\n",G->vertices[j].data,weight,G->vertices[k].data);
               }
           }
        }
    }
}
int main()
{
    int i;
    ALgraph G;
    //生成邻接表和逆邻接表；
    createlist(&G);
    cout<<"邻接矩阵为："<<endl;
    for(i=0;i<vertexnum;i++)
    {
        arcnode *p;
        p=G.vertices[i].firstarc;
        cout<<G.vertices[i]. data<<':';
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
    criticalpath(&G);
}

/*
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
10 10 10
*/
