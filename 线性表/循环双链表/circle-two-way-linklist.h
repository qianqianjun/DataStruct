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
   p->next=head;
   while(p->elem>=0)
   {
       if(head==NULL)
	   {
	       head=p;
		   p->pro=head;
		   p->next=head;
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
   q->next=head;
   return head;
}
//�������������
void print(struct sqlist *head)
{
	struct sqlist *p;
     p=head;
	 if(head==NULL)
	 {
	      
	 }
	 else
	 {
	 while(1)
	 {
	     printf("%d ",p->elem);
		 p=p->next;
		 if(p==head)
			 break;
	 }
	 }
}
//��ȡ���Ⱥ�����
int LISTlength(struct sqlist *head)
{
    struct sqlist *p;
	int length=0;
	p=head;
	if(head==NULL)
		return 0;
	else
	{
	while(1)
	{
		p=p->next;
	    length++;
		if(p==head)
			break;
	}
	return length;
	}
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
		 while(p->next!=head)
		 {
			 p=p->next;
		 }
	     return p;
	 }
}
//����ǰ�庯��
struct sqlist *proinsert(struct sqlist *head,int value)
{
     struct sqlist *p,*q,*w;
	 p=head;
	 q=(struct sqlist*)malloc(sizeof(struct sqlist));
	 q->elem=value;
	 q->next=NULL;
	 //����Ϊ�յĻ���
	 if(head==NULL)
	 {
	      head=q;
		  q->pro=head;
		  q->next=head;
	 }
	 else
	 {
		  w=FOUNDw(head);
	      p->pro=q;
		  q->next=p;
		  head=q;
		  q->pro=head;
		  w->next=head;
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
	 p->next=head;
	 if(head==NULL)
	 {
	     head=p;
		 p->pro=head;
		 p->next=head;
	 }
	 else
	 {
		 //������һ��Ԫ�ص�ָ��p1�͵����ڶ���Ԫ�ص�ָ��p2��
		 p1=FOUNDw(head);
		 p1->next=p;
		 p->pro=p1;
	 }
	 return head;
}
//����λ�ò��뺯����
struct sqlist *insertlocal(struct sqlist *head,int local,int value)
{
    struct sqlist *p1,*p2,*p3,*w;
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
		   p1->next=head;
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
		   w=FOUNDw(head);
		   head=p1;
		   p1->pro=head;
		   w->next=head;
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
    struct sqlist *p1,*p2,*p3,*w;
	int num=0;
	p2=p1=head;
	if(head==NULL)
	{
		printf("��ǰ��Ϊ�գ�\n");
		return head;
	}
	else
	{
		if(local==1)
		{
			 w=FOUNDw(head);
		     head=p1->next;
			 p1->next->pro=head;
			 w->next=head;
			 free(p2);
			 return head;
		}
		else
		{
			//�ҵ�Ҫɾ����λ�ú�ǰ�ߵ�λ�ã�
			while(p1->next!=head&&num<local-1)
			{
				 p2=p1;
				 p1=p1->next;
				 num++;
			}
			//������ڴ�λ�ã�
			if(num==local-1)
			{
				//�����ɾ�������������һ���ڵ㣺
				 if(p1->next==head)
				 {
					  p2->next=head;
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
     struct sqlist *p,*q,*w;
	 p=q=head;
	 if(head!=NULL)
	 {
		 while(p->elem!=value&&p->next!=head)
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
				 if(p->next!=head)
				 {
				 w=FOUNDw(head);
				 head=p->next;
				 p->next->pro=head;
				 w->next=head;
				 free(p);
				 return head;
				 }
				 else
				 {
				    head=NULL;
					return head;
					free(p);
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
		return head;
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


















