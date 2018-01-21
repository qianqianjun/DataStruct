#include<iostream>
#include<list>
typedef char keytype;
typedef char sqlist;
using namespace std;
int seqsearch(list<sqlist> l,keytype k)
{
	list<sqlist>::iterator it;
	int i=0;
	for(it=l.begin();it!=l.end();it++)
    {
        if(*it==k)
        {
            return i+1;
        }
        i++;
    }
	return 0;
}
int input(list<sqlist> *l)
{
	char temp;
	cout<<"begin of the input"<<endl;
	cout<<"(tips:enter 'enter' and then enter 'ctrl+z' and 'enter' end the input)"<<endl;
	while(cin>>temp)
	{
		l->push_back(temp);
	}
	cout<<"end of the input"<<endl;
	return 0;
}
int main()
{
	int local;
	keytype key;
	list<sqlist> l;
	cout<<"please input the element you want to find!"<<endl;
	cin>>key;
	input(&l);
	local=seqsearch(l,key);
	if(local==0)
	{
		cout<<"cannot find it"<<endl;
	}
	else
		cout<<"the local of the  elem is"<<' '<<local<<endl;
	return 0;
}
