#include<iostream>
#include<vector>
using namespace std;
int getj(int i,int elem)
{
    int num=0;
    while(num<i)
    {
        elem=elem/10;
        num++;
    }
    return elem%10;
}
int full(vector<int> *v,vector<int> &nodes)
{
    nodes.clear();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            nodes.push_back(v[i][j]);
        }
        v[i].clear();
    }
    return 0;
}
int main()
{
    vector<int> nodes;
    int elem,maxlength;
    cout<<"input the max length of the elem"<<endl;
    cin>>maxlength;
    cout<<"input the elem you want to sort"<<endl;
    while(cin>>elem)
    {
        nodes.push_back(elem);
    }
    vector<int> v[10];
    //开始进行基数排序。
    for(int i=0;i<maxlength;i++)
    {
        for(int j=0;j<nodes.size();j++)
           v[getj(i,nodes[j])].push_back(nodes[j]);
        nodes.clear();
        full(v,nodes);
    }
    cout<<"最终结果为："<<endl;
    for(int i=0;i<nodes.size();i++)
    {
        cout<<nodes[i]<<" ";
    }
    cout<<endl;
    return 0;
}
