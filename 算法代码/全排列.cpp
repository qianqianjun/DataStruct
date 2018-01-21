#include<iostream>
#include<vector>
using namespace std;
template <typename Type>
void Swap(Type &a, Type &b)
{
    Type temp;
    temp = a ;
    a = b;
    b = temp;
}
template <typename Type>
void Perm(vector<Type> &list, int k, int m)
{
    //产生list[k:m]的所有排列
    if(k == m)
    {
        //只剩下一个元素
        for(int i = 0; i <= m; i++)
        {
            cout<<list[i];
        }
        cout<<"  ";
    } else {
        //还有多个元素待排列，递归产生排列
        for(int i = k; i <= m; i++)
        {
            Swap(list[k],list[i]);
            Perm(list,k+1,m);
            Swap(list[k],list[i]);
        }
    }
}
int main()
{
    int n;
    cout<<"请输入需排列数的个数:"<<endl;
    cin>>n;
    vector<int> a;
    cout<<"输入排列的数:"<<endl;
    int elem;
    for(int i = 0; i < n; i++)
    {
        cin>>elem;
        a.push_back(elem);
    }
    Perm(a,0,n-1);
    return 0;
}
