#include <stdio.h>
#include <malloc.h>
//定义节点的个数；
#define vertexnum 5
//创建图
void createGraph(int (*edge)[vertexnum], int start, int ends)
{
        edge[start][ends] = 1;
}
//打印存储的图
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
//深度优先遍历
void DFT(int (*edge)[vertexnum], int* vertexStatusArr)
{
    printf("深度遍历的结果为:\n");
    int i;
    for(i=0;i<vertexnum;i++)
        DFTcore(edge,i,vertexStatusArr);
    printf("\n");
}
int main()
{
    //动态创建存放边的二位数组；
    int (*edge)[vertexnum] = (int (*)[vertexnum])malloc(sizeof(int)*vertexnum*vertexnum);
    int i,j;
    for(i=0;i<vertexnum;i++)
    {
        for(j=0;j<vertexnum;j++)
            edge[i][j] = 0;
    }
    //存放顶点的遍历状态，0：未遍历，1：已遍历
    int* vertexStatusArr = (int*)malloc(sizeof(int)*vertexnum);
    for(i=0;i<vertexnum;i++)
        vertexStatusArr[i] = 0;
    //创建图
  //  createGraph(edge,0,3);
   // createGraph(edge,0,4);
   // createGraph(edge,3,1);
   // createGraph(edge,3,2);
   //createGraph(edge,4,1);
    printf("请输入由五个节点组成的图\n(输入每条边的始末节点，节点从0到4,输入大于4的数字结束输入)\n");
    int start=0,ends;
    while(start<5&&start>=0)
    {
        scanf("%d%d",&start,&ends);
        createGraph(edge,start,ends);
    }
    printf("图的邻接矩阵为:\n");
    displayGraph(edge);
    //深度优先遍历
    DFT(edge,vertexStatusArr);
    return 0;
}
