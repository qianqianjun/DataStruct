#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LIS 100;//�����ĳ�ʼ�����ȡ�
#define ladd 10;//��ռ䲻��ʱ������Ϊ
typedef int elemtype;
struct sqlist
{
   elemtype *elem;
   int length;
   int listsize;
};
//��ʼ���б�
int initlist(struct sqlist *l)
{
   l->elem=(elemtype*)malloc('LIS'*sizeof(elemtype));
   if(!l->elem)
	   exit(0);
   else
   {
   l->length=0;
   l->listsize='LIS';
   printf("��ʼ���б�ɹ���\n");
   }
   return 0;
}
//˳�����뺯��
int input(struct sqlist *l,int num)
{
    if(!l->elem)
	{
		printf("��ʼ��ʧ�ܣ�\n");
	    exit(0);
	}
	int i,j,m,length;
	elemtype *newbase;
	//������ݴ治��
	if(l->length+num>l->listsize)
	{
	    newbase=(elemtype*)realloc(l->elem,(l->listsize+'ladd')*sizeof(elemtype));
        if(!newbase)exit(0);
		l->elem=newbase;
		l->listsize+=ladd;
	}
	printf("���������ݣ����س�������һ�����֣�����������ݻ����ӵ���������֮��\n");
    for(i=0;i<num;i++)
	{
		length=l->length;
	    scanf("%d",&l->elem[length]);
		l->length++;
	}
	return 0;
}
//��������
int insert(struct sqlist *l,int local,elemtype elem)
{
   elemtype *newbase;
   int i,j,m,n;
   //���λ�ó���Χ��
   if(local>l->length+1||local<1)
   {   system("CLS");
	   printf("λ�ó���Χ��\n");
       for(i=0;i<l->length;i++)
		   printf("%d ",l->elem[i]);
	   printf("\n");
       return 0;
   }
   else
   {
		if(l->length+1>l->listsize)
		{
			newbase=(elemtype*)realloc(l->elem,(l->listsize+1)*sizeof(elemtype));
			if(!newbase)exit(0);
			l->elem=newbase;
			l->listsize+=1;
		}
        for(i=l->length;i>local-1;i--)
		{
		    l->elem[i]=l->elem[i-1];
		}
		l->elem[local-1]=elem;
		l->length++;
		system("CLS");
	    return 0;
   }
}
int dellocal(struct sqlist *l,int local)
{
	int i,j,m,n;
    if(local<1||local>l->length)
	{   system("CLS");
		printf("λ�ó���Χ��\n");
	    return 0;
	}
	else
	{
		for(i=local-1;i<l->length;i++)
		{
		    l->elem[i]=l->elem[i+1];
		}
		l->length--;
		system("CLS");
        return 0;
	}

}
int delvalue(struct sqlist *l,elemtype elem)
{
	int length=0,i;
	if(l->length==0)
	{	system("CLS");
		printf("��ǰΪ�գ�\n");
	    return 0;
	}
	else
	{
	    for(i=0;i<l->length;i++)
		{	if(l->elem[i]!=elem)
			{	l->elem[length]=l->elem[i];
			    length++;
			}
		}
			l->length=length;
			system("CLS");
			return 0;
	}
}
int foundlocal(struct sqlist *l,int local)
{
	if(local<1||local>l->length)
	{	printf("λ�ó��ޣ�\n");
	    system("CLS");
		return 0;
	}
	else
	{
		if(l->length==0)
		{	system("CLS");
			printf("��ǰ���������ݣ�\n");
			return 0;
		}
		else
		{system("CLS");
	    printf("��λ������Ϊ��%d\n",l->elem[local-1]);
		return 0;
		}
	}
}
int foundvalue(struct sqlist *l,elemtype elem)
{
	int i,j=0;
	if(l->length==0)
	{	system("CLS");
		printf("��ǰ���������ݣ�\n");
		return 0;
	}
	else
	{    system("CLS");
		printf("�����ݴ��ڵ�λ��Ϊ��\n");
	   for(i=0;i<l->length;i++)
		   if(l->elem[i]==elem)
		   {  printf("%d ",i+1);j++;}
		   if(j==0)
			   printf("û���ҵ�������\n");
		   else
		   printf("\n");

	return 0;
	}
}

