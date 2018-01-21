#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
#define vertexnum 20
#define INFINITY 10000
typedef int infotype;
typedef int vertextype;
using namespace std;
//ͼ�Ĵ洢�ṹ�������ڽӾ���洢��
typedef struct arcnode
{
    int adjvex;
    struct arcnode *nextarc;
    infotype *info;
}arcnode;
//�ڽӱ�Ԫ�أ�
typedef struct vnode
{
    vertextype data;
    arcnode *firstarc;
}vnode,adjlist[vertexnum];
typedef struct
{
    adjlist vertices;//�洢ͼ���ڽӱ��������ò�����
    int vexnum;//�洢ͼ�Ľڵ�����
    int arcs[vertexnum][vertexnum];//ͼ���ڽӾ���
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
//������·�����У�
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
                    printf(" ����Ϊ:%3d ",dist[i]);
                    printf("·��Ϊ��");
                    printf("%d  ",v);
                    for(j=k-1;j>=0;j--)
                        printf("%d  ",p[j]);
                    printf("%d\n",i);
                    break;
                }
                if(pre==-1)
                {
                    printf("��·��\n");
                    break;
                }
                p[k]=pre;
                pre=path[p[k]];
                k++;
            }
        }
    }
}
//�Ͻ�˹�����㷨ʵ�֣�
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
    cout<<"���·���������"<<endl;
    showpath(G,dist,path,v);
}
//��������
int main()
{
    int i,j;
    Graph G;
    //����ͼ���ڽӾ���
    creategraph(&G);
    shortpath_dij(&G,0);
}
//��������
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
//���һ���ǽ�����־���������룻
*/

