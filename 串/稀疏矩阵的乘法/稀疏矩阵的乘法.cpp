#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define maxsize 200
#define maxrpos 200
typedef int elemtype;
//����ṹ�壻
typedef struct
{
    int i;
    int j;
    elemtype e;
}triple;
typedef struct
{
    triple data[maxsize+1];
    int mu,nu,tu;
    int rpos[maxrpos];
}rlsmatrix;
//��ʼ��ϡ�����
void initrlsmatrix(rlsmatrix*m)
{
    if(m)
    {
        m->tu=0;
        m->mu=0;
        m->nu=0;
    }
}
//����ϡ�����
rlsmatrix* creatematrix(rlsmatrix *m)
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
        scanf("%d%d%d",&m->data[i].i,&m->data[i].j,&m->data[i].e);
    }
    return m;
}
//�õ�ϡ�����ÿһ�з���Ԫ�ĵ�һ��λ�ã�
rlsmatrix* getrpos(rlsmatrix*m)
{
    int num[maxrpos];
    for(int col=1;col<=m->mu;col++)
        num[col]=0;
    for(int t=1;t<=m->tu;t++)
        num[m->data[t].i]++;
    m->rpos[1]=1;
    for(int col=2;col<=m->mu;col++)
        m->rpos[col]=m->rpos[col-1]+num[col-1];
    return m;
}
//����ϡ�����ĳ˷����㣻
rlsmatrix*multrlsmatrix(rlsmatrix*m,rlsmatrix*n,rlsmatrix*Q)
{
    int arow,tp,p,brow,t,q,ccol;
    int ctemp[n->nu+2];
    if(m->nu!=n->mu)
    {
        printf("���������޷����г˻����㣡\n");
        exit(0);
    }
    Q->mu=m->mu,Q->nu=n->nu;
    Q->tu=0;
    if(m->tu*n->tu!=0)
    {
        for(arow=1;arow<=m->mu;arow++)
        {
            for(int x=1;x<=n->nu;x++)
                ctemp[x]=0;
            Q->rpos[arow]=Q->tu+1;
            if(arow<m->mu)
                tp=m->rpos[arow+1];
            else
                tp=m->tu+1;
            for(p=m->rpos[arow];p<tp;p++)
            {
                brow=m->data[p].j;
                if(brow<n->mu)
                    t=n->rpos[brow+1];
                else
                    t=n->tu+1;
                for(q=n->rpos[brow];q<t;q++)
                {
                    ccol=n->data[q].j;
                    ctemp[ccol]+=(m->data[p].e)*(n->data[q].e);
                }
                for(ccol=1;ccol<=Q->nu;ccol++)
                {
                    if(ctemp[ccol])
                    {
                        Q->tu++;
                        if(Q->tu>maxsize)
                        {
                            printf("�������\n");
                            exit(0);
                        }
                        else
                        {
                            Q->data[Q->tu].i=arow;
                            Q->data[Q->tu].j=ccol;
                            Q->data[Q->tu].e=ctemp[ccol];
                        }
                    }
                }
            }
        }
    }
    return Q;
}
//��������
int main()
{
    rlsmatrix m1,n1,Q1;
    rlsmatrix *m,*n,*Q;
    m=&m1,n=&n1,Q=&Q1;
    initrlsmatrix(m);
    initrlsmatrix(n);
    m=creatematrix(m);
    n=creatematrix(n);
    m=getrpos(m);
    n=getrpos(n);
    Q=multrlsmatrix(m,n,Q);
    printf("\n");
    printf("�˻�����������Ԫ���ʾΪ��\n");
    //���ﻹû�и㶮����
    for(int i=2;i<=Q->tu;i++)
    {
        printf("%d %d %d\n",Q->data[i].i,Q->data[i].j,Q->data[i].e);
    }
    return 0;
}

