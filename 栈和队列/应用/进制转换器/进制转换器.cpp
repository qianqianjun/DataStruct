#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include"link_stack.h"
void printresult(struct sqstack *head)
{
    struct sqstack *p;
	if(head->next!=head)
	{
		p=head->next;
		 while(p->next!=head)
		 {
			printf("%d",p->elem);
			p=p->next;
		 }
		 printf("%d\n",p->elem);
	}
	else
	   printf("当前栈为空！\n");
}
void check(int proj,int value)
{
	int flag;
    while(value)
	{
	    flag=value%10;
		if(flag>=proj)
		{
			printf("您输入的数据有误!\n");
			exit(0);
		}
		value=value/10;
	}
}
int coversation10(int proj,int value)
{
    int flag,value10=0,i=0;
	check(proj,value);
	if(proj==10)
	{
	    return value;
	}
	else
	{
	    while(value/10!=0)
		{
		     flag=value%10;
			 value10=value10+flag*pow(proj,i);
			 i++;
			 value=value/10;
		}
		value10=value10+value*pow(proj,i);
		return value10;
	}
}
struct sqstack *coversation(struct sqstack *head,int proj,int value,int nextj)
{
	//将value转换为十进制的数字。
    value=coversation10(proj,value);
	while(value)
	{
	    head=push(head,value%nextj);
		value=value/nextj;
	}
	return head;
}
int main()
{
	int value,proj,nextj,value10;
    struct sqstack *head;
	head=initsqstack();
	printf("欢迎使用进制转换器！\n");
	while(1)
	{

	   printf("*************************************************************\n");
	   printf("*请输入待转进制和在该进制下的数值（中间请用空格隔开！）：    \n");
	   scanf("%d%d",&proj,&value);
	   printf("请输入要转换为的进制:  ");
	   scanf("%d",&nextj);
	   head=coversation(head,proj,value,nextj);
	   system("CLS");
	   printf("转换之后的结果为： \n");
	   printf("原进制：%d   现进制：%d\n",proj,nextj);
	   printf("\n");
	   printf("原数值：%d   现数值：",value);
	   printresult(head);
	   printf("\n");
	}
	return 0;
}
