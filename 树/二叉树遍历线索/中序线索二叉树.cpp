#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
typedef char telemtype;
typedef struct binode
{
    telemtype data;
    struct binode *lchild;
	struct binode *rchild;
	int rtag,ltag;
}Binode,*Bitree;
Bitree pre;
int printelement(telemtype e)
{
    putchar(e);
    return 1;
}
int createbintree(Bitree*tree)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ')
    {
        (*tree) = NULL;
    }
    else
    {
        if (!((*tree) = (struct binode *)malloc(sizeof(struct binode))))
            exit(0);
        (*tree)->data = ch;
        createbintree(&((*tree)->lchild));
        createbintree(&((*tree)->rchild));
    }
    return 1;
}
void Thread(Bitree T)
{
    if(T!=NULL)
    {
        Thread(T->lchild);
        if(T->lchild==NULL)
        {
            T->lchild=pre;
            T->ltag=1;
        }
        else
            T->ltag=0;
        if(pre->rchild==NULL)
        {
            pre->rchild=T;
            pre->rtag=1;
        }
        else
            pre->rtag=0;
        pre=T;
        Thread(T->rchild);
    }
}
Bitree inthread(struct binode * T)
{
    Bitree root;
    root=(Bitree)malloc(sizeof(Binode));
    root->ltag=0;root->rtag=1;root->lchild=T;
    if(T==NULL)
        root->lchild=root;
    else
    {
        root->lchild=T;
        pre=root;
        Thread(T);
        pre->rchild=root;
        pre->rtag=1;
        root->rchild=pre;
    }
    return root;
}
void inordershow(Bitree root)
{
    Bitree p=root->lchild;
    while(p!=root)
    {
        while(p->ltag==0)
            p=p->lchild;
        printf("%c",p->data);
        while(p->rtag==1&&p->rchild!=root)
        {
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;
    }
}
int main()
{
    Bitree T;
	printf("请用先序方式输入树,空节点要用空格表示\n");
    createbintree(&T);
    Bitree root;
    root=inthread(T);
    cout<<"中序输出结果为："<<endl;
    inordershow(root);
    return 0;
}
