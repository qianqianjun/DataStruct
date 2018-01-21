#include<stdio.h>
#include"circle-two-way-linklist.h"
void main()
{
	struct sqlist *head,*p,*q;
	struct sqlist list;
	int length,value,local;
	head=&list;
	head=NULL;
	printf("初始化一个双向不循环链表,输入小于零的数字结束输入\n");
    head=input(head);

	//获取链表长度函数：
//	length=LISTlength(head);

	//获取链表最后一个元素的指针的函数;
//	p=FOUNDw(head);

	//链表前插功能：
//	printf("请输入要前插的数值：\n");
//	scanf("%d",&value);
//	head=proinsert(head,value);

	//链表后插功能：
//	printf("请输入要增加到链表末尾的数字：\n");
//	scanf("%d",&value);
//	head=bottominsert(head,value);

	//链表位置插入函数：
//	printf("请输入要插入的位置和数值：\n");
//	scanf("%d%d",&local,&value);
//	head=insertlocal(head,local,value);

	//链表删除第一个节点函数：
//	head=DELlistt(head);

	//删除表尾函数：
//	head=DELlistw(head);

	//按位置删除函数：
//	printf("请输入要删除数据的位置：\n");
//	scanf("%d",&local);
//	head=DELlocal(head,local);

	//按数值删除函数：
//	printf("请输入要删除的数值：\n");
//	scanf("%d",&value);
//	head=DELvalue(head,value);

	//按照位置查找函数：
//	printf("请输入要查找的位置\n");
//	scanf("%d",&local);
//	p=FOUNDlocal(head,local);

	//按照值查找函数：
//	printf("请输入要查找的值:\n");
//	scanf("%d",&value);
//	local=FOUNDvalue(head,value);

	//输出检验功能：
//	print(head);
//	printf("%d\n",length);
//	printf("%d\n",p->elem);
	printf("%d\n",local);
}