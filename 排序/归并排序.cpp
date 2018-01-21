#include<iostream>
#include<malloc.h>
using namespace std;
class sqlist
{
    public:int num,maxnum,*v;
    public:
    sqlist()
    {
        num=0;
        maxnum=100;
        v=(int *)malloc(100*sizeof(int));
    }
    int pushback(int elem)
    {
        if(num+1<maxnum)
        {
            v[num]=elem;
            num++;
        }
        else
        {
            maxnum+=10;
            v=(int *)realloc(v,maxnum*sizeof(int));
            v[num]=elem;
            num++;
        }
        return 0;
    }
    int length()
    {
        return this->num;
    }
    //�����ǹ鲢������㷨��
    int Merge(int *&v,int low,int mid,int high)  //һ�ζ�·�鲢�����������ڵ����������й鲢Ϊһ����������С�
    {
        int *r;
        int i=low,j=mid+1,k=0;
        r=(int*)malloc((high-low+1)*sizeof(int));
        while(i<=mid&&j<=high)
        {
            if(v[i]<=v[j])
            {
                r[k]=v[i];
                i++;
                k++;
            }
            else
            {
                r[k]=v[j];
                j++;
                k++;
            }
        }
        while(i<=mid)
        {
            r[k]=v[i];
            i++;
            k++;
        }
        while(j<=high)
        {
            r[k]=v[j];
            j++;
            k++;
        }
        for(k=0,i=low;i<=high;k++,i++)
            v[i]=r[k];
        free(r);
        return 0;
    }
    void mergepass(int *&v,int length,int n)   //һ�˶�·�鲢
    {
        int i;
        for(i=0;i+2*length-1<n;i=i+2*length)  //�鲢length�������������ӱ�
            this->Merge(v,i,i+length-1,i+2*length-1);
        if(i+length-1<n)  //���������ӱ����߳���С��length
            this->Merge(v,i,i+length-1,n-1);   //�鲢�������ӱ�
    }
    void mergesort()
    {
        int length;
        for(length=1;length<this->num;length=2*length)
            this->mergepass(this->v,length,this->num);
    }
};
int main()
{
    sqlist l;
    int elem;
    while(cin>>elem)
    {
        l.pushback(elem);
    }
    l.mergesort();
    for(int i=0;i<l.length();i++)
    {
        cout<<l.v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
