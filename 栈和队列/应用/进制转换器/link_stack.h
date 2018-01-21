#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct sqstack
{
   int elem;
   struct sqstack *next;
};
struct sqstack *initsqstack()
{
   struct sqstack *head;
   head=(struct sqstack*)malloc(sizeof(struct sqstack));
   head->next=head;
   head->elem=NULL;
   return head;
}
struct sqstack *push(struct sqstack *head,int e)
{
    struct sqstack *p;
	p=(struct sqstack*)malloc(sizeof(struct sqstack));
	p->elem=e;
	p->next=head->next;
	head->next=p;
	return head;
}
void print(struct sqstack *head)
{
    struct sqstack *p;
	if(head->next!=head)
	{
		p=head->next;
		 while(p->next!=head)
		 {
			printf("%d ",p->elem);
			p=p->next;
		 }
		 printf("%d\n",p->elem);
	}
	else
	   printf("当前栈为空！\n");
}
struct sqstack *pop(struct sqstack *head)
{
     struct sqstack *p;
	 if(head->next==head)
		 return head;
	 p=head->next;
	 head->next=p->next;
	 free(p);
	 return head;
}
struct sqstack *gettop(struct sqstack *head)
{
    struct sqstack *p;
	if(head->next!=head)
	{
		p=head->next;
		return p;
	}
	else
	    return head;
}
int empty(struct sqstack *head)
{
    if(head->next=head)
		return 0;
	else
		return 1;
}
int getlength(struct sqstack *head)
{
    int length=0;
	struct sqstack *p;
	p=head->next;
	if(head->next!=head)
	{
	    while(p!=head)
		{
		    length++;
			p=p->next;
		}
		return length;
	}
	else
		return 0;
}
int foundvalue(struct sqstack *head,int value)
{
     struct sqstack *p;
	 int i=1;
	 if(head->next==head)
	 {
		 printf("当前栈为空!\n");
		 return 0;
	 }
	 else
	 {
	     p=head->next;
		 while(p->elem!=value&&p!=head)
		 {	 
			 i++;
			 p=p->next;
		 }
		 if(p->elem==value)
			 return i;
		 else
		 {
		     printf("当前栈中没有此数据 ");
			 return 0;
		 }
	 }
}
struct sqstack *foundlocal(struct sqstack *head,int local)
{
	struct sqstack *p;
	int length,i=0;
	p=head;
	length=getlength(head);
     if(head->next==head)
	 {
	     printf("当前栈为空！\n");
		 return head;
	 }
	 else
	 {
	     if(local>length||local<1)
		 {
		     printf("位置不合法！\n");
			 return head;
		 }
		 else
		 {
		     while(i!=local)
			 {
			     p=p->next;
				 i++;
			 }
			 return p;
		 }
	 }	 
}
