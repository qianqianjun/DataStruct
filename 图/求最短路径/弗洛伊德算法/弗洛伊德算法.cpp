#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//�������Ľڵ�����
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
//�����ڽӾ��󣬴洢�ߵ�Ȩֵ��
void createarcell(Graph *G,int start,int ends,int weight)
{
    G->arcs[start][ends]=weight;
}
void creategraph(Graph *G)
{
    int i,j;
    int start=0,ends=0,weight;
    int num;
    cout<<"��������ͼ�����Ľڵ���Ŀ"<<endl;
    scanf("%d",&num);
    G->vexnum=num;
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j]=INFINITY;
    }
    cout<<"��������ߵ�����յ��Լ��ߵ�Ȩֵ"<<endl;
    while(start>=0&&start<G->vexnum&&ends>=0&&ends<G->vexnum)
    {
        scanf("%d%d%d",&start,&ends,&weight);
        createarcell(G,start,ends,weight);
    }
}
//������������ڵ�֮������·����
void showresult(Graph *G,int path[vertexnum][vertexnum],int dist[vertexnum][vertexnum])
{
    int i,j,pre,k,p[vertexnum],m;
    cout<<"��������֮������·��Ϊ:"<<endl<<endl;
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
                     printf("%d-->%d: ��·��\n",i,j);
                     break;
                 }
                 if(pre==i)
                 {
                     printf("%d-->%d: ",i,j);
                     printf("����:%d ",dist[i][j]);
                     printf("·����");
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
    int A[vertexnum][vertexnum];    //���ڴ洢ʼ�ڵ㵽�սڵ�����·���ĳ��ȣ�
    int path[vertexnum][vertexnum],i,j,k;   //���ڴ�Ŵ�ʼ�ڵ㵽�սڵ��·����
    //��ʼ����
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
    //���k�ڵ���Ϊ�м�ڵ�֮��Խ����Ӱ�죻
    for(k=0;k<G->vexnum;k++)
    {
        for(i=0;i<G->vexnum;i++)
        {
            for(j=0;j<G->vexnum;j++)
            {
                if(A[i][j]>A[i][k]+A[k][j])    //�ҵ�һ�����Ӷ̵�·����
                {
                    A[i][j]=A[i][k]+A[k][j];   //�滻Ϊ���Ӷ̵�·�����ȣ�
                    path[i][j]=path[k][j];   //�޸�·��Ϊ����k�ڵ㣻
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
//�������ݣ�
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
��һ��Ϊ�ڵ�����֮��������Ϊ�� ʼ�ڵ㣬�սڵ㣬Ȩֵ ��ʾ�ıߣ����һ���������ڽ������룻
*/
