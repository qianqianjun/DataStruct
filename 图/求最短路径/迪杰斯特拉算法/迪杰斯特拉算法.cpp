#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
#define vertexnum 20
#define INFINITY 10000
typedef int infotype;
typedef int vertextype;
using namespace std;
//图的存储结构，采用邻接矩阵存储；
typedef struct arcnode
{
    int adjvex;
    struct arcnode *nextarc;
    infotype *info;
}arcnode;
//邻接表元素；
typedef struct vnode
{
    vertextype data;
    arcnode *firstarc;
}vnode,adjlist[vertexnum];
typedef struct
{
    adjlist vertices;//存储图的邻接表，本程序用不到；
    int vexnum;//存储图的节点数；
    int arcs[vertexnum][vertexnum];//图的邻接矩阵；
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
//输出最短路径序列；
void showpath(Graph *G,int dist[vertexnum],int path[vertexnum],int v)
{
    int i,j,pre,k,p[vertexnum];
    for(i=0;i<G->vexnum;i++)
    {
        if(i==v)
            continue;
        else
        {
            k=0;
            pre=path[i];
            while(1)
            {
                if(pre==v)
                {
                    printf("%d-->%d:",v,i);
                    printf(" 长度为:%3d ",dist[i]);
                    printf("路径为：");
                    printf("%d  ",v);
                    for(j=k-1;j>=0;j--)
                        printf("%d  ",p[j]);
                    printf("%d\n",i);
                    break;
                }
                if(pre==-1)
                {
                    printf("无路径\n");
                    break;
                }
                p[k]=pre;
                pre=path[p[k]];
                k++;
            }
        }
    }
}
//迪杰斯特拉算法实现；
void shortpath_dij(Graph *G,int v)
{
    int dist[vertexnum],path[vertexnum],i,j,mindist,u;
    bool s[vertexnum];
    for(i=0;i<G->vexnum;i++)
    {
        dist[i]=G->arcs[v][i];
        s[i]=false;
        if(G->arcs[v][i]<INFINITY)
            path[i]=v;
        else
            path[i]=-1;
    }
    for(i=0;i<G->vexnum;i++)
    {
        mindist=INFINITY;
        for(j=0;j<G->vexnum;j++)
        {
            if(s[j]==0&&dist[j]<mindist)
            {
                u=j;
                mindist=dist[j];
            }
        }
        s[u]=1;
        for(j=0;j<G->vexnum;j++)
        {
            if(s[j]==0)
            {
                if(G->arcs[u][j]<INFINITY&&dist[u]+G->arcs[u][j]<dist[j])
                {
                    dist[j]=dist[u]+G->arcs[u][j];
                    path[j]=u;
                }
            }
        }
    }
    cout<<"最短路径结果如下"<<endl;
    showpath(G,dist,path,v);
}
//主函数；
int main()
{
    int i,j;
    Graph G;
    //创建图的邻接矩阵；
    creategraph(&G);
    shortpath_dij(&G,0);
}
//测试数据
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
9 9 9
//最后一行是结束标志，必须输入；
*/

