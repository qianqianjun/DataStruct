#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define sis 100;
#define add 10;
typedef float elemtype;
struct sqstack
{
   elemtype *top;
   elemtype *base;
   int stacksize;
   int height;
};
int initstack(struct sqstack *s)
{
    s->base=(elemtype*)malloc('sis'*sizeof(elemtype));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=sis;
	s->height=0;
	printf("初始化栈成功\n");
	return 0;
}
int push(struct sqstack *s,elemtype e)
{
    if(s->top-s->base>=s->stacksize)
	{
	   s->base=(elemtype *)realloc(s->base,(s->stacksize+'add')*sizeof(elemtype));
	   if(!s->base) exit(0);
	   s->top=s->base+s->stacksize;
	   s->stacksize+='add';
	}
	*s->top++=e;
	s->height++;
	return 0;
}
elemtype pop(struct sqstack *s)
{
	float e;
    if(s->base==s->top)
	{	
		printf("当前栈为空!\n");
	    exit(0);
	}
	else
	{
		e=*(s->top-1);
	    s->top--;
		s->height--;
		return e;
	}
}
void main()
{
    int j=0,m,flag;
	float flags;
	char c2,number[10],buffer[256];
	struct sqstack s1;
	struct sqstack *p1;
	float result,x1,x2;
	p1=&s1;
	initstack(p1);
   	gets(buffer);
	while(buffer[j]!='\0')
	{
		if(buffer[j]<'0'||buffer[j]>'9')
		{
			c2=buffer[j];
			switch(c2)
			{
			    case ' ':break;
				case '+':{x1=pop(p1);x2=pop(p1);result=x2+x1;push(p1,result);break;}
				case '-':{x1=pop(p1);x2=pop(p1);result=x2-x1;push(p1,result);break;}
				case '*':{x1=pop(p1);x2=pop(p1);result=x2*x1;push(p1,result);break;}
				case '/':{x1=pop(p1);x2=pop(p1);result=x2/x1;push(p1,result);break;}
				default:{printf("输入错误，请重新输入！\n");exit(0);break;}
			}
			j++;
		}
		else
		{
			m=0;
			while(buffer[j]<='9'&&buffer[j]>='0')
			{
				  number[m]=buffer[j];
				  j++;
				  m++;
			}
			number[m]='\0';
			flag=atoi(number);
			flags=flag*1.0;
			push(p1,flags);
		}
	}
	result=pop(p1);
	printf("计算结果为：%.2f\n",result);
}


