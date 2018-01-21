#include<iostream>
#include<vector>
#include<malloc.h>
using namespace std;
int quicksort(int* &v,int low,int high)
{
    int i,j,temp;
    i=low,j=high;
    if(i<j)
    {
        temp=v[low];
        while(i!=j)
        {
            while(i<j&&v[j]>=temp) j--;
            v[i]=v[j];
            while(i<j&&v[i]<=temp) i++;
            v[j]=v[i];
        }
        v[i]=temp;
        quicksort(v,low,i-1);
        quicksort(v,i+1,high);
    }
}
int main()
{
    int *v;
    int maxnum,num;
    num=0,maxnum=5;
    v=(int*)malloc(sizeof(int)*5);
    int elem;
    while(cin>>elem)
    {
        if(num+1<maxnum)
        {
            v[num]=elem;
            num++;
        }
        else
        {
            v=(int*)realloc(v,(maxnum+10)*sizeof(int));
            v[num]=elem;
            maxnum+=10;
            num++;
        }
    }
    quicksort(v,0,num-1);
    for(int i=0;i<num;i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    return 0;
}
