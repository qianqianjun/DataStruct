/*#include<iostream>
using namespace std;
int div(int bnum,int maxnum)
{
    if(bnum<1||maxnum<1)
        return 0;
    if(bnum==1||maxnum==1)
        return 1;
    if(bnum<maxnum)
        return div(bnum,bnum);
    if(bnum==maxnum)
        return div(bnum,maxnum-1)+1;
    return div(bnum,maxnum-1)+div(bnum-maxnum,maxnum);
}
int main()
{
    int elem,num;
    cin>>elem;
    num=div(elem,elem);
    cout<<num<<endl;

    return 0;
}*/
//��ŵ�����⣻
/*
#include<iostream>
using namespace std;
void move(int n,char from,char to)
{
    cout<<"move "<<n<<" form "<<from<<"to "<<to<<endl;
    return;
}
int hanio(int n,char begins,char stop,char ends)
{
    if(n>0)
    {
        hanio(n-1,begins,ends,stop);//�Ƚ�ǰ��n-1�����ӷ�����ʱ���ϡ�
        move(n,begins,ends);  //�����һ�������ƶ���Ŀ�����ϡ�
        hanio(n-1,stop,begins,ends);  //����ʱ���ϵ�����ȫ���ƶ���Ŀ�����Ͻ�����ʼ������ʼ�ݹ���á�
    }
}
int main()
{
    char a='X';
    char b='Y';
    char c='Z';
    int num;
    cin>>num;
    hanio(num,a,b,c);
    return 0;
}
*/
//ȫ�������⣺
/*
#include<iostream>
#include<vector>
using namespace std;
template <class type>
void Swap(type &a,type &b)
{
    type c;
    c=a;
    a=b;
    b=c;
}
template <class type>
void perm(vector<type> &v,int k,int m)
{
    if(k==m)
    {
        for(int i=0;i<=m;i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
    else{
        for(int i=k;i<=m;i++)
        {
            Swap(v[k],v[i]);
            perm(v,k+1,m);
            Swap(v[k],v[i]);
        }
    }
}
int main()
{
    vector<int> v;
    int elem;
    while(cin>>elem)
    {
        v.push_back(elem);
    }
    perm(v,0,v.size()-1);
    return 0;
}*/


