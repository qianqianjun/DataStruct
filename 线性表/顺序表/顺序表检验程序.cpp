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
	   printf("* ��ѡ�������Ŀ��        *\n");
	   printf("* 1--˳������             *\n");
	   printf("* 2--��������             *\n");
	   printf("* 3--ɾ������             *\n");
	   printf("* 4--��������             *\n");
	   printf("* 0--�˳�����             *\n");
	   printf("***************************\n");
      scanf("%d",&e);
      switch(e)
	  {
	    case 1:{printf("�������������ݵĸ�����\n");
			    scanf("%d",&m);
			    input(p,m);flag++;
			    system("CLS");
			    printf("��ǰ����Ϊ��\n");
			    for(i=0;i<p->length;i++)
					printf("%d ",p->elem[i]);
				printf("\n");
			    break;}
		case 2:{
			    if(flag==0)
				{
					system("CLS");
				   printf("��ǰû�����ݣ����Ƚ��е�һ����������֮���ٽ��в��������\n");
				   break;
				}
				else
				{   printf("������������ݵ�λ�ã�\n");
				    scanf("%d",&w);
					printf("��������������:\n");
					scanf("%d",&elem);
					insert(p,w,elem);
					printf("��ǰ����Ϊ��\n");
					for(i=0;i<p->length;i++)
						printf("%d ",p->elem[i]);
					printf("\n");
					break;}
			   }
		case 3:{
			       if(flag==0)
				   {
					   system("CLS");
					   printf("��ǰû���κ����ݣ����Ƚ��е�һ���Ĳ�����\n");
					   break;
				   }
				   else
				   {   printf("��ѡ��ɾ����ʽ��\n");
				       printf("0--λ��ɾ��  1--��ֵɾ��\n");
					   scanf("%d",&cas);
					   switch(cas)
					   {
					   case 0:{printf("������λ�ã�\n");
						       scanf("%d",&w);
						       del(p,w);
							   printf("��ǰ����Ϊ��\n");
							   for(i=0;i<p->length;i++)
								   printf("%d ",p->elem[i]);
							   printf("\n");
							   break;}
					   case 1:{printf("������ɾ�������ݣ�\n");
						       scanf("%d",&elem);
						       del1(p,elem);
							   printf("��ǰ����Ϊ��\n");
							   for(i=0;i<p->length;i++)
								   printf("%d ",p->elem[i]);
							   printf("\n");
						       break;}
					   default:printf("��ָ����Ч��\n");break;
					   }
			           break;
				   }
			   }
		case 4:{
			      if(flag==0)
				  {
				      system("CLS");
					  printf("��ǰû���κ����ݣ����Ƚ��е�һ���Ĳ�����\n");
					  break;
				  }
			      else
				  {
				      printf("��ѡ����ҷ�ʽ��\n");
					  printf("0--λ�ü���   1--��ֵ����\n");
					  scanf("%d",&cas);
					  switch(cas)
					  {
					  case 0:{printf("������λ�ã�\n");
						      scanf("%d",&w);
							  found(p,w);
							  printf("��ǰ����Ϊ��\n");
							  for(i=0;i<p->length;i++)
								  printf("%d ",p->elem[i]);
							  printf("\n");
						      break;}
					  case 1:{printf("���������ݣ�\n");
						      scanf("%d",&elem);
							  found1(p,elem);
							  printf("��ǰ����Ϊ��\n");
							  for(i=0;i<p->length;i++)
							  printf("%d ",p->elem[i]);
							  printf("\n");
						      break;}
					  default:{printf("ָ����Ч��\n");
						       for(i=0;i<p->length;i++)
								   printf("%d ",p->elem[i]);
						       printf("\n");
							   break;}
					  }
					  break;
				  }
			   }
		case 0:printf("ллʹ�ã��ټ���\n");break;
		default:{system("CLS");printf("��˵ʲô�������������\n");break;}
	  }
   }
   return 0;
}