#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Loading
{
public:
    int n,*x,*bestx,*w,c,cw,bestw,r;
    void Backtrack(int i)
    {
        if(i>n)
        {
            if(cw>bestw)
            {
                for(int j=0;j<n;j++)
                    bestx[j]=x[j];
                bestw=cw;
            }
            return;
        }
        r-=w[i];
        if(cw+w[i]<=c)
        {
            x[i]=1;
            cw+=w[i];
            Backtrack(i+1);
            cw-=w[i];
        }
        if(cw+r>bestw)
        {
            x[i]=0;
            Backtrack(i+1);
        }
        r+=w[i];
    }
    //void initclass(int *w,int c,int n,int bestw)
};
int main()
{
	Loading L;
	//the number of the box;
	cout<<"input the number of the box!"<<endl;
	cin>>L.n;
	//the able of the first boat to take;
	cout<<"input the ability of the first boat to take goods"<<endl;
	cin>>L.c;
	//the weight of the goods;
	L.w=new int [L.n+1];
	L.r=0;
	cout<<"input the weight of the goods"<<endl;
	for(int i=0;i<L.n;i++)
	{
		cin>>L.w[i];
		L.r+=L.w[i];
	}
	L.x=new int [L.n+1];
	L.bestx=new int [L.n+1];
	L.bestw=0;
	L.cw=0;
	L.Backtrack(0);
	cout<<"the result is"<<endl;
	for(int i=0;i<L.n;i++)
	{
		cout<<L.bestx[i]<<" ";
	}
	cout<<endl;
	delete [] L.x;
	delete [] L.bestx;
	delete [] L.w;
    return 0;
}
