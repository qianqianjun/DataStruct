#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct sqlist
{
   int elem;
   struct sqlist *next;
};
//��ʼ���б�
struct sqlist *input(struct sqlist *head,int num)
{
	 if(num==0)
		 exit(0);
     struct sqlist *p1,*p2;
	 p2=p1=(struct sqlist *)malloc(sizeof(struct sqlist));
	 p1->elem=1;
     p1->next=NULL;
	 while(p1->elem<=num)
	 {
	    if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct sqlist*)malloc(sizeof(struct sqlist));
		p1->elem=(p2->elem)+1;
	 }
	 p2->next=head;
	 return head;
}
void print(struct sqlist *head)
{
    struct sqlist *p;
	p=head;
	while(1)
	{
	    printf("%d ",p->elem);
		p=p->next;
		if(p==head)
			break;
	}
}
void print1(struct sqlist *head)
{
    struct sqlist *p;
	p=head;
	while(p!=NULL)
	{
	    printf("%d ",p->elem);
		p=p->next;
	}
}
//��λ�ò��Һ���
struct sqlist *FOUNDlocal(struct sqlist *head,int local)
{
    struct sqlist *p,*n;
	p=head;
	n=NULL;
	int i=0;
	if(head==NULL)
	{
	    printf("����Ϊ�գ�\n");
		exit(0);
	}
	else
	{
		while(i<local-1&&p->next!=head)
		{
		   p=p->next;
		   i++;
		}
		if(p->next==head)
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
//�������к���
void write(struct sqlist *head,int num,int out,int begin)
{
    int i,flag=0;
	struct sqlist result;
	struct sqlist *tou;
	tou=&result;
	struct sqlist *p1,*p2,*p3;
	p2=FOUNDlocal(head,begin-1);
	p1=FOUNDlocal(head,begin);
	while(flag<num)
	{
	    for(i=0;i<out-1;i++)
		{
			p2=p1;
			p1=p1->next;
		}
		p3=p1->next;
		p2->next=p3;
		printf("%d ",p1->elem);
		free(p1);
		p1=p3;
		flag++;
	}
}
int main()
{
    struct sqlist *head,*tou;
	struct sqlist list;
	int num,out,begin;
	head=&list;
	head=NULL;
	printf("����μ���Ϸ����,�����ͳ��ֵ�����,��ʼ�������˱��(�ո����)��\n");
	scanf("%d%d%d",&num,&out,&begin);
	if(begin>num||num<1||out<1||begin<1)
	{
		printf("���ݴ���\n");
		exit(0);
	}
	head=input(head,num);
	write(head,num,out,begin);
	return 0;
}
