#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct sqlist
{  int elem;
   struct sqlist *next;
};
//多功能链表插入函数：
struct sqlist *insert(struct sqlist *head,int local,int value)
{
   int num=0;
   struct sqlist *p1,*p2,*p3;
   if(head==NULL)//空表的话
   {   
	   if(local!=1)
	   {   
		   printf("当前表为空！无法插入！\n");
           return head;
	   }
	   else
	   {
	       p1=(struct sqlist*)malloc(sizeof(struct sqlist));
		   p1->elem=value;
		   head=p1;
		   p1->next=NULL;
           return head;
	   }
   }
   else
   {
	   p1=(struct sqlist*)malloc(sizeof(struct sqlist));
	   p1->elem=value;
	   if(local==1)
	   {
		   p1->next=head;
		   head=p1;
		   return head;
	   }
	   else
	   {
                num=0;
	        if(local<1)
		 {	 printf("位置不合法！\n");
		     return head;
		 }
		 else
		 {
		     p2=p3=head;
		   while(num<local-1&&p2->next!=NULL)
		   {
			   p3=p2;
			   p2=p2->next;
			   num++;
		   }
		   if(num==local-1)
		   {
	                p3->next=p1;
		        p1->next=p2;
			return head;
		   }
		   else
		   {
			   if(num==local-2)
			   {
					p2->next=p1;
					p1->next=NULL; 
					return head;
			   }
			   else
			  {
					printf("表中没有那么多数据！\n");
					return head;
			  }
		   }
		 }
	   }
   }
}
//输出链表函数：
void print(struct sqlist *head)
{
    struct sqlist *p;
	p=head;
	while(p!=NULL)
	{
	    printf("%d ",p->elem);
		p=p->next;
	}
}
//初始化输入链表函数：
struct sqlist *input(struct sqlist *head)
{
     struct sqlist *p1,*p2;
	 p2=p1=(struct sqlist *)malloc(sizeof(struct sqlist));
	 scanf("%d",&p1->elem);
         p1->next=NULL;
	 while(p1->elem>=0)
	 {
	    if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct sqlist*)malloc(sizeof(struct sqlist));
		scanf("%d",&p1->elem);
	 }
	 p2->next=NULL;
	 return head;
}
//链表头插入函数：
struct sqlist *proinsert(struct sqlist *head)
{
    struct sqlist *p;
	p=(struct sqlist*)malloc(sizeof(struct sqlist));
	scanf("%d",&p->elem);
	p->next=head;
	head=p;
	return head;
}
//链表尾插入函数：
struct sqlist *bottominsert(struct sqlist *head)
{
    struct sqlist *p,*p1;
	p1=head;
	p=(struct sqlist*)malloc(sizeof(struct sqlist));
        p->next=NULL;
	scanf("%d",&p->elem);
       if(p1==NULL)
          head=p;
       else
       {
	while(1)
	{
        p1=p1->next;
        if(p1->next==NULL)
           break;
	}
	p1->next=p;
        }
	return head;
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
//删除第一节点函数：
struct sqlist*DELlistt(struct sqlist *head)
{
    struct sqlist *p,*q,*n;
	n=NULL;
    p=q=head;
	if(head!=NULL)
	{
		p=p->next;
		head=p;
		free(q);
		return head;
	}
	else
		return n;
}
//删除表尾的函数。
struct sqlist *DELlistw(struct sqlist *head)
{
    struct sqlist *p,*q;
	p=q=head;
	if(head!=NULL)
	{
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		free(p);
		return head;
	}
	else
		return head;
}
//通过位置删除节点
struct sqlist *DELlocal(struct sqlist *head, int local)
{
     struct sqlist *p,*q,*n;
	 p=q=head;
	 n=NULL;
	 int num=0;
	 if(head!=NULL)
	 {
		 while(p!=NULL&&num<local-1)
		 {
			q=p;
			p=p->next;
			num++;
		 }
		 //如果有此位置
		 if(num==local-1)
		 {
			 //如果是第一个位置。
			 if(num==0)
			 {	 
				 head=p->next;
				 free(p);
				 return head;
			 }
			 else
			 {
				 q->next=p->next;
				 free(p);
				 return head;
			 }
		 }
		 //如果此位置没有数据，则返回值为空。
		 else
		 {
			 return n;
		 }
	 }
	 else
		 return head;
}
//按值删除函数
struct sqlist *DELvalue(struct sqlist *head,int value)
{
     struct sqlist *p,*q;
	 p=q=head;
	 if(head!=NULL)
	 {
		 while(p->elem!=value&&p->next!=NULL)
		 {
			 q=p;
			 p=p->next;
		 }
		 if(p->elem!=value)
			 return head;
		 else
		 {
			 if(head!=p)
			 {
				 q->next=p->next;
				 free(p);
				 return head;
			 }
			 else
			 {	 
				 head=p->next;
				 free(p);
				 return head;
			 }
		 }
	 }
	 else
		 return head;
}
//按位置查找函数
struct sqlist *FOUNDlocal(struct sqlist *head,int local)
{
    struct sqlist *p,*n;
	p=head;
	n=NULL;
	int i=0;
	if(head==NULL)
		return head;
	else
	{
		while(i<local-1&&p->next!=NULL)
		{
		   p=p->next;
		   i++;
		}
		if(p->next==NULL)
		{
		   if(i==local-1)
			   return p;
		   else
			   return n;
		}
		else
		return p;
	}
}
//按值查找：
int FOUNDvalue(struct sqlist *head,int value)
{
    struct sqlist *p;
	p=head;
	int local=1;
	if(head==NULL)
		return 0;
	else
	{
		while(p->elem!=value&&p->next!=NULL)
		{
			p=p->next;
			local++;
		}
		if(p->elem==value)
			return local;
		else
			return 0;
	}
}

