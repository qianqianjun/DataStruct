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
//�ڽӱ�Ԫ�أ�
typedef struct vnode
{
    int data;
    arcnode *firstarc;
}vnode,adjlist[vertexnum];
typedef struct
{
    adjlist vertices;//�洢ͼ���ڽӱ��������ò�����
    int vexnum;//�洢ͼ�Ľڵ�����
    int arcs[vertexnum][vertexnum];//ͼ���ڽӾ���
}Graph;
void createlist(Graph *G)
{
    int square[vertexnum][vertexnum];
    int i,j;
    cout<<"��������ڵ�ĸ���"<<endl;
    cin>>G->vexnum;
    cout<<"����������Ǹ��ڵ㵽�ĸ��ڵ�֮���б�,������ڽڵ���������ֽ�������"<<endl;
    int ends=1,start=1;
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
            square[i][j]=0;
    }
    //�����ڽӾ���
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
//��ͼ����ͨ������
void tarjan(int v,Graph* G)      //tarjan��ǿ��ͨ��֧
{
    dfn[v]=low[v]=time;   //��ǵ�v��DFS�������
    time++;
    sqstack[top++]=v;             //����v��ջ
    instack[v]=true;            //��ǵ�v�Ѿ���ջ��
    for(arcnode *p=G->vertices[v].firstarc;p!=NULL;p=p->nextarc)    //����V��ֱ�ӵ���ĵ�
        if(!dfn[p->adjvex])   //���v���ڽӵ�û�����ջ
        {
            tarjan(p->adjvex,G);
            low[v]=mins(low[v],low[p->adjvex]);    //���v��ֱ�ӵ���������û��ջ��,v����������Ϊ�����еĽ�Сֵ
        }
        else if(instack[p->adjvex])   //�����ջ��
            low[v]=mins(low[v],dfn[p->adjvex]);    //�����ջ�У���v������������������ź��Ǹ������Ž�С��

    if(dfn[v]==low[v])      //���dfn[v]��low[v]��ȣ���˵��v����������ǿ��ͨ��֧DFS������㣬���ǿ��ͨ��֧˵�е㶼��v��֮��
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
    cout<<"ǿ��ͨ����Ϊ��"<<endl;
    for(i=0;i<G.vexnum;i++)
        if(!dfn[i])     //���iû�����ջ
            tarjan(i,&G);
    return 0;
}

/*
�������ݣ�
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
