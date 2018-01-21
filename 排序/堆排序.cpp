#include<iostream>
#include<malloc.h>
using namespace std;
class sqlist
{
    public:int num,maxnum,*v;
    public:
        sqlist()
        {
            this->num=0;
            this->maxnum=100;
            this->v=(int*)malloc(100*sizeof(int));
        }
        int pushback(int elem)
        {
            if(num+1<maxnum)
            {
                num++;
                v[num]=elem;
            }
            else
            {
                maxnum+=10;
                v=(int*)realloc(v,(maxnum)*sizeof(int));
                num++;
                v[num]=elem;
            }
            return 0;
        }
        int shift(int* &v,int low,int high)
        {
            int i=low,j=2*i;
            int temp = v[i];
            while(j<=high)
            {
                if(j<high&&v[j]<v[j+1]) j++; //ָ����ӽڵ�
                if(temp<v[j])
                {
                    v[i]=v[j];
                    i=j;
                    j=2*i;
                }
                else
                    break; //˫�״󣬲��ٽ��е�����
            }
            v[i]=temp;
        }
        void heapsort(int *&v,int n)
        {
            int i,temp;
            for(i=n/2;i>=1;i--)
            {
                this->shift(this->v,i,n);
            }
            for(i=n;i>=2;i--)
            {
                temp=v[1];  //��v[i]��v[1]���н�����
                v[1]=v[i];
                v[i]=temp;
                this->shift(this->v,1,i-1);  //ɸѡv[1]�ڵ㣬�õ�i-1���ڵ�Ķѡ�
            }
        }
        void print()
        {
            for(int i=1;i<=this->num;i++)
            {
                cout<<this->v[i]<<' ';
            }
            cout<<endl;
        }
};
int main()
{
    sqlist l;
    int elem;
    while(cin>>elem)
       l.pushback(elem);
    l.heapsort(l.v,l.num);
    l.print();
    return 0;
}
