#include<stdio.h>
#include"set.h"
int main()
{
	struct sqlist jiaojibiao;
	struct sqlist bingjibiao;
	struct sqlist *j,*bi;
	int na,nb,numjiao,numbing,i;
	//���ϳ�ʼ����
    int a[9]={1,2,3,4,5,7,8,9,0},b[8]={10,9,4,6,3,2,5,1};
	na=sizeof(a)/sizeof(int);
	nb=sizeof(b)/sizeof(int);
	//��ɽ������㣻
	j=&jiaojibiao;
	initlist(j);//��ʼ��������
	numjiao=intersection(a,na,b,nb,j);
	printf("��������Ϊ��\n");
	for(i=0;i<numjiao;i++)
		printf("%d ",j->elem[i]);
	//��ɲ������㣻
	bi=&bingjibiao;
	initlist(bi);//��ʼ��������
	numbing=unisection(a,na,b,nb,bi);
	printf("����Ϊ��\n");
	for(i=0;i<numbing;i++)
		printf("%d ",bi->elem[i]);
    return 0;
}
