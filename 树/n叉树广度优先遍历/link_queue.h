#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef char telemtype;
typedef struct binodes
{
    telemtype data;
    struct binodes *leftchild;
	struct binodes *nextsibing;
}binode,*bitree;
struct node
{
   bitree elem;
   struct node *next;
};
struct linkqueue
{
   struct node *top;
   struct node *bottom;
};
int initqueue(struct linkqueue *q)
{
   q->top=q->bottom=(struct node*)malloc(sizeof(struct node));
   if(!q->top)exit(0);
   q->top->next=NULL;
   return 0;
}
void addqueue(struct linkqueue *q,bitree e)
{
    struct node *p;
     p=(struct node*)malloc(sizeof(struct node));
     if(!p)exit(0);
     p->elem=e;
     p->next=NULL;
     q->bottom->next=p;
     q->bottom=p;
}
bitree delqueue(struct linkqueue *q)
{
    struct node *p;
    bitree e;
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
