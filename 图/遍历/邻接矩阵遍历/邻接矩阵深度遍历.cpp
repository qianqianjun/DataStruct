#include <stdio.h>
#include <malloc.h>
//����ڵ�ĸ�����
#define vertexnum 5
//����ͼ
void createGraph(int (*edge)[vertexnum], int start, int ends)
{
        edge[start][ends] = 1;
}
//��ӡ�洢��ͼ
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
void DFTcore(int (*edge)[vertexnum],int i,int* vertexStatusArr)
{
    if(vertexStatusArr[i] == 1)
        return;
    printf("%d ",i);
    vertexStatusArr[i] = 1;
    int j;
    for(j=0;j<vertexnum;j++)
    {
        if(edge[i][j] == 1)
            DFTcore(edge, j, vertexStatusArr);
    }
}
//������ȱ���
void DFT(int (*edge)[vertexnum], int* vertexStatusArr)
{
    printf("��ȱ����Ľ��Ϊ:\n");
    int i;
    for(i=0;i<vertexnum;i++)
        DFTcore(edge,i,vertexStatusArr);
    printf("\n");
}
int main()
{
    //��̬������űߵĶ�λ���飻
    int (*edge)[vertexnum] = (int (*)[vertexnum])malloc(sizeof(int)*vertexnum*vertexnum);
    int i,j;
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
            edge[i][j] = 0;
    }
    //��Ŷ���ı���״̬��0��δ������1���ѱ���
    int* vertexStatusArr = (int*)malloc(sizeof(int)*vertexnum);
    for(i=0;i<vertexnum;i++)
        vertexStatusArr[i] = 0;
    //����ͼ
  //  createGraph(edge,0,3);
   // createGraph(edge,0,4);
   // createGraph(edge,3,1);
   // createGraph(edge,3,2);
   //createGraph(edge,4,1);
    printf("������������ڵ���ɵ�ͼ\n(����ÿ���ߵ�ʼĩ�ڵ㣬�ڵ��0��4,�������4�����ֽ�������)\n");
    int start=0,ends;
    while(start<5&&start>=0)
    {
        scanf("%d%d",&start,&ends);
        createGraph(edge,start,ends);
    }
    printf("ͼ���ڽӾ���Ϊ:\n");
    displayGraph(edge);
    //������ȱ���
    DFT(edge,vertexStatusArr);
    return 0;
}
