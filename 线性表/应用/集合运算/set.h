#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LIS 100;//定义表的初始化长度。
#define ladd 10;//表空间不足时的增量为
typedef int elemtype;
//交，并集表的结构：
struct sqlist
{
   elemtype *elem;
   int length;
   int listsize;
};
//初始化交，并集表的函数；
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
//交集运算的函数；
int intersection(int *pa,int lengtha,67int *pb,int lengthb,struct sqlist *jiao)
{
	int i,j,t,a=0,b=0;
	elemtype *newbase;
	if(lengtha==0||lengthb==0)
		printf("交集为空集！\n");
	else
	{
		//集合进行排序：
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
		//集合之间开始寻找相同元素：
		while(1)
		{
			if(*(pa+a)==*(pb+b))//找到相同元素
			{
				//存放交集元素的数组长度不够了,扩增：
				 if(jiao->length+1>jiao->listsize)
				 {
					newbase=(elemtype*)realloc(jiao->elem,(jiao->listsize+'ladd')*sizeof(elemtype));
					if(!newbase)exit(0);
					jiao->elem=newbase;
					jiao->listsize+=ladd;
				 }
				 //存放交集元素：
				 jiao->elem[jiao->length]=*(pa+a);
				 jiao->length++;
				 //如果有到达终点的集合，结束循环；
				 if(a==lengtha||b==lengthb)
					 break;
				 //没有到达的话，指针后移；
				 else
				 {
					 a++;
					 b++;
				 }
			}
			else//如果不相等，则移动两个数中的最小值；
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
		//执行完毕！
	}
	return jiao->length;
}
//并集运算函数：
int unisection(int *pa,int lengtha,int *pb,int lengthb,struct sqlist *bing)
{
	int i,j,flag=0;
	elemtype *newbase;
	if(lengtha==0&&lengthb==0)
	{	printf("并集为空集！\n");return 0;}




	if(lengtha>=lengthb)
	{
		for(i=0;i<lengtha;i++)
		{
		    bing->elem[i]=*(pa+i);
		}
		bing->length=lengtha;
		//判断个数少的集合中元素是否在集合多的元素中包含；
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
			//如果不包含
			else
			{
			    //存放并集元素的数组长度不够了,扩增：
				 if(bing->length+1>bing->listsize)
				 {
					newbase=(elemtype*)realloc(bing->elem,(bing->listsize+'ladd')*sizeof(elemtype));
					if(!newbase)exit(0);
					bing->elem=newbase;
					bing->listsize+=ladd;
				 }
				 //存放并集元素：
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
		//判断个数少的集合中元素是否在集合多的元素中包含；
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
			//如果不包含
			else
			{
				//存放并集元素的数组长度不够了,扩增：
				 if(bing->length+1>bing->listsize)
				 {
					newbase=(elemtype*)realloc(bing->elem,(bing->listsize+'ladd')*sizeof(elemtype));
					if(!newbase)exit(0);
					bing->elem=newbase;
					bing->listsize+=ladd;
				 }
				 //存放并集元素：
				 bing->elem[bing->length]=*(pa+i);
				 bing->length++;
			}
		}
	}
return bing->length;
}

