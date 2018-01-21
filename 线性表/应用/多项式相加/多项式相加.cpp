#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct sqlist
{
    int xi;
	int log;
	struct sqlist *next;
};
struct sqlist *input(struct sqlist *head)
{
    struct sqlist *p1,*p2;
	p1=(struct sqlist *)malloc(sizeof(struct sqlist));
	scanf("%d%d",&p1->xi,&p1->log);
	p1->next=NULL;
	if(p1->xi==0)
		return NULL;
	else
	{
	while(p1->xi!=0)
	{
	    if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct sqlist *)malloc(sizeof(struct sqlist));
		scanf("%d%d",&p1->xi,&p1->log);
	}
	p2->next=NULL;
	return head;
	}
}
//链表取长度函数：
int LISTlength(struct sqlist *head)
{
	struct sqlist *p,*q;
	int length=0;
	p=q=head;
    if(head==NULL)
		return 0;
	else
	{	while(p!=NULL)
		{
			length++;
		    q=p;
			p=p->next;
		}
		return length;
	}
}
//输出链表函数：
void print(struct sqlist *head)
{
    struct sqlist *p;
	p=head;
	printf("结果为：F(X)= ");
	while(p->next!=NULL)
	{
	    printf("%dX^%d+",p->xi,p->log);
		p=p->next;
	}
	printf("%dX^%d\n",p->xi,p->log);
}
//链表合并函数
struct sqlist *add(struct sqlist *head,struct sqlist *head1)
{
    struct sqlist *p1,*p2,*p3,*p4;\
	int m,n,flag=0;
	p1=head;
	p2=head1;
	if(head==NULL&&head1==NULL)
	{
	    printf("为空\n");
		exit(0);
	}
	else
	{
	    if(head==NULL)
			return head1;
		else
		{
		    if(head1==NULL)
				return head;
			else
			{
			   while(p2!=NULL)
			   {
				   while(p1!=NULL)
				   {
					   if(p1->log==p2->log)
					   {
						   p1->xi=p1->xi+p2->xi;
						   flag=1;
						   break;
					   }
					   p4=p1;
					   p1=p1->next;
				   }
				   if(flag==0)
				   {
					   p3=(struct sqlist *)malloc(sizeof(struct sqlist));
					   p3->log=p2->log;
					   p3->xi=p2->xi;
					   p3->next=NULL;
					   p4->next=p3;
				   }
				   p2=p2->next;
				   flag=0;
				   p1=head;
			   }
			   return head;
			}
		}
	}

}
int main()
{
    struct sqlist list,list1;
	struct sqlist*head,*head1,*h;
	int one,two;
	head=&list;
	head1=&list1;
	head1=NULL;
	head=NULL;
	printf("请输入第一个多项式的系数和指数(空格隔开)，系数未0时结束输入：\n");
	head=input(head);
	printf("请输入第二个多项式的系数和指数(空格隔开)，系数为0时结束输入：\n");
	head1=input(head1);
	h=add(head,head1);
	print(h);
	return 0;
}
