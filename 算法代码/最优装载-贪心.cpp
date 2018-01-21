#include<iostream>
using namespace std;
int quicksort(int *&v,int *&v1,int low,int high)
{
    int i,j,temp,temp1;
    i=low,j=high;
    temp=v[low];
    temp1=v1[low];
    if(i<j)
    {
        while(i<j)
        {
            while(i<j&&v[j]>=temp) j--;
            {
                v[i]=v[j];
                v1[i]=v1[j];
            }
            while(i<j&&v[i]<=temp) i++;
            {
                v[j]=v[i];
                v1[j]=v1[i];
            }
        }
        v[i]=temp;
        v1[i]=temp1;
        quicksort(v,v1,low,i-1);
        quicksort(v,v1,i+1,high);
    }
    return 0;
}
void Loading(int *&x,int *&v,int *v1,int num,int maxweight)
{
    quicksort(v,v1,0,num-1);
    int weight=maxweight;
    int i=0;
    while(weight>0&&i<num)
    {
        if(weight-v[i]>0)
            x[v1[i]]=1;
        weight-=v[i];
        i++;
    }
    return ;
}
int main()
{
    int *v,*x,*v1,num,maxweight;
    cout<<"输入集装箱的个数和最大承重量"<<endl;
    cin>>num>>maxweight;
    v=new int [num+1];
    v1=new int [num+1];
    x=new int [num+1];
    for(int i=0;i<num;i++)
    {
        cin>>v[i];
        v1[i]=i;
        x[i]=0;
    }
    Loading(x,v,v1,num,maxweight);
    for(int i=0;i<num;i++)
        cout<<x[i]<<" ";
    cout<<endl;
    delete [] v;
    delete [] v1;
    delete [] x;
    return 0;
}
