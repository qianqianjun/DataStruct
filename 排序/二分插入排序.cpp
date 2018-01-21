#include<iostream>
#include<vector>
using namespace std;
int bininsertsort(vector<int> &v)
{
    int i,j,low,high,mid,temp;
    for(i=1;i<v.size();i++)
    {
        if(v[i]<v[i-1])//如果顺序出现异常情况:
        {
            //二分查找应该插入的位置。
            low=0;
            high=i-1;
            temp=v[i];
            while(low<=high)
            {
                mid=(low+high)/2;
                if(v[mid]>temp)
                    high=mid-1;
                else
                    low=mid+1;
            }
            //元素进行后移操作。
            for(j=i-1;j>=high+1;j--)
            {
                v[j+1]=v[j];
            }
            v[high+1]=temp;
        }
    }
    return 0;
}
int main()
{
    vector<int> v;
    int elem;
    cout<<"input the elem you want to sort"<<endl;
    while(cin>>elem)
    {
        v.push_back(elem);
    }
    bininsertsort(v);
    cout<<"The result of the sort is"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    return 0;
}
