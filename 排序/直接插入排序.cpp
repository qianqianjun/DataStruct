#include<iostream>
#include<vector>
using namespace std;
int insertsort(vector<int> &v)
{
    int i,j,temp;
    for(i=1;i<v.size();i++)
    {
        if(v[i]<v[i-1])
        {
            temp=v[i];
            j=i-1;
            do
            {
                v[j+1]=v[j];
                j--;
            }while(j>=0&&v[j]>temp);
            v[j+1]=temp;
        }
    }
    return 0;
}
int main()
{
    vector<int> v;
    //初始化要排序的数据。
    int elem;
    while(cin>>elem)
    {
        v.push_back(elem);
    }
    //开始排序：
    insertsort(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    return 0;
}
