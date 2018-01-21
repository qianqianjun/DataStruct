#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define vertexnum 6
typedef int infotype;
typedef int vrtype;
typedef int vertextype;
//定义邻接矩阵的元素结构体类型；
typedef struct vertexnodes
{
    vrtype adj;  //定义邻接矩阵的元素之间的关系，无权图用1，0表示临接与否，有权图表示权重。
    infotype *info;  //节点信息的指针；
}arcell,adjmartix[vertexnum][vertexnum];
typedef struct
{
    vertextype vexs[vertexnum];
    adjmartix arcs;
    int vexnum,arcnum;
}Mgraph;
struct close
{
    vertextype adjvex;
    vrtype lowcost;
}closedge[vertexnum];
void initgraph(Mgraph *G)
{
    G->vexnum=vertexnum;
    for(int i=0;i<vertexnum;i++)
    {
        G->vexs[i]=i+1;

        for(int j=0;j<vertexnum;j++)
            G->arcs[i][j].adj=101;
    }
}
void createarcell(Mgraph *G,int start,int ends,int weight)
{
    G->arcs[start-1][ends-1].adj=weight;
}
void creategraph(Mgraph *G)
{
    int start=1,ends=1,weight;
    cout<<"请您输入边的起点终点以及边的权值"<<endl;
    while(start>0&&start<=vertexnum&&ends>0&&ends<=vertexnum)
    {
        scanf("%d%d%d",&start,&ends,&weight);
        createarcell(G,start,ends,weight);
    }
}
/*
void display(Mgraph G)
{
    int i,j;
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
            cout<<G.arcs[i][j].adj<<' ';
        cout<<endl;
    }
}*/
int minnum(close closedge[vertexnum])
{
    int k,mins,j,i;
    mins=101;
 /*   for(j=0;j<vertexnum;j++)
    {
        if(closedge[j].lowcost!=0)
            {mins=closedge[j].lowcost;break;}
    }*/
     for(i=0;i<vertexnum;i++)
     {
         if(mins>closedge[i].lowcost&&closedge[i].lowcost!=0)
         {mins=closedge[i].lowcost;k=i;}
     }
     return k;
}
void mincosttree(Mgraph *G)
{
    int k=0;
    for(int j=0;j<G->vexnum;j++)
    {
        if(j!=k)
        {
            closedge[j].adjvex=G->vexs[k];
            closedge[j].lowcost=G->arcs[k][j].adj;
        }
    }
    closedge[k].lowcost=0;
    for(int i=1;i<G->vexnum;i++)
    {
        k=minnum(closedge);
        cout<<closedge[k].adjvex<<' '<<G->vexs[k]<<endl;
        closedge[k].lowcost=0;
        for(int j=0;j<G->vexnum;j++)
        {
            if(G->arcs[k][j].adj<closedge[j].lowcost)
            {
                closedge[j].adjvex=G->vexs[k];
                closedge[j].lowcost=G->arcs[k][j].adj;
            }
        }
    }
}
int main()
{
    int k;
    Mgraph G;
    initgraph(&G);
    creategraph(&G);
    cout<<"最小生成树的边为："<<endl;
    mincosttree(&G);
}
//测试数据；
/*
1 3 1
3 1 1
1 4 5
4 1 5
1 2 6
2 1 6
2 3 5
3 2 5
3 4 5
4 3 5
2 5 3
5 2 3
3 5 6
5 3 6
5 6 6
6 5 6
3 6 4
6 3 4
4 6 2
6 4 2
9 9 9
*/
