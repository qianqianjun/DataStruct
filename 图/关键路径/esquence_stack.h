#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define sis 100;
#define add 10;
struct sqstack
{
   int *top;
   int *base;
   int stacksize;
   int height;
};
int initstack(struct sqstack *s)
{
    s->base=(int*)malloc('sis'*sizeof(int));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=sis;
	s->height=0;
	return 0;
}
int push(struct sqstack *s,int e)
{
    if(s->top-s->base>=s->stacksize)
	{
	   s->base=(int *)realloc(s->base,(s->stacksize+'add')*sizeof(int));
	   if(!s->base) exit(0);
	   s->top=s->base+s->stacksize;
	   s->stacksize+='add';
	}
	*s->top++=e;
	s->height++;
	return 0;
}
int pop(struct sqstack *s,int *p)
{
    if(s->base==s->top)
	{
	    return 1;
	}
	else
	{
	    *p=*(s->top-1);
	    s->top--;
		s->height--;
		return 0;
	}
}
bool isempty(struct sqstack *s)
{
    if(s->top==s->base)
        return true;
    else
        return false;
}
