#include <stdio.h>
#include <malloc.h>
#include"link_queue.h"
#define vertexnum 4
//创建图的邻接矩阵；
void createGraph(int (*edge)[vertexnum], int start, int ends)
{
        edge[start][ends] = 1;
}
//打印存储的图的邻接矩阵；
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
//对图的广度优先搜索遍历；
void BFSTraverse(int edge[vertexnum][vertexnum],sqqueue *q,int status[vertexnum])
{
    int i, j,k;
    for(i = 0; i <vertexnum; i++)  //对每一个顶点做循环
    {
        if (status[i]!=1)    // 若是未访问过就处理
        {
            status[i]=1;
            printf("%d ",i);        // 打印顶点，也可以其它操作
            addqueue(q,i);          // 将此顶点入队列
            while(!emptyqueue(q))   // 若当前队列不为空
            {
                k=delqueue(q);      // 将队头元素出队列，赋值给i
                for(j=0;j<vertexnum;j++)
                {
                    // 判断其它顶点若与当前顶点存在边且未访问过
                    if(edge[k][j] == 1 && status[j]!=1)
                    {

                        status[j]=1;            //将找到的此顶点标记为已访问
                        printf("%d ",j);  // 打印顶点
                        addqueue(q,j);              // 将找到的此顶点入队列
                    }
                }
            }
        }
     }
}
int main()
{
    //动态创建存放边的二位数组；
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
    //存放顶点的遍历状态，0：未遍历，1：已遍历
    int* status = (int*)malloc(sizeof(int)*vertexnum);
    for(i=0;i<vertexnum;i++)
        status[i] = 0;
    printf("请输入由五个节点组成的图\n(输入每条边的始末节点，节点从0到4,输入大于4的数字结束输入)\n");
    int start=0,ends;
    while(start<5&&start>=0)
    {
        scanf("%d%d",&start,&ends);
        createGraph(edge,start,ends);
    }
    printf("图的邻接矩阵为:\n");
    displayGraph(edge);
    initqueue(q);
    printf("广度优先搜索遍历结果为:\n");
    BFSTraverse(edge,q,status);
    return 0;
}
