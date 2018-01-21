#include<iostream>
#include<cstdio>
using namespace std;
void Sort(float *&value,float *&weight,float *&cost,int low,int high,int *&target)
{
    int i,j,temp3;
    float temp,temp1,temp2;
    i=low,j=high;
    if(i<j)
    {
        temp=cost[low];
        temp1=value[low];
        temp2=weight[low];
        temp3=target[low];
        while(i!=j)
        {
            while(i<j&&cost[j]<=temp) j--;
            cost[i]=cost[j];
            value[i]=value[j];
            weight[i]=weight[j];
            target[i]=target[j];
            while(i<j&&cost[i]>=temp) i++;
            cost[j]=cost[i];
            value[j]=value[i];
            weight[j]=weight[i];
            target[j]=target[i];
        }
        cost[i]=temp;
        value[i]=temp1;
        weight[i]=temp2;
        target[i]=temp3;
        Sort(value,weight,cost,low,i-1,target);
        Sort(value,weight,cost,i+1,high,target);
    }
}
void QuickSort(int num,float *&weight,float *&value,int *&target)
{
    float *cost;
    cost=new float [num+1];
    for(int i=0;i<num;i++)
    {
        cost[i]=value[i]/weight[i];
    }
    Sort(value,weight,cost,0,num-1,target);
    /*for(int i=0;i<num;i++)
    {
        printf("%4.2f %4.2f %4.2f %d\n",cost[i],value[i],weight[i],target[i]);
    }
    cout<<endl;*/
}
void backpack(int num,float *&weight,float *&value,float *&take,float v,int *target)
{
    QuickSort(num,weight,value,target);
    int i;
    for(i=0;i<num;i++)
    {
        if(v>=weight[i])
        {
            v-=weight[i];
            take[target[i]]=1;
        }
        else
            break;
    }
    if(i<=num-1)
        take[target[i]]=v/weight[i];
}
int main()
{
    float *value,*weight,*take,v;
    int num,*target;
    cout<<"输入物品个数和背包容量"<<endl;
    cin>>num>>v;
    value=new float [num+1];
    weight=new float [num+1];
    take=new float [num+1];
    target=new int [num+1];
    cout<<"输入物品的价值和重量"<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>value[i]>>weight[i];
        take[i]=0;
        target[i]=i;
    }
    backpack(num,weight,value,take,v,target);
    for(int i=0;i<num;i++)
    {
        printf("%.2f ",take[i]);
    }
    delete [] value;
    delete [] weight;
    delete [] target;
    delete [] take;
    return 0;
}
