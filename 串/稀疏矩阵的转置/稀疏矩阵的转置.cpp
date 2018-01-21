#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef int elemtype;
#define maxsize 2500
//�ṹ�嶨�壻
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
//��Ԫ��ĳ�ʼ����
struct tsmatrix* initmatrix(struct tsmatrix*m)
{
    if(m)
    {
        m=(struct tsmatrix*)malloc(maxsize*sizeof(struct tsmatrix));
        if(!m)
        {
            printf("�ڴ����ʧ��");
            exit(0);
        }
        m->tu=0;
        m->mu=0;
        m->nu=0;
        return m;
    }
}
//������Ԫ��ĺ�����
struct tsmatrix* creatematrix(struct tsmatrix *m)
{
    printf("������ϡ����������������������Ԫ�ĸ���(�м��ÿո����)\n");
    int row,col,num;
    scanf("%d%d%d",&m->mu,&m->nu,&m->tu);
    if((m->nu)*(m->mu)<m->tu)
    {
        printf("�������󣬳�����ֹ");
        exit(0);
    }
    printf("������ϡ��������Ԫ���\n");
    for(int i=1;i<=m->tu;i++)
    {
        scanf("%d%d%d",&m->data[i].row,&m->data[i].col,&m->data[i].e);
    }
    return m;
}
//�㷨5��1 ��ת���㷨��
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
//�㷨5.2 ת�ú�����
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
    //��ʼ����
    t=initmatrix(t);
    m=initmatrix(m);
    //������
    m=creatematrix(m);
    //�㷨5.1 ת�÷�����
    transformsmatrix(m,t);
    printf("���㷨5.1ת�ú�ľ���Ϊ��\n");
    for(int i=1;i<=t->tu;i++)
    {
        printf("%d %d %d\n",t->data[i].row,t->data[i].col,t->data[i].e);
    }
    //�㷨5.2ת�÷�������
    fasttransformsmatrix(m,t);
    printf("���㷨5.2ת�ú�ľ���Ϊ��\n");
    for(int i=1;i<=t->tu;i++)
    {
        printf("%d %d %d\n",t->data[i].row,t->data[i].col,t->data[i].e);
    }
    return 0;
}
