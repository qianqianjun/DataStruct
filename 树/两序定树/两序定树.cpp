#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
typedef char telemtype;
struct binode
{
	char data;
	struct binode *leftchild;
	struct binode *rightchild;
}BiNode,*BTree;
int printelement(telemtype e)
{
    putchar(e);
    return 1;
}
//利用先序和中序建立二叉树
int GetPostOrder(telemtype prim[],telemtype mid[],struct binode **T,int len)
{
	if(len==0)
	{
	    (*T)=NULL;
	}
	else
    {
        //提出先序序列中的第一个节点
        telemtype ch=prim[0];
        int index=0;
        //在中序序列中查找当前根节点，并用index记录其在序列中的位置
        while(mid[index]!=ch)
        {
            index++;
        }
        //给根节点分配空间
        (*T)=(struct binode*)malloc(sizeof(struct binode));
        (*T)->data=ch;
        //建立左子树
        GetPostOrder(prim+1,mid,&((*T)->leftchild),index);
        //建立右子树
        GetPostOrder(prim+index+1,mid+index+1,&((*T)->rightchild),len-index-1);
     }
     return 1;
}
//已知后序和中序，确定树的前序；i
int GetPreOrder(telemtype last[],telemtype mid[],struct binode**T,int len)
{
	if(len==0)
	{
	    (*T) = NULL;
	}
	else
	{
		//取出后序序列中的最后一个节点
		telemtype ch=last[len-1];
		int index=0;
		//在中序序列中进行查找根节点，并用index记录其在序列中的索引
		while(mid[index]!=ch)
		{
			index++;
		}
		(*T)=(struct binode*)malloc(sizeof(struct binode)); //给根节点分配空间
		(*T)->data=ch;
		GetPreOrder(last,mid,&((*T)->leftchild),index);//建立左子树
		GetPreOrder(last+index,mid+index+1,&((*T)->rightchild),len-index-1);//建立右子树
	 }
	 return 1;
}

int PostOrder(struct binode* T, int(*visit)(telemtype e))
{
    if (T!=NULL)
    {
        if (PostOrder(T->leftchild, visit))
            if (PostOrder(T->rightchild, visit))
                if (visit(T->data))
                    return 1;
        return 0;
    }
    else
        return 1;
}

int PreOrder(struct binode* T, int(*visit)(telemtype e))
{
    if (T!=NULL)
    {
        if (visit(T->data))
            if (PreOrder(T->leftchild, visit))
                if (PreOrder(T->rightchild, visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}
int main()
{
    int length;
    struct binode *T;
	telemtype first[26],mid[26],last[26];
	//先序和中序确定后序；
	printf("请输入树的先序表示和中序表示，中间用空格或回车隔开\n");
    scanf("%s%s",first,mid);
	length=strlen(first);
	GetPostOrder(first,mid,&T,length);
	printf("由您输入的先序和中序输出的:\n");
	PostOrder(T,printelement);
	printf("\n");

	//后序和中序确定先序；
	printf("请输入树的后序表示和中序表示，中间用空格或回车隔开\n");
    scanf("%s%s",last,mid);
	length=strlen(last);
	GetPreOrder(last,mid,&T,length);
	printf("由您输入的先序和中序输出的:\n");
	PreOrder(T,printelement);
	printf("\n");
	return 0;
}























/*
//先序输出二叉树
void PreOrder(BTree T)
{
	if(T!=NULL)
	{
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//后序输出二叉树
/*void PostOrder(BTree T)
{
	if(T!=NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
}*/




