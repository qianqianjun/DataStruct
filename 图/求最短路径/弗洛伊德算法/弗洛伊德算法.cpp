#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//定义最多的节点数；
#define vertexnum 20
#define INFINITY 10000
typedef int infotype;
typedef int vertextype;
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
}vnode,adjlist[vertexnum];
typedef struct
{
    adjlist vertices;
    int vexnum;
    int arcs[vertexnum][vertexnum];
}Graph;
//创建邻接矩阵，存储边的权值；
void createarcell(Graph *G,int start,int ends,int weight)
{
    G->arcs[start][ends]=weight;
}
void creategraph(Graph *G)
{
    int i,j;
    int start=0,ends=0,weight;
    int num;
    cout<<"请您输入图包含的节点数目"<<endl;
    scanf("%d",&num);
    G->vexnum=num;
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j]=INFINITY;
    }
    cout<<"请您输入边的起点终点以及边的权值"<<endl;
    while(start>=0&&start<G->vexnum&&ends>=0&&ends<G->vexnum)
    {
        scanf("%d%d%d",&start,&ends,&weight);
        createarcell(G,start,ends,weight);
    }
}
//输出任意两个节点之间的最短路径；
void showresult(Graph *G,int path[vertexnum][vertexnum],int dist[vertexnum][vertexnum])
{
    int i,j,pre,k,p[vertexnum],m;
    cout<<"任意两点之间的最短路径为:"<<endl<<endl;
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            pre=path[i][j];
            k=0;
            while(1)
            {
                 if(pre==-1)
                 {
                     printf("%d-->%d: 无路径\n",i,j);
                     break;
                 }
                 if(pre==i)
                 {
                     printf("%d-->%d: ",i,j);
                     printf("距离:%d ",dist[i][j]);
                     printf("路径：");
                     printf("%d ",i);
                     for(m=k-1;m>=0;m--)
                         printf("%d ",p[m]);
                     printf("%d\n",j);
                     break;
                 }
                 p[k]=pre;
                 pre=path[i][pre];
                 k++;
            }
        }
        printf("\n");
    }
}
int floyd(Graph *G)
{
    int A[vertexnum][vertexnum];    //用于存储始节点到终节点的最短路径的长度；
    int path[vertexnum][vertexnum],i,j,k;   //用于存放从始节点到终节点的路径；
    //初始化；
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            A[i][j]=G->arcs[i][j];
            if(i!=j&&G->arcs[i][j]<INFINITY)
                path[i][j]=i;
            else
                path[i][j]=-1;
        }
    }
    //添加k节点作为中间节点之后对结果的影响；
    for(k=0;k<G->vexnum;k++)
    {
        for(i=0;i<G->vexnum;i++)
        {
            for(j=0;j<G->vexnum;j++)
            {
                if(A[i][j]>A[i][k]+A[k][j])    //找到一条更加短的路径；
                {
                    A[i][j]=A[i][k]+A[k][j];   //替换为更加短的路径长度；
                    path[i][j]=path[k][j];   //修改路径为经过k节点；
                }
            }
        }
    }
    showresult(G,path,A);
}
int main()
{
    Graph G;
    creategraph(&G);
    floyd(&G);
    return 0;
}
//测试数据：
/*
7
0 1 4
0 2 6
0 3 6
1 4 7
1 2 1
2 4 6
2 5 4
3 2 2
3 5 5
4 6 6
5 4 1
5 6 8
-1 -1 -1
第一行为节点数，之后若干行为用 始节点，终节点，权值 表示的边；最后一行数据用于结束输入；
*/
