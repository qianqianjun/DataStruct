#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct sqlist
{
   int elem;
   struct sqlist *pro;
   struct sqlist *next;
};
//��ʼ�����뺯����
struct sqlist *input(struct sqlist *head)
{
   struct sqlist *p,*q;
   q=p=(struct sqlist*)malloc(sizeof(struct sqlist));
   scanf("%d",&p->elem);
   p->next=NULL;
   while(p->elem>=0)
   {
       if(head==NULL)
	   {
	       head=p;
		   p->pro=head;
	   }
	   else
	   {
	       q->next=p;
		   p->pro=q;
	   }
	   q=p;
	   p=(struct sqlist*)malloc(sizeof(struct sqlist));
	   scanf("%d",&p->elem);
   }
   q->next=NULL;
   return head;
}
//�������������
void print(struct sqlist *head)
{
	struct sqlist *p;
     p=head;
	 while(p!=NULL)
	 {
	     printf("%d ",p->elem);
		 p=p->next;
	 }
}
//��ȡ���Ⱥ�����
int LISTlength(struct sqlist *head)
{
    struct sqlist *p;
	int length=0;
	p=head;
	while(p!=NULL)
	{
		p=p->next;
	    length++;	
	}
	return length;
}
//���ָ������β��ָ��ĺ�����
struct sqlist *FOUNDw(struct sqlist *head)
{
     struct sqlist *p;
	 p=head;
	 if(head==NULL)
		 return head;
	 else
	 {
		 while(p->next!=NULL)
		 {
			 p=p->next;
		 }
	     return p;
	 }
}
//����ǰ�庯��
struct sqlist *proinsert(struct sqlist *head,int value)
{
     struct sqlist *p,*q;
	 p=head;
	 q=(struct sqlist*)malloc(sizeof(struct sqlist));
	 q->elem=value;
	 q->next=NULL;
	 //����Ϊ�յĻ���
	 if(head==NULL)
	 {
	      head=q;
		  q->pro=head;
	 }
	 else
	 {
	      p->pro=q;
		  q->next=p;
		  head=q;
		  q->pro=head;
	 }
     return head;
}
//�����庯����
struct sqlist*bottominsert(struct sqlist *head,int value)
{
     struct sqlist *p,*p1,*p2;
	 p1=p2=head;
	 p=(struct sqlist*)malloc(sizeof(struct sqlist));
	 p->elem=value;
	 p->next=NULL;
	 if(head==NULL)
	 {
	     head=p;
		 p->pro=head;
	 }
	 else
	 {
		 //������һ��Ԫ�ص�ָ��p1�͵����ڶ���Ԫ�ص�ָ��p2��
	     while(p1->next!=NULL)
		 {
		     p2=p1;
			 p1=p1->next;
		 }
		 p1->next=p;
		 p->pro=p1;
	 }
	 return head;
}
//����λ�ò��뺯����
struct sqlist *insertlocal(struct sqlist *head,int local,int value)
{
    struct sqlist *p1,*p2,*p3;
	int num=0;
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
		   p1->pro=head;
		   p1->next=NULL;
           return head;
	   }
   }
	//���ǿձ�
   else
   {
	   p1=(struct sqlist*)malloc(sizeof(struct sqlist));
	   p1->elem=value;
	   if(local==1)
	   {
		   p1->next=head;
		   p1->next->pro=p1;
		   head=p1;
		   p1->pro=head;
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
		   while(num<local-1&&p2->next!=NULL)
		   {
			   p3=p2;
			   p2=p2->next;
			   num++;
		   }
		   if(num==local-1)
		   {
	            p3->next=p1;
				p1->pro=p3;
		        p1->next=p2;
				p2->pro=p1;
			return head;
		   }
		   else
		   {
			   if(num==local-2)
			   {
					p2->next=p1;
					p1->pro=p2;
					p1->next=NULL; 
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
//����ɾ����һ���ڵ㺯����
struct sqlist *DELlistt(struct sqlist *head)
{
     struct sqlist *p1,*p2,*p3;
	 p1=head;
	 if(head==NULL)
		 return head;
	 else
	 {
	     p3=FOUNDw(head);
		 //���ֻ��һ���ڵ㣺
		 if(p1==p3)
		 {	 
			 head=NULL;
			 free(p3);
		     return head;
		 }
		 else
		 {
		     head=p1->next;
			 p1->next->pro=head;
			 free(p1);
		 }
	 }
}
//ɾ����β����
struct sqlist *DELlistw(struct sqlist *head)
{
     struct sqlist *p1,*p2,*p3;
	 p1=head;
	 if(head==NULL)
		 return head;
	 else
	 {
	     p3=FOUNDw(head);
		 if(head==p3)
		 {	 
			 head=NULL;
			 free(p3);
		     return head;
		 }
		 else
		 {
		     while(1)
			 {
				 if(p1->next->next==NULL)
					 break;
			      p1=p1->next;
			 }
			 p2=p1->next;
			 free(p2);
			 p1->next=NULL;
			 return head;
		 }
	 }
}
//λ��ɾ��������
struct sqlist *DELlocal(struct sqlist *head,int local)
{
    struct sqlist *p1,*p2,*p3;
	int num=0;
	p2=p1=head;
	if(head==NULL)
	{
		printf("��ǰ��Ϊ�գ�\n");
	    exit(0);
		return head;
	}
	else
	{
		if(local==1)
		{
		     head=p1->next;
			 p1->next->pro=head;
			 free(p2);
			 return head;
		}
		else
		{
			//�ҵ�Ҫɾ����λ�ú�ǰ�ߵ�λ�ã�
			while(p1->next!=NULL&&num<local-1)
			{
				 p2=p1;
				 p1=p1->next;
				 num++;
			}
			//������ڴ�λ�ã�
			if(num==local-1)
			{
				//�����ɾ�������������һ���ڵ㣺
				 if(p1->next==NULL)
				 {
					  p2->next=NULL;
					  free(p1);
					  return head;
				 }
				 //����������һ���ڵ㣺
				 else
				 {
					  p2->next=p1->next;
					  p1->next->pro=p2;
					  free(p1);
					  return head;
				 }

			}
			else
			{
				return head;
			}
		}
	}
}

//��ֵɾ������
struct sqlist *DELvalue(struct sqlist *head,int value)
{
     struct sqlist *p,*q;
	 p=q=head;
	 if(head!=NULL)
	 {
		 while(p->elem!=value&&p->next!=NULL)
		 {
			 q=p;
			 p=p->next;
		 }
		 if(p->elem!=value)
			 return head;
		 else
		 {
			 if(head!=p)
			 {
				 q->next=p->next;
				 p->next->pro=q;
				 free(p);
				 return head;
			 }
			 else
			 {	 
				 head=p->next;
				 p->next->pro=head;
				 free(p);
				 return head;
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
		return head;
	else
	{
		while(i<local-1&&p->next!=NULL)
		{
		   p=p->next;
		   i++;
		}
		if(p->next==NULL)
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
		while(p->elem!=value&&p->next!=NULL)
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


















