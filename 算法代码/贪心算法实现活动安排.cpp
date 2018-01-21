#include<iostream>
using namespace std;
template <class type>
void GreedySelector(int n,type *&s,type *&f,bool *&A)
{
    A[1]=true;
    int j=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]>=f[j])
        {
            j=i;
            A[i]=true;
        }
        else
            A[i]=false;
    }
}
template <class type>
int QuickSort(type *&s,type *&f,int low ,int high)
{
    int i,j;
    type temp1,temp2;
    i=low;
    j=high;
    if(i<j)
    {
        temp1=f[low];
        temp2=s[low];
        while(i!=j)
        {
            while(i<j&&f[j]>=temp1) j--;
            f[i]=f[j];
            s[i]=s[j];
            while(i<j&&f[i]<=temp1) i++;
            f[j]=f[i];
            s[j]=s[i];
        }
        f[i]=temp1;
        s[i]=temp2;
        QuickSort(s,f,low,i-1);
        QuickSort(s,f,i+1,high);
    }
}
int main()
{
    int *s,*f,num;
    bool *A;
    cout<<"输入活动的个数"<<endl;
    cin>>num;
    s=new int [num+1];
    f=new int [num+1];
    A=new bool [num+1];
    cout<<"输入开始和结束时间"<<endl;
    for(int i=1;i<=num;i++)
    {
        cin>>s[i]>>f[i];
    }
    QuickSort(s,f,1,num);
    cout<<"活动重排"<<endl;
    for(int i=1;i<=num;i++)
    {
        cout<<s[i]<<" "<<f[i]<<endl;
    }
    GreedySelector(num,s,f,A);
    for(int i=1;i<=num;i++)
    {
        if(A[i])
            cout<<"活动"<<":"<<i<<endl;
    }
    delete [] s;
    delete [] f;
    return 0;
}
