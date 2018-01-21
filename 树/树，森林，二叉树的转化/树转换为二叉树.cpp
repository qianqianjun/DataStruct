#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
//���к��ӽ�������ĵ�������
typedef struct TreeLinkNode
{
    int index;
    struct TreeLinkNode *next;
} TreeLinkNode,*pTreeLinkNode;
//���������㣨����㣩
typedef struct TreeNode
{
    pTreeLinkNode link;
    int data;
} TreeNode,*pTreeNode;
//ɭ�ֽ��
typedef struct FTreeNode
{
    pTreeNode tree;
    struct FTreeNode *next;
} FTreeNode,*pFTreeNode;
//ɭ������ĳ�ʼ������
void InitFTree(pFTreeNode &fTree)
{
    fTree = (pFTreeNode)malloc(sizeof(FTreeNode));
    fTree->next = NULL;
}
//ɭ������Ĳ������
void InsertFTree(pFTreeNode &fTree,pTreeNode node)
{
    pFTreeNode t_node = fTree;
    pFTreeNode newnode  = (pFTreeNode)malloc(sizeof(FTreeNode));

    while(t_node->next != NULL)
    {
        t_node = t_node->next;
    }

    newnode->tree = node;
    t_node->next = newnode;
    newnode->next = NULL;
}
//���������������������
void GListToTree(pTreeNode &tree,int &current_index,int parent_index)
{
    char ch;
    pTreeLinkNode newnode;

    pTreeLinkNode link = (pTreeLinkNode)malloc(sizeof(TreeLinkNode));
    link->index = current_index;
    link->next = NULL;
    tree[parent_index].link = link;

    while(true)
    {
        scanf("%c",&ch);

        if(ch == '(')
        {
            parent_index = current_index;
            current_index ++;
            scanf("%d",&tree[current_index].data);
            tree[current_index].link = NULL;

            GListToTree(tree,current_index,parent_index);
        }
        else if(ch == ',')
        {
            current_index ++;
            scanf("%d",&tree[current_index].data);
            tree[current_index].link = NULL;

            newnode = (pTreeLinkNode)malloc(sizeof(TreeLinkNode));
            newnode->index = current_index;
            newnode->next = NULL;
            link->next = newnode;
            link = link->next;
        }
        else
        {
            return;
        }
    }
}
//������齨��ɭ������
void GListToFTree(pFTreeNode &fTree)
{
    char ch;
    int current_index,parent_index;
    pTreeNode tree;
    scanf("%c",&ch);

    while(ch != '#')
    {
        current_index = -1;
        tree=(pTreeNode)malloc(50*sizeof(TreeNode));

        current_index ++;
        scanf("%d",&tree[current_index].data);
        tree[current_index].link = NULL;

        scanf("%c",&ch);

        if(ch != ')')
        {
            parent_index = current_index;
            current_index ++;
            scanf("%d",&tree[current_index].data);
            tree[current_index].link = NULL;

            GListToTree(tree,current_index,parent_index);
            scanf("%c",&ch);
        }

        InsertFTree(fTree,tree);
        scanf("%c",&ch);
    }
}
//�洢����������м�¼�ĵ�������
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode,*pLinkNode;
//������ĳ�ʼ��
void InitLinkList(pLinkNode &link)
{
    link=(pLinkNode)malloc(sizeof(LinkNode));
    link->next =NULL;
}
//������Ľ���
void CreateLinkList(pLinkNode &link,int m)
{
    int i;
    pLinkNode newnode,p_Link=link;

    printf("�����������������:");
    for(i=0; i<m; i++)
    {
        newnode=(pLinkNode)malloc(sizeof(LinkNode));
        scanf("%d",&newnode->data);
        newnode->next =NULL;
        p_Link->next =newnode;
        p_Link = p_Link->next;
    }
}
//�������ͷɾ
void DeleteFirst(pLinkNode &link)
{
    pLinkNode p_Link=link->next ;
    if(p_Link != NULL)
    {
        link->next =p_Link->next ;
        free(p_Link);
    }
}
//�洢����������е�˫��������
typedef struct DuLinkNode
{
    int data;
    bool isVisited;
    struct DuLinkNode *next;
    struct DuLinkNode *prior;
} DuLinkNode,*pDuLinkNode;
//˫������ĳ�ʼ��
void InitDuLinkList(pDuLinkNode &DuLink)
{
    DuLink=(pDuLinkNode)malloc(sizeof(DuLinkNode));
    DuLink->isVisited = true;
    DuLink->prior =NULL;
    DuLink->next =(pDuLinkNode)malloc(sizeof(DuLinkNode));
    DuLink->next->prior=DuLink;
    DuLink->next ->isVisited = true;
    DuLink->next ->next =NULL;
}
//˫������Ľ���
void CreateDuLinkList(pDuLinkNode &DuLink,int m)
{
    int i;
    pDuLinkNode newnode,p_DuLink=DuLink;

    printf("�����������������:");
    for (i=0; i<m; i++)
    {
        newnode = (pDuLinkNode)malloc(sizeof(DuLinkNode));
        scanf("%d",&newnode->data);
        newnode->isVisited = false;
        newnode->next = p_DuLink->next ;
        p_DuLink->next ->prior = newnode;
        newnode->prior = p_DuLink;
        p_DuLink->next = newnode;

        p_DuLink = p_DuLink->next;
    }
}
//���������
typedef struct BiTreeNode
{
    int data;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
} BiTreeNode,*pBiTreeNode;
//������
typedef struct BiTree
{
    pBiTreeNode tree;
} BiTree;
//��������ʼ��
void InitBiTree(BiTree &biTree)
{
    biTree.tree = NULL;
}
//���������ؽ�������
void CreateBiTree(pBiTreeNode &biTree,pLinkNode &link,
                  pDuLinkNode &DuLink)
{
    pLinkNode p_Link = link->next;
    pDuLinkNode p_DuLink = DuLink->next;
    if(p_Link != NULL)
    {
        biTree = (pBiTreeNode)malloc(sizeof(BiTreeNode));
        biTree->left = NULL;
        biTree->right = NULL;
        biTree->data = p_Link->data ;

        while(p_Link->data != p_DuLink->data)
        {
            p_DuLink = p_DuLink->next;
        }

        p_DuLink->isVisited = true;
        DeleteFirst(link);
        if(p_DuLink->prior->isVisited == false)
        {
            CreateBiTree(biTree->left,link,DuLink);
        }
        if(p_DuLink->next ->isVisited == false)
        {
            CreateBiTree(biTree->right,link,DuLink);
        }
    }
}
//������ת��Ϊ�����Ƕ�����ת��Ϊɭ�ֵ��Ӻ���
void BiTreeToTree(pTreeNode &tree,pBiTreeNode &biTree,
                  int &current_index,int parent_index)
{
    pBiTreeNode p_biTree = biTree->left;
    pTreeLinkNode newnode;

    if(p_biTree != NULL)
    {
        current_index ++;
        tree[current_index].data = p_biTree->data;
        tree[current_index].link = NULL;

        newnode = (pTreeLinkNode)malloc(sizeof(TreeLinkNode));
        newnode->index = current_index;
        newnode->next = NULL;
        tree[parent_index].link = newnode;

        BiTreeToTree(tree,p_biTree,current_index,newnode->index);

        while(p_biTree->right != NULL)
        {
            p_biTree = p_biTree->right;

            current_index ++;
            tree[current_index].data = p_biTree->data;
            tree[current_index].link = NULL;

            newnode->next = (pTreeLinkNode)malloc(sizeof(TreeLinkNode));
            newnode = newnode->next;
            newnode->index = current_index;
            newnode->next = NULL;

            BiTreeToTree(tree,p_biTree,current_index,newnode->index);
        }
    }
}
//������ת��Ϊɭ��
void BiTreetoFTree(pFTreeNode &fTree,pBiTreeNode &biTree)
{
    int current_index,parent_index;
    pTreeNode newnode;
    pBiTreeNode p_biTree = biTree;

    do
    {
        newnode = (pTreeNode)malloc(sizeof(TreeNode) * 50);

        current_index = 0 ;
        parent_index = current_index;
        newnode[current_index].data = p_biTree->data;
        newnode[current_index].link = NULL;

        BiTreeToTree(newnode,p_biTree,current_index,parent_index);
        InsertFTree(fTree,newnode);

        p_biTree = p_biTree->right;
    }
    while(p_biTree != NULL);
}
//��ת��Ϊ����������ɭ��ת��Ϊ���������Ӻ���
void TreeToBiTree(pTreeNode &tree,pBiTreeNode &biTree,int index)
{
    pBiTreeNode newnode = (pBiTreeNode)malloc(sizeof(BiTreeNode));
    newnode->data = tree[index].data;
    newnode->left = NULL;
    newnode->right = NULL;
    biTree = newnode;

    pTreeLinkNode link = tree[index].link;
    pBiTreeNode tempNode = biTree;

    if(link != NULL)
    {
        TreeToBiTree(tree,tempNode->left,link->index);
        link = link->next;
        tempNode = tempNode->left;
        while(link != NULL)
        {
            TreeToBiTree(tree,tempNode->right,link->index);
            link = link->next;
            tempNode = tempNode->right;
        }
    }
}
//ɭ��ת��Ϊ������
void FTreeToBiTree(pFTreeNode &fTree,BiTree &biTree)
{
    pFTreeNode p_fTree = fTree->next;
    pBiTreeNode p_biTree = biTree.tree;

    while(p_fTree != NULL)
    {
        if(biTree.tree == NULL)
        {
            TreeToBiTree(p_fTree->tree,biTree.tree,0);
            p_biTree = biTree.tree;
        }
        else
        {
            TreeToBiTree(p_fTree->tree,p_biTree->right,0);
            p_biTree = p_biTree->right;
        }
        p_fTree = p_fTree->next;
    }
}
//��ת��Ϊ�������ɭ��ת��Ϊ�������Ӻ���
void TreeToGList(pTreeNode &tree,int parent_index)
{
    pTreeLinkNode p_treeLink = tree[parent_index].link;

    if(p_treeLink != NULL)
    {
        printf("(");
        printf("%d",tree[p_treeLink->index].data);
        TreeToGList(tree,p_treeLink->index);
        p_treeLink = p_treeLink->next;

        while(p_treeLink != NULL)
        {
            printf(",");
            printf("%d",tree[p_treeLink->index].data);
            TreeToGList(tree,p_treeLink->index);

            p_treeLink = p_treeLink->next;
        }

        printf(")");
    }
}
//ɭ��ת��Ϊ�����
void FTreeToGList(pFTreeNode &fTree)
{
    int parent_index;
    pFTreeNode p_fTree = fTree->next;

    while(p_fTree != NULL)
    {
        parent_index = 0;

        printf("(");
        printf("%d",p_fTree->tree[0].data);
        TreeToGList(p_fTree->tree,parent_index);
        printf(")");

        p_fTree = p_fTree->next;
    }
    printf("#");
}
//�����ȸ���������ɭ�ֵ��ȸ��������Ӻ���
void TreePreTraverse(pTreeNode &tree,int index)
{
    pTreeLinkNode link ;
    printf("%d ",tree[index].data);

    link = tree[index].link;
    while(link != NULL)
    {
        TreePreTraverse(tree,link->index);
        link = link->next;
    }
}
//ɭ�ֵ��ȸ�����
void FTreePreTraverse(pFTreeNode &fTree)
{
    pFTreeNode link = fTree->next;
    while(link != NULL)
    {
        TreePreTraverse(link->tree,0);
        link = link->next;
    }
}
//���ĺ����������ɭ�ֵĺ���������Ӻ���
void TreePostTraverse(pTreeNode &tree,int index)
{
    pTreeLinkNode link ;

    link = tree[index].link;
    while(link != NULL)
    {
        TreePostTraverse(tree,link->index);
        link = link->next;
    }
    printf("%d ",tree[index].data);
}
//ɭ�ֵĺ������
void FTreePostTraverse(pFTreeNode &fTree)
{
    pFTreeNode link = fTree->next;
    while(link != NULL)
    {
        TreePostTraverse(link->tree,0);
        link = link->next;
    }
}
//���������������
void BiTreePreTraverse(pBiTreeNode &tree)
{
    if(tree != NULL)
    {
        printf("%d ",tree->data);

        if(tree->left != NULL)
        {
            BiTreePreTraverse(tree->left);
        }

        if(tree->right != NULL)
        {
            BiTreePreTraverse(tree->right);
        }
    }
}
//���������������
void BiTreeInOrderTraverse(pBiTreeNode &tree)
{
    if(tree !=NULL)
    {
        if(tree->left != NULL)
        {
            BiTreeInOrderTraverse(tree->left);
        }

        printf("%d ",tree->data);

        if(tree->right != NULL)
        {
            BiTreeInOrderTraverse(tree->right);
        }
    }
}
//������
int main(void)
{


    printf("\n##################################################################\n");
    printf("\n����ɭ�֣��Ĺ�������ű�ʾ�����ؽ�����ɭ�֣�\n");
    printf("����������ɭ�֣��Ĺ�������ű�ʾ��������#��������\n");

    pFTreeNode fTree1;
    InitFTree(fTree1);
    GListToFTree(fTree1);

    printf("\n����ɭ�֣��Ĺ�������ű�ʾ�����ؽ�����ɭ�֣���ı���\n");
    printf("����ɭ�֣����ȸ�������\n");
    FTreePreTraverse(fTree1);
    printf("\n");
    printf("����ɭ�֣��ĺ��������\n");
    FTreePostTraverse(fTree1);
    printf("\n");

    printf("\n##################################################################\n");
    printf("\n����ɭ�֣�ת���ɶ�������\n\n");
    BiTree biTree1;
    InitBiTree(biTree1);
    FTreeToBiTree(fTree1,biTree1);

    printf("����ɭ�֣�ת���ɶ�������������ı���\n");
    printf("����ɭ�֣�ת���ɵĶ����������������\n");
    BiTreePreTraverse(biTree1.tree);
    printf("\n����ɭ�֣�ת���ɵĶ����������������\n");
    BiTreeInOrderTraverse(biTree1.tree);
    printf("\n");

    printf("\n##################################################################\n");
    printf("\n����������������к�����������������ؽ���������\n");
    int m;
    printf("������������Ľ������");
    scanf("%d",&m);

    pLinkNode link;
    InitLinkList(link);
    CreateLinkList(link,m);

    pDuLinkNode DuLink;
    InitDuLinkList(DuLink);
    CreateDuLinkList(DuLink,m);

    BiTree biTree2;
    InitBiTree(biTree2);
    CreateBiTree(biTree2.tree,link,DuLink);

    printf("\n�ؽ�������������������\n");
    BiTreePreTraverse(biTree2.tree);
    printf("\n�ؽ�������������������\n");
    BiTreeInOrderTraverse(biTree2.tree);
    printf("\n");

    printf("\n##################################################################\n");
    pFTreeNode fTree2;
    InitFTree(fTree2);

    printf("\n�ؽ��Ķ�����ת��������ɭ�֣���\n\n");
    BiTreetoFTree(fTree2,biTree2.tree);
    printf("�ؽ��Ķ�����ת��������ɭ�֣�������ɭ�֣��ı�����\n");
    printf("����ɭ�֣����ȸ�������\n");
    FTreePreTraverse(fTree2);
    printf("\n����ɭ�֣��ĺ��������\n");
    FTreePostTraverse(fTree2);
    printf("\n\n");

    printf("##################################################################\n");
    printf("\n�������ɵ���(ɭ��)��������Ӧ�Ĺ�������ű�ʾ����\n");
    FTreeToGList(fTree2);
    printf("\n\n##################################################################\n");

    return 0;
}
