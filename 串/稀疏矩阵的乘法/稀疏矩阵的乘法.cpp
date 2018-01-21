#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define maxsize 200
#define maxrpos 200
typedef int elemtype;
//定义结构体；
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
//初始化稀疏矩阵；
void initrlsmatrix(rlsmatrix*m)
{
    if(m)
    {
        m->tu=0;
        m->mu=0;
        m->nu=0;
    }
}
//输入稀疏矩阵；
rlsmatrix* creatematrix(rlsmatrix *m)
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
        scanf("%d%d%d",&m->data[i].i,&m->data[i].j,&m->data[i].e);
    }
    return m;
}
//得到稀疏矩阵每一行非零元的第一个位置；
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
//两个稀疏矩阵的乘法运算；
rlsmatrix*multrlsmatrix(rlsmatrix*m,rlsmatrix*n,rlsmatrix*Q)
{
    int arow,tp,p,brow,t,q,ccol;
    int ctemp[n->nu+2];
    if(m->nu!=n->mu)
    {
        printf("两个矩阵无法进行乘积运算！\n");
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
                            printf("程序出错\n");
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
//主函数；
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
    printf("乘积结果矩阵的三元组表示为：\n");
    //这里还没有搞懂啊；
    for(int i=2;i<=Q->tu;i++)
    {
        printf("%d %d %d\n",Q->data[i].i,Q->data[i].j,Q->data[i].e);
    }
    return 0;
}

