#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
typedef int infotype;
typedef int vertextype;
#define INFINITY 10000
#define vertexnum 20
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
    int vexnum,edgenum;//存储图的节点数,边数；
    int arcs[vertexnum][vertexnum];//图的邻接矩阵；
}Graph;
typedef struct
{
    int u;
    int v;
    int w;
}edge;
//创建邻接矩阵，存储边的权值；
void createarcell(Graph *G,int start,int ends,int weight)
{
    G->arcs[start][ends]=weight;
}
//初始化一个图；
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
//这里是插入排序法，参考于网上博客；
void insertsort(edge E[vertexnum],int len)
{
    int i, j;
    edge temp;
    for(i=1;i<len;i++)
    {
        temp.w=E[i].w;
        temp.u=E[i].u;
        temp.v=E[i].v;
        for(j=i-1;j>=0;j--)
        {
            if(E[j].w>temp.w)
            {
                E[j+1].u=E[j].u;
                E[j+1].v=E[j].v;
                E[j+1].w=E[j].w;
            }
             //   E[j+1]=E[j];
            else
                break;
        }
        E[j+1].w=temp.w;
        E[j+1].u=temp.u;
        E[j+1].v=temp.v;
    }
}
//克鲁斯卡尔算法；
void kruskal(Graph *G)
{
    int i,j,u1,v1,sn1,sn2,k;
    int vset[vertexnum]; //存放联通分量编号；
    edge E[vertexnum];    //存放边的信息；
    k=0;
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            if(G->arcs[i][j]!=0&&G->arcs[i][j]!=INFINITY)
            {
                E[k].u=i;
                E[k].v=j;
                E[k].w=G->arcs[i][j];
                k++;
            }
        }
    }
    G->edgenum=k;
    insertsort(E,G->edgenum);  //插入排序法，并没有多了解啊。。。。
//    for(i=0;i<k;i++)
//        cout<<E[i].u<<' '<<E[i].v<<' '<<E[i].w<<endl;
    for(i=0;i<G->edgenum;i++)
        vset[i]=i;    //初始化节点所处连通分量的标号，最初都不一样，所以可以随便选择边；
    k=1;
    j=0;
    cout<<"生成的最小生成树边和边的权值如下："<<endl;
    while(k<G->vexnum)   //最小生成树的边应该为节点数减一；
    {
        u1=E[j].u;
        v1=E[j].v;
        sn1=vset[u1];
        sn2=vset[v1];
        if(sn1!=sn2)   //如果不构成回路的话
        {
            printf("(%d,%d):%d\n",u1,v1,E[j].w);   //输出对应的边和权值；
            k++;
            for(i=0;i<G->edgenum;i++)
            {
                if(vset[i]==sn2)
                    vset[i]=sn1;     //使现在的最小生成树的子树中的节点的连通分量的标号都相同；
            }
        }
        j++;
    }
}
int main()
{
    Graph G;
    creategraph(&G);
    kruskal(&G);
}

/*
测试数据：
7
0 5 1
0 1 9
1 2 4
1 0 9
1 6 3
2 1 4
2 3 2
3 2 2
3 4 6
3 6 5
4 3 6
4 6 7
4 5 8
5 4 8
5 0 1
6 4 7
6 1 3
6 3 5
9 9 9
*/
