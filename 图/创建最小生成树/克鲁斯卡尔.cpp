#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
typedef int infotype;
typedef int vertextype;
#define INFINITY 10000
#define vertexnum 20
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
    int vexnum,edgenum;//�洢ͼ�Ľڵ���,������
    int arcs[vertexnum][vertexnum];//ͼ���ڽӾ���
}Graph;
typedef struct
{
    int u;
    int v;
    int w;
}edge;
//�����ڽӾ��󣬴洢�ߵ�Ȩֵ��
void createarcell(Graph *G,int start,int ends,int weight)
{
    G->arcs[start][ends]=weight;
}
//��ʼ��һ��ͼ��
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
//�����ǲ������򷨣��ο������ϲ��ͣ�
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
//��³˹�����㷨��
void kruskal(Graph *G)
{
    int i,j,u1,v1,sn1,sn2,k;
    int vset[vertexnum]; //�����ͨ������ţ�
    edge E[vertexnum];    //��űߵ���Ϣ��
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
    insertsort(E,G->edgenum);  //�������򷨣���û�ж��˽Ⱑ��������
//    for(i=0;i<k;i++)
//        cout<<E[i].u<<' '<<E[i].v<<' '<<E[i].w<<endl;
    for(i=0;i<G->edgenum;i++)
        vset[i]=i;    //��ʼ���ڵ�������ͨ�����ı�ţ��������һ�������Կ������ѡ��ߣ�
    k=1;
    j=0;
    cout<<"���ɵ���С�������ߺͱߵ�Ȩֵ���£�"<<endl;
    while(k<G->vexnum)   //��С�������ı�Ӧ��Ϊ�ڵ�����һ��
    {
        u1=E[j].u;
        v1=E[j].v;
        sn1=vset[u1];
        sn2=vset[v1];
        if(sn1!=sn2)   //��������ɻ�·�Ļ�
        {
            printf("(%d,%d):%d\n",u1,v1,E[j].w);   //�����Ӧ�ıߺ�Ȩֵ��
            k++;
            for(i=0;i<G->edgenum;i++)
            {
                if(vset[i]==sn2)
                    vset[i]=sn1;     //ʹ���ڵ���С�������������еĽڵ����ͨ�����ı�Ŷ���ͬ��
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
�������ݣ�
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
