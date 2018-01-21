#include<stdio.h>
#include"double-one-way-linklist.h"
void main()
{
    struct sqlist list;
    int local,length,value;
	struct sqlist *head,*p;
	head=&list;
	head=NULL;

	//开始输入一个列表。
	printf("现在开始初始化一个列表吧,输入负数结束：\n");
	head=input(head);

	//任意位置插入函数：
//	printf("请输入插入的位置和插入的数据：\n");
//	scanf("%d%d",&local,&value);
//	head=insert(head,local,value);

	//链表头插入函数：
//	printf("请输入要插入链表头的数据：\n");
//	scanf("%d",&value);
//	head=proinsert(head,value);

	//链表尾插入函数：
//	printf("请输入要插入链表尾的数据：\n");
//	scanf("%d",&value);
//	head=bottominsert(head,value);

	//按位置删除函数：
//	printf("请输入要删除数据所在的位置：\n");
//	scanf("%d",&local);
//	head=DELlocal(head,local);

	//按值删除函数：
//	printf("请输入要删除的数据：\n");
//	scanf("%d",&value);
//	head=DELvalue(head,value);

	//删除第一个节点函数。
//	head=DELlistt(head);

	//删除表尾的数据的函数：
//	head=DELlistw(head);

	//链表获取长度函数：
//	length=LISTlength(head);

    //按位置查找函数：
//	printf("请输入要查找的位置：\n");
//	scanf("%d",&local);
//	p=FOUNDlocal(head,local);    

	//按值查找函数
//	 printf("请输入查找的数值：\n");
//	 scanf("%d",&value);
//	 local=FOUNDvalue(head,value);

	//获取表尾函数：
//	p=FOUNDw(head);

	//输出验证是否成功
	
	// print(head);
	//printf("%d",length);
	//printf("%d\n",p->elem);
	// printf("%d\n",local);
}