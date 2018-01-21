/*
    ��������������ʷ֣�����Ȩ����Ϊ�����ε��ܳ���
    �ƿ�1601 ��ǫ 2016014302 �������ݿ��ܲ�ȫ�棬�����⻶ӭ��ϵ�ҽ��и���
    E-mail : 2016014302@mail.buct.edu.cn
*/
/*
    �㷨������
        1.�����ӽṹ���ʣ����Ŷ���ε�Ȩֵ����������ɣ��ֱ�Ϊ���������ε�Ȩֵ���������������
        ���˴˷ֿ������������Ӷ���ε�����Ȩֵ��
        2.��̬�滮�㷨�ľ���ʵ�֡����Զ���������ά����S[i][j]��t[i][j],�ֱ��ʾ����Ϊi-1�ͱ��
        Ϊj���������������ɵ����������ε�����һ������ı��;���Ϊi-1��j�Ķ���ε�����Ȩֵ��
        �������ֻ�����������ʱ����ΪȨֵΪ0 ��
        3.������������Ķ����ȨֵΪ0������t[i][i]=0  (1<=i<=n) �� j-1>=1 ʱ��ӵ�б��Ϊi-1��j��
        �Ӷ���ε�Ȩֵt[i][j]�ɱ��Ϊi-1,k,j������ɵ����ǵ�Ȩֵgetweight(i-1,k,j)��t[i][k]+t[k+1][j]
        k��λ�ò�ȷ��������֪ i<=k<=j-1 ,��Ҫȥ�Ƚ�Ѱ�ҡ�
        ����t[i][j]=0  (i=j);
            t[i][j]=min{t[i][k]+t[k+1][j]+getwright(i-1,k,j)}  (i<=k<=j-1);

*/
#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int **a;//��Ŷ�������꣬����a[0]a[1]�Ǳ���������������ꡣ
//��������֪������ı�������Ӧ��Ȩֵ�ĺ����������������������ɵ������ε��ܳ���ΪȨֵ��
float getweight(int v1,int v2,int v3)
{
    int A=(a[v1][0]-a[v2][0])*(a[v1][0]-a[v2][0])+(a[v1][1]-a[v2][1])*(a[v1][1]-a[v2][1]);
    int B=(a[v1][0]-a[v3][0])*(a[v1][0]-a[v3][0])+(a[v1][1]-a[v3][1])*(a[v1][1]-a[v3][1]);
    int C=(a[v3][0]-a[v2][0])*(a[v3][0]-a[v2][0])+(a[v3][1]-a[v2][1])*(a[v3][1]-a[v2][1]);
    return sqrt(A)+sqrt(B)+sqrt(C);
}
//�����Ƕ�̬�滮�����㷨�����������������Ρ�
int MinWeightTreeDiv(int n,float **t,int **s)
{
    for(int i=1;i<=n;i++)
        t[i][i]=0;
    for(int r=1;r<n;r++)  //��ʾ�������ζ���ĸ�����������������㿪ʼ����Ϊ��������Ȩֵ��Ϊ���㡣
    {
        for(int i=1;i<= n-r;i++)
        {
            int j=i+r;
            t[i][j]=t[i+1][j]+getweight(i-1,i,j);
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int u=t[i][k]+t[k+1][j]+getweight(i-1,k,j);  //���Ѿ�������Ľ�����������ã������ظ����㡣
                if(u<t[i][j]) //���ֵ�ǰ���Ų������յ����ţ���Ҫ��������ֵ�����������εĵ���������ı�š�
                {
                    t[i][j]=u;
                    s[i][j]=k;
                }
            }
        }
    }
}
//�ݹ��������������ʷֵĽ����
void PrintResult(int i,int j,int **s)
{
    if(i==j)
        return;
    PrintResult(i,s[i][j],s);
    PrintResult(s[i][j]+1,j,s);
    cout<<"�����ʷֶ��㣺V"<<i-1<<",V"<<j<<",V"<<s[i][j]<<endl;
}
int main()
{
    int num,**s;//����ĸ��������ڴ洢����λ�õĶ�ά���顣
    float **t;//���������Ȩֵ�Ķ�ά���顣
    cout<<"���������ε�ĸ���"<<endl;
    cin>>num;
    //�����ڴ������
    //��������û���õ������к͵����С�
    a=new int *[num+1];
    t=new float *[num+1];
    s=new int *[num+1];
    for(int i=0;i<num+1;i++)
    {
        a[i]=new int [2];
        t[i]=new float [num+1];
        s[i]=new int [num+1];
    }
    cout<<"������������λ��"<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    //��̬�滮�ҵ����ŵĶ���Ρ�
    MinWeightTreeDiv(num,t,s);
    PrintResult(1,num-1,s);//������
    //�ͷ��ڴ�Ĳ�����
    for(int i=0;i<num+1;i++)
    {
        delete [] a[i];
        delete [] t[i];
        delete [] s[i];
    }
    delete [] s;
    delete [] t;
    delete [] a;
    return 0;
}
