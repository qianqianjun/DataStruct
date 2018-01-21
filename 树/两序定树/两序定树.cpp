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
//���������������������
int GetPostOrder(telemtype prim[],telemtype mid[],struct binode **T,int len)
{
	if(len==0)
	{
	    (*T)=NULL;
	}
	else
    {
        //������������еĵ�һ���ڵ�
        telemtype ch=prim[0];
        int index=0;
        //�����������в��ҵ�ǰ���ڵ㣬����index��¼���������е�λ��
        while(mid[index]!=ch)
        {
            index++;
        }
        //�����ڵ����ռ�
        (*T)=(struct binode*)malloc(sizeof(struct binode));
        (*T)->data=ch;
        //����������
        GetPostOrder(prim+1,mid,&((*T)->leftchild),index);
        //����������
        GetPostOrder(prim+index+1,mid+index+1,&((*T)->rightchild),len-index-1);
     }
     return 1;
}
//��֪���������ȷ������ǰ��i
int GetPreOrder(telemtype last[],telemtype mid[],struct binode**T,int len)
{
	if(len==0)
	{
	    (*T) = NULL;
	}
	else
	{
		//ȡ�����������е����һ���ڵ�
		telemtype ch=last[len-1];
		int index=0;
		//�����������н��в��Ҹ��ڵ㣬����index��¼���������е�����
		while(mid[index]!=ch)
		{
			index++;
		}
		(*T)=(struct binode*)malloc(sizeof(struct binode)); //�����ڵ����ռ�
		(*T)->data=ch;
		GetPreOrder(last,mid,&((*T)->leftchild),index);//����������
		GetPreOrder(last+index,mid+index+1,&((*T)->rightchild),len-index-1);//����������
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
	//���������ȷ������
	printf("���������������ʾ�������ʾ���м��ÿո��س�����\n");
    scanf("%s%s",first,mid);
	length=strlen(first);
	GetPostOrder(first,mid,&T,length);
	printf("�����������������������:\n");
	PostOrder(T,printelement);
	printf("\n");

	//���������ȷ������
	printf("���������ĺ����ʾ�������ʾ���м��ÿո��س�����\n");
    scanf("%s%s",last,mid);
	length=strlen(last);
	GetPreOrder(last,mid,&T,length);
	printf("�����������������������:\n");
	PreOrder(T,printelement);
	printf("\n");
	return 0;
}























/*
//�������������
void PreOrder(BTree T)
{
	if(T!=NULL)
	{
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//�������������
/*void PostOrder(BTree T)
{
	if(T!=NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
}*/




