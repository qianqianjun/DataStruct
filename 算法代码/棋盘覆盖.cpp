#include<iostream>
using namespace std;
int **p;
int tile=0;
/*
#define lt 4;
#define rt 3;
#define lb 2;
#define rb 1;*/
const int lt=4;
const int rt=3;
const int lb=2;
const int rb=1;
int getm(int k)
{
    if(k==1)
        return 2;
    else
    {
        return 2*getm(k-1);
    }
    return 1;
}
int printchess(int k)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
           cout<<p[i][j]<<" ";
        cout<<endl;
    }
}
int test(int k)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
            p[i][j]=1;
    }
    return 0;
}
void coverchess(int tr,int tc,int dr,int dc,int sizes)
{
    if(sizes==1)
        return;
    int t;
    int s=sizes/2;  //�ָ�������;
    if(dr<tr+s&&dc<tc+s)
        t=lt;
    else
    {
        if(dr<tr+s&&dc>=tc+s)
           t=rt;
        else
        {
            if(dr>=tr+s&&dc<tc+s)
                t=lb;
            else
            {
                if(dr>=tr+s&&dc>=tc+s)
                    t=rb;
            }
        }
    }
    //�����������Ͻǵ������̣�
    if(dr<tr+s&&dc<tc+s)
        //���ⷽ���ڴ������С�
        coverchess(tr,tc,dr,dc,s);
    else//��������û������ķ���
    {
        //��t��L�͹��Ƹ������½ǡ�
        p[tr+s-1][tc+s-1]=t;
        //�������෽��
        coverchess(tr,tc,tr+s-1,tc+s-1,s);
    }
    //�������Ͻ������̣�
    if(dr<tr+s&&dc>=tc+s)
        //���ⷽ���ڴ�������
        coverchess(tr,tc+s,dr,dc,s);
    else
    {
        //��������û�����ⷽ��
        //��t��L�ͷ��񸲸����½ǡ�
        p[tr+s-1][tc+s]=t;
        //�������෽��
        coverchess(tr,tc+s,tr+s-1,tc+s,s);
    }
    //�������½�����;
    if(dr>=tr+s&&dc<tc+s)
        //���ⷽ���ڴ������С�
        coverchess(tr+s,tc,dr,dc,s);
    else
    {
        //��t��L�͹��Ƹ������Ͻǡ�
        p[tr+s][tc+s-1]=t;
        //�������෽��
        coverchess(tr+s,tc,tr+s,tc+s-1,s);
    }
    //�������½ǵ����̡�
    if(dr>=tr+s&&dc>=tc+s)
        //���ⷽ���ڴ������С�
        coverchess(tr+s,tc+s,dr,dc,s);
    else{
        //��t��L�͹��Ƹ������Ͻǡ�
        p[tr+s][tc+s]=t;
        //�������෽��
        coverchess(tr+s,tc+s,tr+s,tc+s,s);
    }
}
int main()
{
    int k,tr,tc;
    cout<<"�������̵Ĺ�ģ��������λ�ã�ע�����Ͻǵĵ�λ��Ϊ��0 ��0���ո����"<<endl;
    cin>>k>>tr>>tc;
    k=getm(k);
    p=new int *[k];
    for(int i=0;i<k;i++)
    {
        p[i]=new int [k];
    }
    //�������㡣
    p[tr][tc]=0;
    coverchess(0,0,tr,tc,k);
    printchess(k);
    return 0;
}
