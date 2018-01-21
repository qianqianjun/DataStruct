#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define max 100;
struct squeue
{
    int *base;
    int top;
    int bottom;
};
int initqueue(struct squeue *q)
{
    q->base=(int*)malloc('max'*sizeof(int));
    if(!q->base){exit(0);printf("�ڴ����ʧ��!");}
    q->top=q->bottom=0;
    return 0;
}
int getlength(struct squeue *p)
{
    return (p->bottom-p->top+'max')%'max';
}
int addqueue(struct squeue *q,int e)
{
    if((q->bottom+1)%'max'==q->top) {printf("����ʧ��!");exit(0);}
	q->base[q->bottom]=e;
	q->bottom=(q->bottom+1)%'max';
	return 0;
}
int delqueue(struct squeue *q)
{
	int e;
    if(q->top==q->bottom)
	{printf("error!");exit(0);}
	e=q->base[q->top];
	q->top=(q->top+1)%'mix';
	return e;
}
void print(struct squeue *q)
{
    int i;
	if(q->bottom!=q->top)
	{
	    for(i=q->top;i<q->bottom;i++)
		{
			printf("%d ",q->base[i]);
		}
		printf("\n");
	}
	else
		printf("��ǰ����Ϊ��!");
}
void printresult(struct squeue *q)
{
    int i;
	if(q->bottom!=q->top)
	{
	    for(i=q->top;i<q->bottom-1;i++)
		{
			printf("%d ",q->base[i]);
		}
		printf("\n");
	}
	else
		printf("��ǰ����Ϊ��!");
}
int gettop(struct squeue *q)
{
	if(q->top==q->bottom)
	{printf("��ǰ����Ϊ��!");return -88888;}
    return q->base[q->top];
}
void clear(struct squeue *q)
{
    q->top=q->bottom=0;
}
int main()
{
	int h,i=1,j,node,newnode,nodes;
    struct squeue que;
	struct squeue *q;
	q=&que;
	initqueue(q);
	//������ǵ�һ��;
	addqueue(q,0);
	addqueue(q,1);
	addqueue(q,1);
	addqueue(q,0);
	printf("������Ҫ���������");
	scanf("%d",&h);
	if(h<1)
	{	
		printf("��������ȷ!");
		exit(0);
	}
	else
	{
		if(h==1)
			printf("1 1 \n");
		else
		{
			while(i<h)
			{	
				do
				{
				    node=delqueue(q);
					j=q->top;
					nodes=q->base[j];
			    	newnode=node+nodes;
					addqueue(q,newnode);
				}while(q->base[q->top]!=0);
				addqueue(q,0);
				i++;
			}
			delqueue(q);
			printresult(q);
		}
	}
	return 0;
}
