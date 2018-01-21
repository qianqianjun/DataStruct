#include<stdio.h>
#include"esquence-list.h"
int main()
{
   int i,j,m,n,s,e,w,flag=0,cas;
   elemtype elem;
   struct sqlist list;
   struct sqlist *p;
   p=&list;
   initlist(p);
   while(e!=0)
   {
	   printf("***************************\n");
	   printf("* 请选择服务项目！        *\n");
	   printf("* 1--顺序输入             *\n");
	   printf("* 2--插入输入             *\n");
	   printf("* 3--删除数据             *\n");
	   printf("* 4--查找数据             *\n");
	   printf("* 0--退出程序             *\n");
	   printf("***************************\n");
      scanf("%d",&e);
      switch(e)
	  {
	    case 1:{printf("请输入输入数据的个数：\n");
			    scanf("%d",&m);
			    input(p,m);flag++;
			    system("CLS");
			    printf("当前数据为：\n");
			    for(i=0;i<p->length;i++)
					printf("%d ",p->elem[i]);
				printf("\n");
			    break;}
		case 2:{
			    if(flag==0)
				{
					system("CLS");
				   printf("当前没有数据，请先进行第一步输入数据之后再进行插入操作！\n");
				   break;
				}
				else
				{   printf("请输入插入数据的位置：\n");
				    scanf("%d",&w);
					printf("请输入插入的数据:\n");
					scanf("%d",&elem);
					insert(p,w,elem);
					printf("当前数据为：\n");
					for(i=0;i<p->length;i++)
						printf("%d ",p->elem[i]);
					printf("\n");
					break;}
			   }
		case 3:{
			       if(flag==0)
				   {
					   system("CLS");
					   printf("当前没有任何数据，请先进行第一步的操作！\n");
					   break;
				   }
				   else
				   {   printf("请选择删除方式！\n");
				       printf("0--位置删除  1--数值删除\n");
					   scanf("%d",&cas);
					   switch(cas)
					   {
					   case 0:{printf("请输入位置：\n");
						       scanf("%d",&w);
						       del(p,w);
							   printf("当前数据为：\n");
							   for(i=0;i<p->length;i++)
								   printf("%d ",p->elem[i]);
							   printf("\n");
							   break;}
					   case 1:{printf("请输入删除的数据：\n");
						       scanf("%d",&elem);
						       del1(p,elem);
							   printf("当前数据为：\n");
							   for(i=0;i<p->length;i++)
								   printf("%d ",p->elem[i]);
							   printf("\n");
						       break;}
					   default:printf("该指令无效！\n");break;
					   }
			           break;
				   }
			   }
		case 4:{
			      if(flag==0)
				  {
				      system("CLS");
					  printf("当前没有任何数据，请先进行第一步的操作！\n");
					  break;
				  }
			      else
				  {
				      printf("请选择查找方式：\n");
					  printf("0--位置检索   1--数值检索\n");
					  scanf("%d",&cas);
					  switch(cas)
					  {
					  case 0:{printf("请输入位置：\n");
						      scanf("%d",&w);
							  found(p,w);
							  printf("当前数据为：\n");
							  for(i=0;i<p->length;i++)
								  printf("%d ",p->elem[i]);
							  printf("\n");
						      break;}
					  case 1:{printf("请输入数据：\n");
						      scanf("%d",&elem);
							  found1(p,elem);
							  printf("当前数据为：\n");
							  for(i=0;i<p->length;i++)
							  printf("%d ",p->elem[i]);
							  printf("\n");
						      break;}
					  default:{printf("指令无效！\n");
						       for(i=0;i<p->length;i++)
								   printf("%d ",p->elem[i]);
						       printf("\n");
							   break;}
					  }
					  break;
				  }
			   }
		case 0:printf("谢谢使用，再见！\n");break;
		default:{system("CLS");printf("您说什么，臣妾听不懂！\n");break;}
	  }
   }
   return 0;
}