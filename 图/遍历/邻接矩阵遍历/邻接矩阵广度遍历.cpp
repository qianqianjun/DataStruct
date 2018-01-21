#include <stdio.h>
#include <malloc.h>
#include"link_queue.h"
#define vertexnum 4
//����ͼ���ڽӾ���
void createGraph(int (*edge)[vertexnum], int start, int ends)
{
        edge[start][ends] = 1;
}
//��ӡ�洢��ͼ���ڽӾ���
void displayGraph(int (*edge)[vertexnum])
{
    int i,j;
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
            printf("%d ",edge[i][j]);
        printf("\n");
    }
}
//��ͼ�Ĺ����������������
void BFSTraverse(int edge[vertexnum][vertexnum],sqqueue *q,int status[vertexnum])
{
    int i, j,k;
    for(i = 0; i <vertexnum; i++)  //��ÿһ��������ѭ��
    {
        if (status[i]!=1)    // ����δ���ʹ��ʹ���
        {
            status[i]=1;
            printf("%d ",i);        // ��ӡ���㣬Ҳ������������
            addqueue(q,i);          // ���˶��������
            while(!emptyqueue(q))   // ����ǰ���в�Ϊ��
            {
                k=delqueue(q);      // ����ͷԪ�س����У���ֵ��i
                for(j=0;j<vertexnum;j++)
                {
                    // �ж������������뵱ǰ������ڱ���δ���ʹ�
                    if(edge[k][j] == 1 && status[j]!=1)
                    {

                        status[j]=1;            //���ҵ��Ĵ˶�����Ϊ�ѷ���
                        printf("%d ",j);  // ��ӡ����
                        addqueue(q,j);              // ���ҵ��Ĵ˶��������
                    }
                }
            }
        }
     }
}
int main()
{
    //��̬������űߵĶ�λ���飻
    int (*edge)[vertexnum] = (int (*)[vertexnum])malloc(sizeof(int)*vertexnum*vertexnum);
    int i,j;
    sqqueue *q;
    sqqueue que;
    q=&que;
    initqueue(q);
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
            edge[i][j] = 0;
    }
    //��Ŷ���ı���״̬��0��δ������1���ѱ���
    int* status = (int*)malloc(sizeof(int)*vertexnum);
    for(i=0;i<vertexnum;i++)
        status[i] = 0;
    printf("������������ڵ���ɵ�ͼ\n(����ÿ���ߵ�ʼĩ�ڵ㣬�ڵ��0��4,�������4�����ֽ�������)\n");
    int start=0,ends;
    while(start<5&&start>=0)
    {
        scanf("%d%d",&start,&ends);
        createGraph(edge,start,ends);
    }
    printf("ͼ���ڽӾ���Ϊ:\n");
    displayGraph(edge);
    initqueue(q);
    printf("������������������Ϊ:\n");
    BFSTraverse(edge,q,status);
    return 0;
}
