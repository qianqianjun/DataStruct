#include<stdio.h>
#include<malloc.h>
#define DEGREE 5 //树的高度
#define NULL 0
#define QUEUESIZE 10
#define MAX_NODE_NUM 100
#define MAX_TREE_NUM 3//森林中树的最大数目

//结构体类型
//树节点的类型
typedef struct st1
{
    char data;//数据域，采用char星
    struct st1 *children[DEGREE];//指向孩子节点的指针域
}CTreeNode;
//森林的节点类型
typedef struct ft
{
    CTreeNode *CTreesArray[MAX_TREE_NUM];//数组存放每棵树的根节点
    int TreeNum;//树的数目
}ForestNode;
//二叉树树的结构体类型
typedef struct st2
{
    char data;//数据域
    struct st2 *lchild,*rchild;//左右孩子节点的指针
}BTreeNode;
//树队列结构体类型
typedef struct nodeCTree
{
    CTreeNode *CTreeArray[MAX_NODE_NUM];//结构体指针数组，存放节点的地址
    //struct nodeCTree *next;
    int CTreeFront,CTreeRear;
}QueueCTree;

//二叉树队列结构类型
typedef struct nodeBTree
{
    BTreeNode *BTreeArray[MAX_NODE_NUM];//结构体指针数组，存放节点的地址
    //struct nodeBTree *next;
        int BTreeFront,BTreeRear;
}QueueBTree;

//查找树的节点
CTreeNode *SearchCTree(CTreeNode *root ,char data)
{
    int i;
    CTreeNode *returnNode;
    if(root->data==data)
        return root;
    else
    {
        for(i=0;i<DEGREE;i++)
        {
            if(root->children[i]==NULL)
                return NULL;
            else
            {
                returnNode=SearchCTree(root->children[i],data);//递归查找
                if(returnNode!=NULL)
                    return returnNode;
            }
        }
    }
}
//生成树
CTreeNode *CreateSTree()
{
    int i,j,k;
    char data, parent;;

    CTreeNode *root,*parentNode,*node;
    printf("请输入树的节点的数量:");
    scanf("%d",&j);
    fflush(stdin);//清除键盘缓存
    if(j==0)
        return NULL;//空树，结束函数
    printf("请输入根节点的数据:");
    scanf("%c",&data);
    fflush(stdin);
    root=(CTreeNode *)malloc(sizeof(CTreeNode));
    root->data=data;
    for(i=0;i<DEGREE;i++)
        root->children[i]=NULL;
    for(i=2;i<=j;i++)//依次输入每个节点的信息
    {
        printf("请输入第%d个节点的数据及其父节点的数据:",i);
        scanf("%c%c",&data,&parent);//切记当以%c号格式输入数据时候，不要输入空格
        fflush(stdin);
        node=(CTreeNode *)malloc(sizeof(CTreeNode));
        node->data=data;
        for(k=0;k<DEGREE;k++)
            node->children[k]=NULL;
        //printf("验证parent=%c\n",parent);
        parentNode=SearchCTree(root,parent);//查找指定数据的节点
        for(k=0;k<DEGREE;k++)
        {
            if(parentNode->children[k]==NULL)
            {
                parentNode->children[k]=node;
                break;
            }
        }
    }
    return root;
}
//树的遍历
void preorderTree(CTreeNode *ctroot)//遍历每个节点的操作就是输出该节点的data域
{
    CTreeNode *ctchild;
    int i;
    printf("%c",ctroot->data);//先遍历根节点
    for(i=0;i<DEGREE;i++)//依次先序遍历孩子节点
    {
        ctchild=ctroot->children[i];
        if(ctchild==NULL)
            break;//孩子节点遍历结束，退出
        else
            preorderTree(ctchild);//递归先序遍历

    }

}


//初始化队列
//初始化树队列
void initQueueCTree(QueueCTree *&q)
{
    q=(QueueCTree *)malloc(sizeof(QueueCTree));
    q->CTreeFront=q->CTreeRear=0;

}
//初始化二叉树队列
void initQueueBTree(QueueBTree *&q)
{
    q=(QueueBTree *)malloc(sizeof(QueueBTree));
    q->BTreeFront=q->BTreeRear=0;

}
//入队列
//树队列元素入队
int addQueueCTree(QueueCTree *&q,CTreeNode *ctroot)//
{
    if((q->CTreeRear+1)%MAX_NODE_NUM==q->CTreeFront)//队满
        return 0;
    q->CTreeRear=(q->CTreeRear+1)%MAX_NODE_NUM;
    q->CTreeArray[q->CTreeRear]=ctroot;
    return 1;//入队列
}
//二叉树队列元素入队
int addQueueBTree(QueueBTree *&q,BTreeNode *btroot)
{

    if((q->BTreeRear+1)%MAX_NODE_NUM==q->BTreeFront)//队满
        return 0;
    q->BTreeRear=(q->BTreeRear+1)%MAX_NODE_NUM;
    q->BTreeArray[q->BTreeRear]=btroot;
    return 1;//入队列

}
//队列判空
//树的队列判空
int QueueCTreeEmpty(QueueCTree *q)
{
    return(q->CTreeFront==q->CTreeRear);

}
//二叉树队列判空
int QueueBTreeEmpty(QueueBTree *q)
{
    return(q->BTreeFront==q->BTreeRear);

}
//出队列
//树队列元素出队
CTreeNode *delQueueCTree(QueueCTree *&q)
{
    CTreeNode *ctroot;
    if(q->CTreeFront==q->CTreeRear)//队空
        return NULL;//返回空指针
    q->CTreeFront=(q->CTreeFront+1)%MAX_NODE_NUM;
    ctroot=q->CTreeArray[q->CTreeFront];
    return ctroot;//返回节点

}
//二叉树队列元素出队
BTreeNode *delQueueBTree(QueueBTree *&q)
{
    BTreeNode *btroot;
    if(q->BTreeFront==q->BTreeRear)//队空
        return NULL;//返回空指针
    q->BTreeFront=(q->BTreeFront+1)%MAX_NODE_NUM;
    btroot=q->BTreeArray[q->BTreeFront];
    return btroot;//返回节点

}
//树转化为二叉树
void TreeToBTree(CTreeNode *ctroot,BTreeNode *&btroot)//树转化为二叉树ctroot指向树的根节点，btroot,指向二叉树的跟
{
    QueueCTree *VisitedCTreeNodes;
    QueueBTree *VisitedBTreeNodes;//辅助队列
    initQueueCTree(VisitedCTreeNodes);
    initQueueBTree(VisitedBTreeNodes);//初始化队列
    CTreeNode *ctnode;
    BTreeNode *btnode,*p,*LastSibling;
    int i;
    btroot=(BTreeNode *)malloc(sizeof(BTreeNode));//添加开辟内存空间语句
    btroot->data=ctroot->data;//树的根节点作为二叉树的根节点
    btroot->lchild=btroot->rchild=NULL;


    addQueueCTree(VisitedCTreeNodes,ctroot);//树的跟节点入队

    addQueueBTree(VisitedBTreeNodes,btroot);//二叉树的跟节点入队

    while(!QueueCTreeEmpty(VisitedCTreeNodes))
    {
        ctnode=delQueueCTree(VisitedCTreeNodes);//树节点出队

        btnode=delQueueBTree(VisitedBTreeNodes);//二叉树节点出队

        for(i=0;i<DEGREE;i++)//访问节点所有的孩子节点
        {
            if(ctnode->children[i]==NULL)//孩子节点访问完毕
                break;
            p=(BTreeNode *)malloc(sizeof(BTreeNode));//分配二叉树节点
            p->data=ctnode->children[i]->data;

            p->lchild=p->rchild=NULL;
            if(i==0)
                btnode->lchild=p;//长子，作为父节点的做孩子
            else
                LastSibling->rchild=p;//作为上一个兄弟节点的右孩子
            LastSibling=p;

            addQueueCTree(VisitedCTreeNodes,ctnode->children[i]);//树节点进队列
            addQueueBTree(VisitedBTreeNodes,p);//二叉树节点进门队列

        }


    }

}
//二叉树的遍历
void Preorder(BTreeNode *T)
{
    if(T)
    {
        printf("%2c",T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}
//森林转化为二叉树的算法
void ForestToBTree(ForestNode *forest,BTreeNode *btroot)//f待转换的森林，btroot,指向转换后的二叉树的根节点指针
{
    int i;
    BTreeNode *btrees[10];//对应森林中的每棵树的二叉树数组
    for(i=0;i<forest->TreeNum;i++)//依次转换森林中的每棵树
    {
        btrees[i]=(BTreeNode *)malloc(sizeof(BTreeNode));
        TreeToBTree(forest->CTreesArray[i],btrees[i]);//转换成二叉树
    }
    btroot=btrees[0];
    for(i=1;i<forest->TreeNum;i++)
    {
        btrees[i-1]->rchild=btrees[i];//把每棵转换后的二叉树合并成为一棵树
    }
    printf("转换后的二叉树，先序遍历的结果为:");
    Preorder(btroot);

}
int main()
{
    int i;
    ForestNode *forest;//森林的节点声明
    forest=(ForestNode *)malloc(sizeof(ForestNode));
    BTreeNode *btree;
    CTreeNode *Tree1,*Tree2,*Tree3;//假如有三棵树
//  forest->CTreesArray[10]={Tree1,Tree2,Tree3};
    forest->CTreesArray[0]=Tree1;
    forest->CTreesArray[1]=Tree2;
    forest->CTreesArray[2]=Tree3;
    forest->TreeNum=sizeof(forest->CTreesArray)/sizeof(forest->CTreesArray[0]);//树的数目
    printf("forest->TreeNum=%d\n",forest->TreeNum);

    for(i=0;i<forest->TreeNum;i++)
    {
        printf("创建第i+1棵树%d\n",i+1);
        forest->CTreesArray[i]=CreateSTree();//创建每棵树
    }
    ForestToBTree(forest,btree);
    return 0;
}
