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
    //����list[k:m]����������
    if(k == m)
    {
        //ֻʣ��һ��Ԫ��
        for(int i = 0; i <= m; i++)
        {
            cout<<list[i];
        }
        cout<<"  ";
    } else {
        //���ж��Ԫ�ش����У��ݹ��������
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
    cout<<"���������������ĸ���:"<<endl;
    cin>>n;
    vector<int> a;
    cout<<"�������е���:"<<endl;
    int elem;
    for(int i = 0; i < n; i++)
    {
        cin>>elem;
        a.push_back(elem);
    }
    Perm(a,0,n-1);
    return 0;
}
