#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;
#define vertexnum 20
int time=1,low[vertexnum],dfn[vertexnum];
int sqstack[vertexnum],top=0;
bool instack[vertexnum];
typedef struct arcnode
{
    int adjvex;
    struct arcnode *nextarc;
}arcnode;
//邻接表元素；
typedef struct vnode
{
    int data;
    arcnode *firstarc;
}vnode,adjlist[vertexnum];
typedef struct
{
    adjlist vertices;//存储图的邻接表，本程序用不到；
    int vexnum;//存储图的节点数；
    int arcs[vertexnum][vertexnum];//图的邻接矩阵；
}Graph;
void createlist(Graph *G)
{
    int square[vertexnum][vertexnum];
    int i,j;
    cout<<"请您输入节点的个数"<<endl;
    cin>>G->vexnum;
    cout<<"请您输入从那个节点到哪个节点之间有边,输入大于节点个数的数字结束输入"<<endl;
    int ends=1,start=1;
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
            square[i][j]=0;
    }
    //创建邻接矩阵；
    while(start>0&&start<=G->vexnum&&ends>0&&start<=G->vexnum)
    {
        scanf("%d%d",&start,&ends);
        square[start-1][ends-1]=1;
    }
    for(i=0;i<G->vexnum;i++)
    {
        G->vertices[i].data=i;
        G->vertices[i].firstarc=NULL;
    }
    arcnode *p,*p1;
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            if(square[i][j]==1)
            {
                if(G->vertices[i].firstarc==NULL)
                {
                    p1=(arcnode*)malloc(sizeof(arcnode));
                    p1->adjvex=j;
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
                    p1->adjvex=j;
                    p1->nextarc=NULL;
                    p->nextarc=p1;
                }
            }
        }
    }
}
int mins(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
//求图的联通分量；
void tarjan(int v,Graph* G)      //tarjan求强连通分支
{
    dfn[v]=low[v]=time;   //标记点v的DFS遍历序号
    time++;
    sqstack[top++]=v;             //将点v入栈
    instack[v]=true;            //标记点v已经在栈中
    for(arcnode *p=G->vertices[v].firstarc;p!=NULL;p=p->nextarc)    //遍历V能直接到达的点
        if(!dfn[p->adjvex])   //如果v的邻接点没有入过栈
        {
            tarjan(p->adjvex,G);
            low[v]=mins(low[v],low[p->adjvex]);    //如果v能直接到达的这个点没在栈中,v的最早祖先为他们中的较小值
        }
        else if(instack[p->adjvex])   //如果在栈中
            low[v]=mins(low[v],dfn[p->adjvex]);    //如果在栈中，则v的最早祖先是他的序号和那个点的序号较小的

    if(dfn[v]==low[v])      //如果dfn[v]和low[v]相等，则说明v点是其所属强连通分支DFS遍历起点，这个强连通分支说有点都在v点之上
    {
        cout<<"{ ";
        do
        {
            v=sqstack[--top];
            instack[v]=false;
            cout<<v<<' ';
        }while(dfn[v]!=low[v]);
        cout<<"}"<<endl;
    }
}
int main()
{
    Graph G;
    createlist(&G);
    int i,j;
    for(j=0;j<vertexnum;j++)
    {
        dfn[j]=0;
        instack[j]=false;
    }
    cout<<"强连通分量为："<<endl;
    for(i=0;i<G.vexnum;i++)
        if(!dfn[i])     //如果i没有入过栈
            tarjan(i,&G);
    return 0;
}

/*
测试数据；
6
1 3
1 2
4 1
2 4
3 4
3 5
5 6
4 6
9 9
*/
