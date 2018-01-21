#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef char telemtype;
#define sis 100;
#define add 10;
typedef struct binodes
{
    telemtype data;
    struct binodes *leftchild;
	struct binodes *rightchild;
}binode,*bitree;
//ջ����
struct sqstack
{
   bitree *top;
   bitree *base;
   int stacksize;
   int height;
};
int initstack(struct sqstack *s)
{
    s->base=(bitree*)malloc('sis'*sizeof(bitree));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=sis;
	s->height=0;
	//printf("��ʼ��ջ�ɹ�\n");
	return 0;
}
int push(struct sqstack *s,bitree e)
{
    if(s->top-s->base>=s->stacksize)
	{
	   s->base=(bitree *)realloc(s->base,(s->stacksize+'add')*sizeof(bitree));
	   if(!s->base) exit(0);
	   s->top=s->base+s->stacksize;
	   s->stacksize+='add';
	}
	*s->top++=e;
	s->height++;
	return 0;
}
int pop(struct sqstack *s,bitree *value)
{
    if(s->base==s->top)
	{
		printf("��ǰջΪ��!\n");
	    return 1;
	}
	else
	{
	    s->top--;
		s->height--;
		*value=*(s->top);
		return 0;
	}
}
bool emptystack(struct sqstack *s)
{
    if(s->top==s->base)
        return true;
    else
        return false;
}

//���Ĳ���������
void inshow(bitree t)
{
    struct sqstack s;
    struct sqstack *p;
    p=&s;
    initstack(p);
    bitree t1=t;
    while(t1||!emptystack(p))
    {
        if(t1)
        {
            push(p,t1);
            t1=t1->leftchild;
        }
        else
        {
            pop(p,&t1);
            printf("%c ",t1->data);
            t1=t1->rightchild;
        }
    }
    printf("\n");
}
int preshow(bitree t)
{
    struct sqstack s;
    struct sqstack *p;
    p=&s;
    initstack(p);
    bitree t1=t;
    if(t1==NULL)
        return 0;
    push(p,t1);
    while(!emptystack(p))
    {
        pop(p,&t1);
        printf("%c ",t1->data);
        if(t1->rightchild!=NULL)
            push(p,t1->rightchild);
        if(t1->leftchild!=NULL)
            push(p,t1->leftchild);
    }
    return 0;
}
//������������
int createbintree(binode **tree)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ')
    {
        (*tree) = NULL;
    }
    else
    {
        if (!((*tree) = (bitree)malloc(sizeof(binode))))
            exit(0);
        (*tree)->data = ch;
        createbintree(&((*tree)->leftchild));
        createbintree(&((*tree)->rightchild));
    }
    return 1;
}
int main()
{
    bitree t;
    printf("������������ʽ����һ������ע������ÿո��ʾ\n");
    createbintree(&t);
    printf("�������Ϊ\n");
    inshow(t);
    printf("�������Ϊ\n");
    preshow(t);
    //ջ�ļ��飻

 /*   bitree p1,p2,p3,p4,rep;
    binode t1,t2,t3,t4;
    t1.data=1;
    t2.data=2;
    t3.data=3;
    t4.data=4;
    p1=&t1;
    p2=&t2;
    p3=&t3;
    p4=&t4;
    push(p,p1);
    push(p,p2);
    push(p,p3);
    push(p,p4);
    pop(p,&rep);
    printf("%d\n",rep->data);
    pop(p,&rep);
    printf("%d\n",rep->data);
    pop(p,&rep);
    printf("%d\n",rep->data);
    pop(p,&rep);
    printf("%d\n",rep->data);
    if(emptystack(p))
    {
        printf("yes\n");
    }
    else
        printf("no\n");  */
    //��ʼ��ʽд��

}
