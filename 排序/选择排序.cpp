#include<iostream>
#include<vector>
#include<malloc.h>
using namespace std;
int selectsort(int *&v,int length)
{
    int temp,k;
    for(int i=0;i<length-1;i++)
    {
        k=i;
        for(int j=i+1;j<length;j++)
        {
            if(v[j]<v[k])
                k=j;
        }
        temp=v[k];
        v[k]=v[i];
        v[i]=temp;
    }
    return 0;
}
int main()
{
    int *v;
    int num,maxnum,elem;
    num=0,maxnum=100;
    v=(int*)malloc(100*sizeof(int));
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
            num++;
        }
    }
    selectsort(v,num);
    for(int i=0;i<num;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
