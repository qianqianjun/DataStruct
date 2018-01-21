#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
class circle
{
public:
    int n;
    float min,*x,*r;
    void Backtrack(int t);
    void Compute(void);
    float Center(int t);
};
float circle::Center(int t)
{
	float temp=0;
	for(int j=1;j<t;j++)
	{
		float valuex=x[j]+2*sqrt(r[t]*r[j]);
		if(valuex>temp)
			temp=valuex;
	}
	return temp;
}
void circle::Compute(void)
{
	float low=0,high=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]-r[i]<low)
			low=x[i]-r[i];
		if(x[i]+r[i]>high)
			high=x[i]+r[i];
	}
	if(high-low<min)
		min=high-low;
}
void circle::Backtrack(int t)
{
	if(t>n)
		Compute();
	else
	{
		for(int j=t;j<=n;j++)
		{
			swap(r[t],r[j]);
			float centerx=Center(t);
			if(centerx+r[1]+r[t]<min)
			{
				x[t]=centerx;
				Backtrack(t+1);
			}
			swap(r[t],r[j]);
		}
	}
}
int main()
{
    circle C;
	cout<<"input the num of the circle"<<endl;
	cin>>C.n;
	C.r=new float [C.n+1];
	for(int i=1;i<=C.n;i++)
		cin>>C.r[i];
	C.min=100000;
    C.x=new float [C.n+1];
    C.Backtrack(1);
    cout<<"the min of the length is "<<C.min<<endl;
    cout<<"the x-local of the circle is"<<endl;
    for(int i=1;i<=C.n;i++)
        cout<<C.x[i]<<" ";
    cout<<endl;
    delete [] C.x;
    delete [] C.r;
    return 0;
}
