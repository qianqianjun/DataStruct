#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef int elemtype;
#define maxsize 2500
//结构体定义；
struct triple
{
    int row;
    int col;
    elemtype e;
};
struct tsmatrix
{
    struct triple data[maxsize+1];
    int mu,nu,tu;
};
//三元表的初始化；
struct tsmatrix* initmatrix(struct tsmatrix*m)
{
    if(m)
    {
        m=(struct tsmatrix*)malloc(maxsize*sizeof(struct tsmatrix));
        if(!m)
        {
            printf("内存分配失败");
            exit(0);
        }
        m->tu=0;
        m->mu=0;
        m->nu=0;
        return m;
    }
}
//创建三元表的函数；
struct tsmatrix* creatematrix(struct tsmatrix *m)
{
    printf("请输入稀疏矩阵的行数，列数，非零元的个数(中间用空格隔开)\n");
    int row,col,num;
    scanf("%d%d%d",&m->mu,&m->nu,&m->tu);
    if((m->nu)*(m->mu)<m->tu)
    {
        printf("输入有误，程序终止");
        exit(0);
    }
    printf("请输入稀疏矩阵的三元组表\n");
    for(int i=1;i<=m->tu;i++)
    {
        scanf("%d%d%d",&m->data[i].row,&m->data[i].col,&m->data[i].e);
    }
    return m;
}
//算法5。1 的转置算法；
int transformsmatrix(struct tsmatrix *m,struct tsmatrix *t)
{
    t->mu=m->nu;
    t->nu=m->mu;
    t->tu=m->tu;
    if(t->tu)
    {
        int q=1;
        for(int col=1;col<=m->nu;col++)
        {
            for(int p=1;p<=m->tu;p++)
            {
                if(m->data[p].col==col)
                {
                    t->data[q].row=m->data[p].col;
                    t->data[q].col=m->data[p].row;
                    t->data[q].e=m->data[p].e;
                    q++;
                }
            }
        }
    }
    return 0;
}
//算法5.2 转置函数；
int fasttransformsmatrix(struct tsmatrix*m,struct tsmatrix*t)
{
    int num[50];
    int cpot[50];
    t->mu=m->nu;
    t->nu=m->mu;
    t->tu=m->tu;
    if(t->tu)
    {
        for(int col=1;col<=m->nu;col++)
            num[col]=0;
        for(int t=1;t<=m->tu;t++)
            num[m->data[t].col]++;
        cpot[1]=1;
        for(int col=2;col<=m->nu;col++)
            cpot[col]=cpot[col-1]+num[col-1];
        for(int p=1;p<=m->tu;p++)
        {
            int col=m->data[p].col;
            int q=cpot[col];
            t->data[q].row=m->data[p].col;
            t->data[q].col=m->data[p].row;
            t->data[q].e=m->data[p].e;
            cpot[col]++;
        }
    }
    return 0;
}
int main()
{
    struct tsmatrix m1,t1;
    struct tsmatrix *m,*t;
    m=&m1;
    t=&t1;
    //初始化；
    t=initmatrix(t);
    m=initmatrix(m);
    //创建；
    m=creatematrix(m);
    //算法5.1 转置方法；
    transformsmatrix(m,t);
    printf("用算法5.1转置后的矩阵为：\n");
    for(int i=1;i<=t->tu;i++)
    {
        printf("%d %d %d\n",t->data[i].row,t->data[i].col,t->data[i].e);
    }
    //算法5.2转置法方法；
    fasttransformsmatrix(m,t);
    printf("用算法5.2转置后的矩阵为：\n");
    for(int i=1;i<=t->tu;i++)
    {
        printf("%d %d %d\n",t->data[i].row,t->data[i].col,t->data[i].e);
    }
    return 0;
}
