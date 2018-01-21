#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define sis 100;
#define add 10;
typedef char elemtype;
//树的有关操作和定义；
typedef struct binodes
{
    elemtype data;
    struct binodes *leftchild;
    struct binodes *rightchild;
}binode,*bitree;
bitree R;
//栈的定义和操作；
typedef struct sqstacks
{
    bitree *top;
    bitree *base;
    int height;
    int stacksize;
}sqstack;
int initstack(sqstack *s)
{
    s->base=(bitree *)malloc('sis'*sizeof(bitree));
	if(!s->base)exit(0);
	s->top=s->base;
	s->stacksize=sis;
	s->height=0;
	return 0;
}
//压栈操作；
void push(sqstack *s,bitree e)
{
    if(s->top-s->base>=s->stacksize)
	{
	   s->base=(bitree *)realloc(s->base,(s->stacksize+'add')*sizeof(bitree));
	   if(!s->base) exit(0);
	   s->top=s->base+s->stacksize;
	   s->stacksize+='add';
	}
	*s->top=e;
	s->top++;
	s->height++;
}
//出栈操作
bitree pop(sqstack *s)
{
	bitree e;
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
//取栈顶函数。
bitree gettop(sqstack *s)
{
	if(s->base==s->top)
	{
		printf("当前栈为空\n");
	    exit(0);
	}
	else
	    return *(s->top-1);
}
int create(bitree *tree)
{
    (*tree)=(bitree)malloc(sizeof(binode));
    (*tree)->leftchild = NULL;
    (*tree)->rightchild=NULL;
    return 1;
}
//创建指针函数。
bitree createpoint()
{
    bitree t;
    create(&t);
    return t;
}
int printelement(elemtype e)
{
    putchar(e);
    return 1;
}
int preshow(binode* T, int(*visit)(elemtype e))
{
    if (T)
    {
        if (visit(T->data))
            if (preshow(T->leftchild, visit))
                if (preshow(T->rightchild, visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}
int postshow(binode* T, int(*visit)(elemtype e))
{
    if (T)
    {
        if (postshow(T->leftchild, visit))
            if (postshow(T->rightchild, visit))
                if (visit(T->data))
                    return 1;
        return 0;
    }
    else
        return 1;
}
//运算函数；
void check(char c2,sqstack *p2,sqstack *p1)
{
    char c1;
    bitree p=gettop(p2);
    c1=p->data;
    //获取栈内元素的值；
	int i,j,flag,a[8][8];
	bitree t1,t2;
	//输入优先级表；大于为1，小于为-1等于为0；
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
		//default:i=7;break;
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
	//获取栈内栈外运算符优先级别大小；
	flag=a[i][j];
//	printf("%d %d ",i,j);
	switch(flag)
	{
	case -1:{
	    bitree t=createpoint();
	    t->data=c2;
		push(p2,t);
		break;}
	case 1:{
		t1=pop(p1);
		t2=pop(p1);
		bitree t3=pop(p2);
		//bitree root=createpoint();
		//root->data=t3->data;
		//root->leftchild=t2;
		//root->rightchild=t1;
		t3->leftchild=t2;
		t3->rightchild=t1;
		push(p1,t3);
		check(c2,p2,p1);
		break;}
	case 0:{
		if(c2==')')
		{
		    bitree p=pop(p2);
		    c2=p->data;
			//c2=popchar(p2);
		    while(c2!='(')
			{
			    bitree root=pop(p2);
			    c2=root->data;
			    if(c2=='(')
                    continue;
				t1=pop(p1);
				t2=pop(p1);
				root->leftchild=t2;
				root->rightchild=t1;
				push(p1,root);
			}
		}
		else
		{
		    printf("\n");
		    R=pop(p1);
			printf("先序输出为:\n");
            preshow(R, printelement);printf("\n");
            printf("后序输出为\n");
            postshow(R,printelement);printf("\n");
		}
		break;}
	case 2:{printf("您输入的表达式有误，请重新输入!\n");exit(0);break;}
	}
}
int main()
{
    int j=0,m,flag;
	char c2,buffer[256],c,c1;
	bitree px,px1;
	sqstack s2,s1;
	sqstack *p2,*p1;
	p1=&s1;
	p2=&s2;
	R=createpoint();
	//对指针栈进行初始化；
	initstack(p1);
	initstack(p2);
	printf("请输入表达式，数字用单个小写字母表示，结束输入#号\n");
	bitree x;
    x=createpoint();
    x->data='#';
	push(p2,x);
	gets(buffer);
	while(buffer[j]!='\0')
	{
		if(buffer[j]=='+'||buffer[j]=='-'||buffer[j]=='*'||buffer[j]=='/'||buffer[j]=='('||buffer[j]==')'||buffer[j]=='#')
		{
			c2=buffer[j];
            check(c2,p2,p1);
		}
		else
		{
		    if(buffer[j]>='a'&&buffer[j]<='z')
            {
                bitree t=createpoint();
                t->data=buffer[j];
                push(p1,t);
            }
            else
            {
                printf("输入有错误\n");
                exit(0);
            }
		}
		j++;
	}
	return 0;
}

/*
int main()
{
    //栈的检验语句；
    sqstack S,S1;
    sqstack *s,*s1;
    s=&S;
    s1=&S1;
    initstack(s);
    initstack(s1);
	char q[5]={'+','-','*','/','#'};
    for(int i=0;i<5;i++)
    {
        bitree t;
        t=createpoint();
        t->data=q[i];
        push(s,t);
    }
    bitree t1=createpoint();
    t1->data='Z';
    bitree t2=createpoint();
    t2->data='Y';
    push(s1,t2);
    push(s1,t1);
    bitree T=gettop(s);
    T->leftchild=pop(s1);
    T->rightchild=pop(s1);
    bitree T1=gettop(s);
    pop(s);
    push(s1,T);
    T=gettop(s);
    cout<<T->data<<endl;
    T1=gettop(s1);
    cout<<T1->data<<' '<<T1->leftchild->data<<' '<<T1->rightchild->data<<' '<<endl;
}*/
