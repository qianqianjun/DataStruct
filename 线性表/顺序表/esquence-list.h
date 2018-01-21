#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LIS 100;//定义表的初始化长度。
#define ladd 10;//表空间不足时的增量为
typedef int elemtype;
struct sqlist
{
   elemtype *elem;
   int length;
   int listsize;
};
//初始化列表。
int initlist(struct sqlist *l)
{
   l->elem=(elemtype*)malloc('LIS'*sizeof(elemtype));
   if(!l->elem)
	   exit(0);
   else
   {
   l->length=0;
   l->listsize='LIS';
   printf("初始化列表成功！\n");
   }
   return 0;
}
//顺序输入函数
int input(struct sqlist *l,int num)
{
    if(!l->elem)
	{
		printf("初始化失败！\n");
	    exit(0);
	}
	int i,j,m,length;
	elemtype *newbase;
	//如果数据存不下
	if(l->length+num>l->listsize)
	{
	    newbase=(elemtype*)realloc(l->elem,(l->listsize+'ladd')*sizeof(elemtype));
        if(!newbase)exit(0);
		l->elem=newbase;
		l->listsize+=ladd;
	}
	printf("请输入数据，按回车输入下一个数字，您输入的数据会增加到已有数据之后！\n");
    for(i=0;i<num;i++)
	{
		length=l->length;
	    scanf("%d",&l->elem[length]);
		l->length++;
	}
	return 0;
}
//插入输入
int insert(struct sqlist *l,int local,elemtype elem)
{
   elemtype *newbase;
   int i,j,m,n;
   //如果位置超范围；
   if(local>l->length+1||local<1)
   {   system("CLS");
	   printf("位置超范围！\n");
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
		printf("位置超范围！\n");
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
		printf("当前为空！\n");
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
	{	printf("位置超限！\n");
	    system("CLS");
		return 0;
	}
	else
	{
		if(l->length==0)
		{	system("CLS");
			printf("当前表中无数据：\n");
			return 0;
		}
		else
		{system("CLS");
	    printf("该位置数据为：%d\n",l->elem[local-1]);
		return 0;
		}
	}
}
int foundvalue(struct sqlist *l,elemtype elem)
{
	int i,j=0;
	if(l->length==0)
	{	system("CLS");
		printf("当前表中无数据：\n");
		return 0;
	}
	else
	{    system("CLS");
		printf("该数据存在的位置为：\n");
	   for(i=0;i<l->length;i++)
		   if(l->elem[i]==elem)
		   {  printf("%d ",i+1);j++;}
		   if(j==0)
			   printf("没有找到该数据\n");
		   else
		   printf("\n");

	return 0;
	}
}

