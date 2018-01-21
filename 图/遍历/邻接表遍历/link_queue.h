#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
typedef int elemtype;
struct node
{
   elemtype elem;
   struct node *next;
};
typedef struct linkqueue
{
   struct node *top;
   struct node *bottom;
}sqqueue;
int initqueue(struct linkqueue *q)
{
   q->top=q->bottom=(struct node *)malloc(sizeof(struct node));
   if(!q->top)exit(0);
   q->top->next=NULL;
   return 0;
}
void destory(struct linkqueue  *q)
{
    while(q->top)
	{
	    q->bottom=q->top->next;
		free(q->top);
		q->top=q->bottom;
	}
}
void addqueue(struct linkqueue *q,int e)
{
	struct node *p;
     p=(struct node*)malloc(sizeof(struct node));
	 if(!p)exit(0);
	 p->elem=e;
	 p->next=NULL;
	 q->bottom->next=p;
	 q->bottom=p;
}
int delqueue(struct linkqueue *q)
{
	struct node *p;
	int e;
    if(q->top==q->bottom) {printf("´íÎó");exit(0);}
	p=q->top->next;
	e=p->elem;
	q->top->next=p->next;
	if(q->bottom==p)q->bottom=q->top;
	free(p);
	return e;
}
void print(struct linkqueue *q)
{
	struct node *p;
   if(q->top==q->bottom)printf("µ±Ç°Îª¿Õ!\n");
   else
   {
       p=q->top->next;
	   while(p!=q->bottom->next)
	   {
	       printf("%d ",p->elem);
		   p=p->next;
	   }
   }
}
bool emptyqueue(sqqueue *q)
{
    if(q->top==q->bottom)
        return true;
    else
        return false;
}




