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
	   printf("��ǰջΪ�գ�\n");
}
void check(int proj,int value)
{
	int flag;
    while(value)
	{
	    flag=value%10;
		if(flag>=proj)
		{
			printf("���������������!\n");
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
	//��valueת��Ϊʮ���Ƶ����֡�
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
	printf("��ӭʹ�ý���ת������\n");
	while(1)
	{

	   printf("*************************************************************\n");
	   printf("*�������ת���ƺ��ڸý����µ���ֵ���м����ÿո����������    \n");
	   scanf("%d%d",&proj,&value);
	   printf("������Ҫת��Ϊ�Ľ���:  ");
	   scanf("%d",&nextj);
	   head=coversation(head,proj,value,nextj);
	   system("CLS");
	   printf("ת��֮��Ľ��Ϊ�� \n");
	   printf("ԭ���ƣ�%d   �ֽ��ƣ�%d\n",proj,nextj);
	   printf("\n");
	   printf("ԭ��ֵ��%d   ����ֵ��",value);
	   printresult(head);
	   printf("\n");
	}
	return 0;
}
