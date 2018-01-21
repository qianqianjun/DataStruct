#include<stdio.h>
#include"set.h"
int main()
{
	struct sqlist jiaojibiao;
	struct sqlist bingjibiao;
	struct sqlist *j,*bi;
	int na,nb,numjiao,numbing,i;
	//集合初始化；
    int a[9]={1,2,3,4,5,7,8,9,0},b[8]={10,9,4,6,3,2,5,1};
	na=sizeof(a)/sizeof(int);
	nb=sizeof(b)/sizeof(int);
	//完成交集运算；
	j=&jiaojibiao;
	initlist(j);//初始化交集表；
	numjiao=intersection(a,na,b,nb,j);
	printf("交集集合为：\n");
	for(i=0;i<numjiao;i++)
		printf("%d ",j->elem[i]);
	//完成并集计算；
	bi=&bingjibiao;
	initlist(bi);//初始化并集表；
	numbing=unisection(a,na,b,nb,bi);
	printf("并集为：\n");
	for(i=0;i<numbing;i++)
		printf("%d ",bi->elem[i]);
    return 0;
}
