#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct sqlist
{  int elem;
   struct sqlist *next;
};
//��ʼ��������������
struct sqlist *input(struct sqlist *head)
{
     struct sqlist *p1,*p2;
	 p2=p1=(struct sqlist *)malloc(sizeof(struct sqlist));
	 scanf("%d",&p1->elem);
         p1->next=NULL;
	 while(p1->elem>=0)
	 {
	    if(head==NULL)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct sqlist*)malloc(sizeof(struct sqlist));
		scanf("%d",&p1->elem);
	 }
	 p2->next=head;
	 return head;
}
//�����������
void print(struct sqlist *head)
{
    struct sqlist *p;
	p=head;
	while(p!=NULL)
	{
	    printf("%d ",p->elem);
		p=p->next;
		if(p==head)
			break;
	}
}
//����ȡ���Ⱥ�����
int LISTlength(struct sqlist *head)
{
	struct sqlist *p,*q;
	int length=0;
	p=q=head;
    if(head==NULL)
		return 0;
	else
	{	while(p!=NULL)
		{
			length++;
		    q=p;
			p=p->next;
			if(p==head)
				break;
		}
		return length;
	}
}
struct sqlist *FOUNDw(struct sqlist *head)
{
    struct sqlist *q;
	q=head;
	if(head==NULL)
	{
		printf("��ǰ��Ϊ��\n");
		exit(0);
	}
	else
	{
	    while(1)
		{
		    q=q->next;
			if(q->next==head)
				break;
		}
		return q;
	}
}
//������λ�ò��뺯����
struct sqlist *insert(struct sqlist *head,int local,int value)
{
   int num=0;
   struct sqlist *p1,*p2,*p3;
   if(head==NULL)//�ձ�Ļ�
   {
	   if(local!=1)
	   {
		   printf("��ǰ��Ϊ�գ��޷����룡\n");
           return head;
	   }
	   else
	   {
	       p1=(struct sqlist*)malloc(sizeof(struct sqlist));
		   p1->elem=value;
		   head=p1;
		   p1->next=head;
           return head;
	   }
   }
   else//���ǿ�����
   {
	   p1=(struct sqlist*)malloc(sizeof(struct sqlist));
	   p1->elem=value;
	   if(local==1)
	   {
		   p1->next=head;
		   head=p1;
		   return head;
	   }
	   else
	   {
         num=0;
	     if(local<1)
		 {
			 printf("λ�ò��Ϸ���\n");
		     return head;
		 }
		 else
		 {
		   p2=p3=head;
		   while(num<local-1&&p2->next!=head)
		   {
			   p3=p2;
			   p2=p2->next;
			   num++;
		   }
		   if(num==local-1)
		   {
	           p3->next=p1;
		       p1->next=p2;
			   return head;
		   }
		   else
		   {
			   if(num==local-2)
			   {
					p2->next=p1;
					p1->next=head;
					return head;
			   }
			   else
			  {
					printf("����û����ô�����ݣ�\n");
					return head;
			  }
		   }
		 }
	   }
   }
}
//����ͷ���뺯����
struct sqlist *proinsert(struct sqlist *head,int value)
{
    struct sqlist *p,*q;
	p=(struct sqlist*)malloc(sizeof(struct sqlist));
	p->elem=value;
	if(head!=NULL)
	{
		//�ҵ������Ǹ��ڵ㣺
		q=head;
		while(1)
		{
			q=q->next;
			if(q->next==head)
				break;
		}
		p->next=head;
		head=p;
		q->next=head;
	}
	else
	{
	    head=p;
		p->next=head;
	}
	return head;
}
//����β���뺯����
struct sqlist *bottominsert(struct sqlist *head,int value)
{
    struct sqlist *p,*p1;
	p1=head;
	p=(struct sqlist*)malloc(sizeof(struct sqlist));
    p->next=head;
	p->elem=value;
	if(p1==NULL)
	  head=p;
	else
	{
		while(1)
		{
			p1=p1->next;
			if(p1->next==head)
			   break;
		}
		p1->next=p;
	}
	return head;
}
//ɾ����һ�ڵ㺯����
struct sqlist*DELlistt(struct sqlist *head)
{
    struct sqlist *p,*q,*n,*m;
	int length;
	n=NULL;
    m=p=q=head;
	if(head==NULL)
		return n;
	else
	{
		length=LISTlength(head);
		if(length==1)
		{
		    head=NULL;
			free(m);
			return head;
		}
		else
		{
			//Ѱ�����һ���ڵ㣺
			while(1)
			{
				q=q->next;
				if(q->next==head)
					break;
			}
			head=p->next;
			q->next=head;
			free(p);
			return head;
		}
	}
}
//ɾ����β�ĺ�����
struct sqlist *DELlistw(struct sqlist *head)
{
    struct sqlist *p,*q;
	int length;
	length=LISTlength(head);
	p=q=head;
	if(head!=NULL)
	{
		if(length!=1)
		{
			while(p->next!=head)
			{
				q=p;
				p=p->next;
			}
			q->next=head;
			free(p);
			return head;
		}
		else
		{
			head=NULL;
		    free(p);
			return head;
		}
	}
	else
		return head;
}
//ͨ��λ��ɾ���ڵ�
struct sqlist *DELlocal(struct sqlist *head, int local)
{
     struct sqlist *p,*q,*n,*m;
	 p=q=head;
	 n=NULL;
	 int num=0;
	 if(head!=NULL)
	 {
         m=FOUNDw(head);
		 while(p!=m&&num<local-1)
		 {
			q=p;
			p=p->next;
			num++;
		 }
		 //����д�λ��
		 if(num==local-1)
		 {
			 //����ǵ�һ��λ�á�
			 if(num==0)
			 {
				 m=FOUNDw(head);
				 head=p->next;
				 m->next=head;
				 free(p);
				 return head;
			 }
			 else
			 {   //��������һ��λ�ã�
				 if(p==m)
				 {
				     q->next=head;
					 free(p);
				 }
				 else
				 {
					 q->next=p->next;
					 free(p);
				 }
				 return head;
			 }
		 }
		 //�����λ��û�����ݣ��򷵻�ֵΪ�ա�
		 else
		 {
			 return n;
		 }
	 }
	 else
		 return head;
}
//��ֵɾ������
struct sqlist *DELvalue(struct sqlist *head,int value)
{
     struct sqlist *p,*q,*m;
	 p=q=head;
	 if(head!=NULL)
	 {
		 m=FOUNDw(head);//��ȡβָ�룻
		 if(m==p)//���������ֻ��һ������
		 {
		     head=NULL;
			 free(p);
			 return head;
		 }
		 else//�ж������
		 {
			 while(p->elem!=value&&p->next!=head)
			 {
				 q=p;
				 p=p->next;
			 }
			 //û���ҵ�Ŀ��ֵ��
			 if(p->elem!=value)
				 return head;
			 //�ҵ���Ŀ��ֵ��
			 else
			 {
				 //���Ŀ��ֵ���ǵ�һ���ڵ㣺
				 if(head!=p)
				 {
					 q->next=p->next;
					 free(p);
					 return head;
				 }
				 //���Ŀ��ֵ�ǵ�һ���ڵ㣺
				 else
				 {
					 m=FOUNDw(head);
					 head=p->next;
					 m->next=head;
					 free(p);
					 return head;
				 }
			 }
		 }
	 }
	 else
		 return head;
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
//��ֵ���ң�
int FOUNDvalue(struct sqlist *head,int value)
{
    struct sqlist *p;
	p=head;
	int local=1;
	if(head==NULL)
		return 0;
	else
	{
		while(p->elem!=value&&p->next!=head)
		{
			p=p->next;
			local++;
		}
		if(p->elem==value)
			return local;
		else
			return 0;
	}
}


