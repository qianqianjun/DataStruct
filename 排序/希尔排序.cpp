#include<iostream>
#include<vector>
using namespace std;
int shellinsertsort(vector<int> &v)
{
    int i,j,d,temp;
    d=v.size()/2;
    while(d>0)
    {
        for(i=d;i<v.size();i++)
        {
            j=i-d;
            temp=v[i];
            while(j>=0&&temp<v[j])
            {
                v[j+d]=v[j];
                j=j-d;
            }
            v[j+d]=temp;
        }
        d=d/2;
    }
    return 0;
}
int main()
{
    vector<int> v;
    int elem;
    cout<<"input the elem list you want to sort"<<endl;
    while(cin>>elem)
    {
        v.push_back(elem);
    }
    shellinsertsort(v);
    cout<<"The result of the sort is"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    return 0;
}

