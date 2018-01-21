#include<iostream>
#include<malloc.h>
#include<algorithm>
typedef int elemtype;
typedef int keytype;
using namespace std;
#define initsize 100
#define addsize 10
typedef struct
{
    elemtype *e;
    int listsize;
    int maxsize;
}sqlist;
int initlist(sqlist *l)
{
    l->e=(elemtype*)malloc(sizeof(elemtype)*initsize);
    l->listsize=0;
    l->maxsize=initsize;
    return 0;
}
int input(sqlist *l)
{
    elemtype temp;
    while(cin>>temp)
    {
        if(l->listsize<=l->maxsize)
        {
            l->e[l->listsize]=temp;
            l->listsize++;
        }
        else
        {
            l->e=(elemtype*)realloc(l->e,(l->listsize+addsize)*sizeof(elemtype));
            l->maxsize+=10;
            l->e[l->listsize]=temp;
            l->listsize++;
        }
    }
    return 0;
}
int twofind(sqlist l,keytype key)
{
    int top=0,bottom=l.listsize;
    int mid=bottom/2;
    while(top!=mid&&l.e[mid]!=key)
    {
        if(l.e[mid]>key)
        {
            bottom=mid;
            mid=(top+bottom)/2;
        }
        else
        {
            top=mid;
            mid=(top+bottom)/2;
        }
    }
    if(l.e[mid]==key)
        return mid+1;
    return 0;
}
int main()
{
    sqlist l;
    initlist(&l);
    cout<<"input the element you want to find"<<endl;
    elemtype key;
    cin>>key;
    cout<<"input the string from low to high"<<endl;
    input(&l);
    int local=twofind(l,key);
    if(local==0)
        cout<<"cannot find in the string"<<endl;
    else
        cout<<"the local of the target is "<<local<<endl;
    return 0;
}
