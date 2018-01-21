#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define sis 100;
#define add 10;
struct sqstack
{
   float *top;
   float *base;
   int stacksize;
   int height;
};
struct sqstackchar
{
   char *top;
   char *base;
   int stacksize;
   int height;
};
float gettop(struct sqstack *s)
{
	if(s->base==s->top)
	{
		printf("��ǰջΪ��\n");
	    exit(0);
	}
	else
	    return *(s->top-1);
}
char gettopchar(struct sqstackchar *s)
{
	if(s->base==s->top)
	{
		printf("��ǰջΪ��\n");
	    exit(0);
	}
	else
	    return *(s->top-1);
}
int initstack(struct sqstack *s)
{
    s->base=(float*)malloc('sis'*sizeof(float));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=sis;
	s->height=0;
	return 0;
}
int initstackchar(struct sqstackchar *s)
{
    s->base=(char*)malloc('sis'*sizeof(char));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=sis;
	s->height=0;
	return 0;
}
int push(struct sqstack *s,float e)
{
    if(s->top-s->base>=s->stacksize)
	{
	   s->base=(float *)realloc(s->base,(s->stacksize+'add')*sizeof(float));
	   if(!s->base) exit(0);
	   s->top=s->base+s->stacksize;
	   s->stacksize+='add';
	}
	*s->top++=e;
	s->height++;
	return 0;
}
int pushchar(struct sqstackchar *s,char e)
{
    if(s->top-s->base>=s->stacksize)
	{
	   s->base=(char *)realloc(s->base,(s->stacksize+'add')*sizeof(char));
	   if(!s->base) exit(0);
	   s->top=s->base+s->stacksize;
	   s->stacksize+='add';
	}
	*s->top++=e;
	s->height++;
	return 0;
}
float pop(struct sqstack *s)
{
	float e;
    if(s->base==s->top)
	{
		printf("��ǰջΪ��!\n");
	    return -8888888;
	}
	else
	{
		e=*(s->top-1);
	    s->top--;
		s->height--;
		return e;
	}
}
char popchar(struct sqstackchar *s)
{
	char e;
    if(s->base==s->top)
	{
		printf("��ǰջΪ��!\n");
	    return '?';
	}
	else
	{
		e=*(s->top-1);
	    s->top--;
		s->height--;
		return e;
	}
}


//������ֵص㡣
float operate(float a,char b,float c)
{
    switch(b)
	{
	case '+':return a+c;break;
	case '-':return a-c;break;
	case '*':return a*c;break;
	case '/':return a/c;break;
	}
}
void check(char c2,struct sqstackchar *p2,struct sqstack *p1)
{
	char c1=gettopchar(p2);
	int i,j,flag,a[8][8];
	float x1,x2,result;
     a[1][1]=a[1][2]=a[1][6]=a[1][7]=1;
	 a[1][3]=a[1][4]=a[1][5]=-1;
	 a[2][1]=a[2][2]=a[2][6]=a[2][7]=a[2][6]=1;
	 a[2][3]=a[2][4]=a[2][5]=-1;
	 a[3][1]=a[3][2]=a[3][6]=a[3][7]=a[3][3]=a[3][4]=1;
	 a[3][5]=-1;
	 a[4][1]=a[4][2]=a[4][3]=a[4][4]=a[4][6]=a[4][7]=1;
	 a[4][5]=-1;
	 a[5][1]=a[5][2]=a[5][3]=a[5][4]=a[5][5]=-1;
	 a[5][6]=0;a[5][7]=2;
	 a[6][1]=a[6][2]=a[6][3]=a[6][4]=a[6][6]=a[6][7]=1;
	 a[6][5]=2;
	 a[7][1]=a[7][2]=a[7][3]=a[7][4]=a[7][5]=-1;
	 a[7][6]=2;a[7][7]=0;
	switch(c1)
	{
		case '+':i=1;break;
		case '-':i=2;break;
		case '*':i=3;break;
		case '/':i=4;break;
		case '(':i=5;break;
		case ')':i=6;break;
		case '#':i=7;break;
	}
	switch(c2)
	{
		case '+':j=1;break;
		case '-':j=2;break;
		case '*':j=3;break;
		case '/':j=4;break;
		case '(':j=5;break;
		case ')':j=6;break;
		case '#':j=7;break;
	}
	flag=a[i][j];
	switch(flag)
	{
	case -1:{
		pushchar(p2,c2);
		break;}
	case 1:{
		x1=pop(p1);
		x2=pop(p1);
		result=operate(x2,c1,x1);
		popchar(p2);
		push(p1,result);
		check(c2,p2,p1);
		break;}
	case 0:{
		if(c2==')')
		{
			c2=popchar(p2);
		    while(c2!='(')
			{
				x1=pop(p1);
				x2=pop(p1);
				result=operate(x2,c2,x1);
				c2=popchar(p2);
				push(p1,result);
			}
		}
		else
		{

			c2=popchar(p2);
		    while(c2!='#')
			{
			    x1=pop(p1);
				x2=pop(p1);
				result=operate(x2,c2,x1);
				c2=popchar(p2);
				push(p1,result);
			}
			result=pop(p1);
			printf("%.2f\n",result);
		}
		break;}
	case 2:{printf("������ı��ʽ��������������!\n");exit(0);break;}
	}
}
int main()
{
    int s[8][8],j=0,m,flag;
	float flags;
	char c2,number[10],buffer[256];
	struct sqstack s1;
	struct sqstack *p1;
	struct sqstackchar s2;
	struct sqstackchar *p2;
	p1=&s1;
	p2=&s2;
	initstack(p1);
	initstackchar(p2);
   	gets(buffer);
	pushchar(p2,'#');
	while(buffer[j]!='\0')
	{
		if(buffer[j]<'0'||buffer[j]>'9')
		{
			c2=buffer[j];
			switch(c2)
			{
			    case '#':check(c2,p2,p1);break;
				case '+':check(c2,p2,p1);break;
				case '-':check(c2,p2,p1);break;
				case '*':check(c2,p2,p1);break;
				case '/':check(c2,p2,p1);break;
				case '(':check(c2,p2,p1);break;
				case ')':check(c2,p2,p1);break;
				default:{printf("����������������룡\n");exit(0);break;}
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
	return 0;
}

/*
sprintf()�������ڽ���ʽ��������д���ַ�������ԭ��Ϊ��
    int sprintf(char *str, char * format [, argument, ...]);

��������strΪҪд����ַ�����formatΪ��ʽ���ַ�������printf()������ͬ��argumentΪ������*/
