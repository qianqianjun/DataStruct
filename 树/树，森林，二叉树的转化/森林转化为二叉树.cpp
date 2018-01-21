#include<stdio.h>
#include<malloc.h>
#define DEGREE 5 //���ĸ߶�
#define NULL 0
#define QUEUESIZE 10
#define MAX_NODE_NUM 100
#define MAX_TREE_NUM 3//ɭ�������������Ŀ

//�ṹ������
//���ڵ������
typedef struct st1
{
    char data;//�����򣬲���char��
    struct st1 *children[DEGREE];//ָ���ӽڵ��ָ����
}CTreeNode;
//ɭ�ֵĽڵ�����
typedef struct ft
{
    CTreeNode *CTreesArray[MAX_TREE_NUM];//������ÿ�����ĸ��ڵ�
    int TreeNum;//������Ŀ
}ForestNode;
//���������Ľṹ������
typedef struct st2
{
    char data;//������
    struct st2 *lchild,*rchild;//���Һ��ӽڵ��ָ��
}BTreeNode;
//�����нṹ������
typedef struct nodeCTree
{
    CTreeNode *CTreeArray[MAX_NODE_NUM];//�ṹ��ָ�����飬��Žڵ�ĵ�ַ
    //struct nodeCTree *next;
    int CTreeFront,CTreeRear;
}QueueCTree;

//���������нṹ����
typedef struct nodeBTree
{
    BTreeNode *BTreeArray[MAX_NODE_NUM];//�ṹ��ָ�����飬��Žڵ�ĵ�ַ
    //struct nodeBTree *next;
        int BTreeFront,BTreeRear;
}QueueBTree;

//�������Ľڵ�
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
                returnNode=SearchCTree(root->children[i],data);//�ݹ����
                if(returnNode!=NULL)
                    return returnNode;
            }
        }
    }
}
//������
CTreeNode *CreateSTree()
{
    int i,j,k;
    char data, parent;;

    CTreeNode *root,*parentNode,*node;
    printf("���������Ľڵ������:");
    scanf("%d",&j);
    fflush(stdin);//������̻���
    if(j==0)
        return NULL;//��������������
    printf("��������ڵ������:");
    scanf("%c",&data);
    fflush(stdin);
    root=(CTreeNode *)malloc(sizeof(CTreeNode));
    root->data=data;
    for(i=0;i<DEGREE;i++)
        root->children[i]=NULL;
    for(i=2;i<=j;i++)//��������ÿ���ڵ����Ϣ
    {
        printf("�������%d���ڵ�����ݼ��丸�ڵ������:",i);
        scanf("%c%c",&data,&parent);//�мǵ���%c�Ÿ�ʽ��������ʱ�򣬲�Ҫ����ո�
        fflush(stdin);
        node=(CTreeNode *)malloc(sizeof(CTreeNode));
        node->data=data;
        for(k=0;k<DEGREE;k++)
            node->children[k]=NULL;
        //printf("��֤parent=%c\n",parent);
        parentNode=SearchCTree(root,parent);//����ָ�����ݵĽڵ�
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
//���ı���
void preorderTree(CTreeNode *ctroot)//����ÿ���ڵ�Ĳ�����������ýڵ��data��
{
    CTreeNode *ctchild;
    int i;
    printf("%c",ctroot->data);//�ȱ������ڵ�
    for(i=0;i<DEGREE;i++)//��������������ӽڵ�
    {
        ctchild=ctroot->children[i];
        if(ctchild==NULL)
            break;//���ӽڵ�����������˳�
        else
            preorderTree(ctchild);//�ݹ��������

    }

}


//��ʼ������
//��ʼ��������
void initQueueCTree(QueueCTree *&q)
{
    q=(QueueCTree *)malloc(sizeof(QueueCTree));
    q->CTreeFront=q->CTreeRear=0;

}
//��ʼ������������
void initQueueBTree(QueueBTree *&q)
{
    q=(QueueBTree *)malloc(sizeof(QueueBTree));
    q->BTreeFront=q->BTreeRear=0;

}
//�����
//������Ԫ�����
int addQueueCTree(QueueCTree *&q,CTreeNode *ctroot)//
{
    if((q->CTreeRear+1)%MAX_NODE_NUM==q->CTreeFront)//����
        return 0;
    q->CTreeRear=(q->CTreeRear+1)%MAX_NODE_NUM;
    q->CTreeArray[q->CTreeRear]=ctroot;
    return 1;//�����
}
//����������Ԫ�����
int addQueueBTree(QueueBTree *&q,BTreeNode *btroot)
{

    if((q->BTreeRear+1)%MAX_NODE_NUM==q->BTreeFront)//����
        return 0;
    q->BTreeRear=(q->BTreeRear+1)%MAX_NODE_NUM;
    q->BTreeArray[q->BTreeRear]=btroot;
    return 1;//�����

}
//�����п�
//���Ķ����п�
int QueueCTreeEmpty(QueueCTree *q)
{
    return(q->CTreeFront==q->CTreeRear);

}
//�����������п�
int QueueBTreeEmpty(QueueBTree *q)
{
    return(q->BTreeFront==q->BTreeRear);

}
//������
//������Ԫ�س���
CTreeNode *delQueueCTree(QueueCTree *&q)
{
    CTreeNode *ctroot;
    if(q->CTreeFront==q->CTreeRear)//�ӿ�
        return NULL;//���ؿ�ָ��
    q->CTreeFront=(q->CTreeFront+1)%MAX_NODE_NUM;
    ctroot=q->CTreeArray[q->CTreeFront];
    return ctroot;//���ؽڵ�

}
//����������Ԫ�س���
BTreeNode *delQueueBTree(QueueBTree *&q)
{
    BTreeNode *btroot;
    if(q->BTreeFront==q->BTreeRear)//�ӿ�
        return NULL;//���ؿ�ָ��
    q->BTreeFront=(q->BTreeFront+1)%MAX_NODE_NUM;
    btroot=q->BTreeArray[q->BTreeFront];
    return btroot;//���ؽڵ�

}
//��ת��Ϊ������
void TreeToBTree(CTreeNode *ctroot,BTreeNode *&btroot)//��ת��Ϊ������ctrootָ�����ĸ��ڵ㣬btroot,ָ��������ĸ�
{
    QueueCTree *VisitedCTreeNodes;
    QueueBTree *VisitedBTreeNodes;//��������
    initQueueCTree(VisitedCTreeNodes);
    initQueueBTree(VisitedBTreeNodes);//��ʼ������
    CTreeNode *ctnode;
    BTreeNode *btnode,*p,*LastSibling;
    int i;
    btroot=(BTreeNode *)malloc(sizeof(BTreeNode));//��ӿ����ڴ�ռ����
    btroot->data=ctroot->data;//���ĸ��ڵ���Ϊ�������ĸ��ڵ�
    btroot->lchild=btroot->rchild=NULL;


    addQueueCTree(VisitedCTreeNodes,ctroot);//���ĸ��ڵ����

    addQueueBTree(VisitedBTreeNodes,btroot);//�������ĸ��ڵ����

    while(!QueueCTreeEmpty(VisitedCTreeNodes))
    {
        ctnode=delQueueCTree(VisitedCTreeNodes);//���ڵ����

        btnode=delQueueBTree(VisitedBTreeNodes);//�������ڵ����

        for(i=0;i<DEGREE;i++)//���ʽڵ����еĺ��ӽڵ�
        {
            if(ctnode->children[i]==NULL)//���ӽڵ�������
                break;
            p=(BTreeNode *)malloc(sizeof(BTreeNode));//����������ڵ�
            p->data=ctnode->children[i]->data;

            p->lchild=p->rchild=NULL;
            if(i==0)
                btnode->lchild=p;//���ӣ���Ϊ���ڵ��������
            else
                LastSibling->rchild=p;//��Ϊ��һ���ֵܽڵ���Һ���
            LastSibling=p;

            addQueueCTree(VisitedCTreeNodes,ctnode->children[i]);//���ڵ������
            addQueueBTree(VisitedBTreeNodes,p);//�������ڵ���Ŷ���

        }


    }

}
//�������ı���
void Preorder(BTreeNode *T)
{
    if(T)
    {
        printf("%2c",T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}
//ɭ��ת��Ϊ���������㷨
void ForestToBTree(ForestNode *forest,BTreeNode *btroot)//f��ת����ɭ�֣�btroot,ָ��ת����Ķ������ĸ��ڵ�ָ��
{
    int i;
    BTreeNode *btrees[10];//��Ӧɭ���е�ÿ�����Ķ���������
    for(i=0;i<forest->TreeNum;i++)//����ת��ɭ���е�ÿ����
    {
        btrees[i]=(BTreeNode *)malloc(sizeof(BTreeNode));
        TreeToBTree(forest->CTreesArray[i],btrees[i]);//ת���ɶ�����
    }
    btroot=btrees[0];
    for(i=1;i<forest->TreeNum;i++)
    {
        btrees[i-1]->rchild=btrees[i];//��ÿ��ת����Ķ������ϲ���Ϊһ����
    }
    printf("ת����Ķ���������������Ľ��Ϊ:");
    Preorder(btroot);

}
int main()
{
    int i;
    ForestNode *forest;//ɭ�ֵĽڵ�����
    forest=(ForestNode *)malloc(sizeof(ForestNode));
    BTreeNode *btree;
    CTreeNode *Tree1,*Tree2,*Tree3;//������������
//  forest->CTreesArray[10]={Tree1,Tree2,Tree3};
    forest->CTreesArray[0]=Tree1;
    forest->CTreesArray[1]=Tree2;
    forest->CTreesArray[2]=Tree3;
    forest->TreeNum=sizeof(forest->CTreesArray)/sizeof(forest->CTreesArray[0]);//������Ŀ
    printf("forest->TreeNum=%d\n",forest->TreeNum);

    for(i=0;i<forest->TreeNum;i++)
    {
        printf("������i+1����%d\n",i+1);
        forest->CTreesArray[i]=CreateSTree();//����ÿ����
    }
    ForestToBTree(forest,btree);
    return 0;
}
