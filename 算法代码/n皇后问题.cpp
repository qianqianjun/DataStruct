#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class queen
{
public:
	int n,*x,sum;
	bool place(int k)
	{
		for(int j=1;j<k;j++)
		{
			if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
				return false;
		}
		return true;
	}
	void Backtrack(int t)
	{
		if(t>n)
			sum++;
		else
		{
			for(int i=1;i<=n;i++)
			{
				x[t]=i;
				if(place(t))
					Backtrack(t+1);
			}
		}
	}
};
int main()
{
	queen q;
	while(cin>>q.n&&q.n)
    {
        q.sum=0;
        q.x=new int [q.n+1];
        for(int i=0;i<=q.n;i++)
            q.x[i]=0;
        q.Backtrack(1);
        cout<<q.sum<<endl;
        delete [] q.x;
    }
	return 0;
}
