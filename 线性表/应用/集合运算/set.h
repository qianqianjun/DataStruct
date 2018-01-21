#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LIS 100;//�����ĳ�ʼ�����ȡ�
#define ladd 10;//��ռ䲻��ʱ������Ϊ
typedef int elemtype;
//����������Ľṹ��
struct sqlist
{
   elemtype *elem;
   int length;
   int listsize;
};
//��ʼ������������ĺ�����
int initlist(struct sqlist *l)
{
   l->elem=(elemtype*)malloc('LIS'*sizeof(elemtype));
   if(!l->elem)
	   exit(0);
   else
   {
   l->length=0;
   l->listsize='LIS';
   }
   return 0;
}
//��������ĺ�����
int intersection(int *pa,int lengtha,67int *pb,int lengthb,struct sqlist *jiao)
{
	int i,j,t,a=0,b=0;
	elemtype *newbase;
	if(lengtha==0||lengthb==0)
		printf("����Ϊ�ռ���\n");
	else
	{
		//���Ͻ�������
		for(j=0;j<lengtha;j++)
		{
			for(i=0;i<lengtha-j-1;i++)
			{
				if(*(pa+i)>*(pa+i+1))
				{
					t=*(pa+i);
					*(pa+i)=*(pa+i+1);
					*(pa+i+1)=t;
				}
			}
		}
		for(j=0;j<lengthb;j++)
		{
			for(i=0;i<lengthb-1-j;i++)
			{
				if(*(pb+i)>*(pb+i+1))
				{	t=*(pb+i);
					*(pb+i)=*(pb+i+1);
					*(pb+i+1)=t;
				}
			}
		}
		//����֮�俪ʼѰ����ͬԪ�أ�
		while(1)
		{
			if(*(pa+a)==*(pb+b))//�ҵ���ͬԪ��
			{
				//��Ž���Ԫ�ص����鳤�Ȳ�����,������
				 if(jiao->length+1>jiao->listsize)
				 {
					newbase=(elemtype*)realloc(jiao->elem,(jiao->listsize+'ladd')*sizeof(elemtype));
					if(!newbase)exit(0);
					jiao->elem=newbase;
					jiao->listsize+=ladd;
				 }
				 //��Ž���Ԫ�أ�
				 jiao->elem[jiao->length]=*(pa+a);
				 jiao->length++;
				 //����е����յ�ļ��ϣ�����ѭ����
				 if(a==lengtha||b==lengthb)
					 break;
				 //û�е���Ļ���ָ����ƣ�
				 else
				 {
					 a++;
					 b++;
				 }
			}
			else//�������ȣ����ƶ��������е���Сֵ��
			{
				 if(a==lengtha||b==lengthb)
					 break;
				 else
				 {
					 if(*(pa+a)>*(pb+b))
						 b++;
					 else
						 a++;
				 }
			}
		}
		//ִ����ϣ�
	}
	return jiao->length;
}
//�������㺯����
int unisection(int *pa,int lengtha,int *pb,int lengthb,struct sqlist *bing)
{
	int i,j,flag=0;
	elemtype *newbase;
	if(lengtha==0&&lengthb==0)
	{	printf("����Ϊ�ռ���\n");return 0;}




	if(lengtha>=lengthb)
	{
		for(i=0;i<lengtha;i++)
		{
		    bing->elem[i]=*(pa+i);
		}
		bing->length=lengtha;
		//�жϸ����ٵļ�����Ԫ���Ƿ��ڼ��϶��Ԫ���а�����
	    for(i=0;i<lengthb;i++)
		{
			flag=0;
		    for(j=0;j<lengtha;j++)
			{
			    if(*(pb+i)==*(pa+j))
				{	flag=1;break;}
			}
			if(flag==1)
				continue;
			//���������
			else
			{
			    //��Ų���Ԫ�ص����鳤�Ȳ�����,������
				 if(bing->length+1>bing->listsize)
				 {
					newbase=(elemtype*)realloc(bing->elem,(bing->listsize+'ladd')*sizeof(elemtype));
					if(!newbase)exit(0);
					bing->elem=newbase;
					bing->listsize+=ladd;
				 }
				 //��Ų���Ԫ�أ�
				 bing->elem[bing->length]=*(pb+i);
				 bing->length++;
			}
		}
	}
	else
	{
		for(i=0;i<lengthb;i++)
		{
			bing->elem[i]=*(pb+i);
		}
		bing->length=lengthb;
		//�жϸ����ٵļ�����Ԫ���Ƿ��ڼ��϶��Ԫ���а�����
		for(i=0;i<lengtha;i++)
		{
			flag=0;
			for(j=0;j<lengthb;j++)
			{
				if(*(pa+i)==*(pb+j))
				{	flag=1;break;}
			}
			if(flag==1)
				continue;
			//���������
			else
			{
				//��Ų���Ԫ�ص����鳤�Ȳ�����,������
				 if(bing->length+1>bing->listsize)
				 {
					newbase=(elemtype*)realloc(bing->elem,(bing->listsize+'ladd')*sizeof(elemtype));
					if(!newbase)exit(0);
					bing->elem=newbase;
					bing->listsize+=ladd;
				 }
				 //��Ų���Ԫ�أ�
				 bing->elem[bing->length]=*(pa+i);
				 bing->length++;
			}
		}
	}
return bing->length;
}

