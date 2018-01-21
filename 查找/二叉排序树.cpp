#include<iostream>
#include<vector>
using namespace std;
typedef int elemtype;
typedef int infotype;
typedef struct node
{
	elemtype elem;
	infotype info;
	struct node *left;
	struct node *right;
}BSTnode;
int insertBSTtree(BSTnode *&T,elemtype key)
{
	if (T==NULL)
	{
		T=new BSTnode;
		if(T==NULL)
			return 0;
		T->left=NULL;
		T->right=NULL;
		T->elem=key;
		return 1;
	}
	if(T->elem==key)
		return 0;
	if(key<T->elem)
		return insertBSTtree(T->left,key);
	else
		return insertBSTtree(T->right,key);
	return 0;
}
BSTnode *searchBST(BSTnode* T,elemtype key)
{
	if (T==NULL||T->elem==key)
		return T;
	if(key<T->elem)
		return searchBST(T->left,key);
	else
		return searchBST(T->right,key);
}
BSTnode * createBSTtree(BSTnode *T,vector<elemtype> elemlist)
{
    int i=0;
    while(i<elemlist.size())
    {
        insertBSTtree(T,elemlist[i]);
        i++;
    }
    return T;
}
void Delete1(BSTnode *T,BSTnode *&p)
{
    BSTnode *q;
    if(p->right!=NULL)
        Delete1(T,p->right);
    else
    {
        T->elem=p->elem;
        T->info=p->info;
        q=p;
        p=p->left;
        delete(q);
    }
}
int Delete(BSTnode *&T)
{
    BSTnode *p;
    if(T->left==NULL)
    {
        p=T;
        T=T->right;
        delete(p);
    }
    else if(T->right==NULL)
    {
        p=T;
        T=T->left;
        delete(p);
    }
    else
        Delete1(T,T->left);
    return 0;
}
int DeleteBST(BSTnode *&T,elemtype key)
{
    if(T==NULL)
        return 0;//空树会删除失败
    if(key<T->elem)
        return DeleteBST(T->left,key);
    if(key>T->elem)
        return DeleteBST(T->right,key);
    else
    {
        Delete(T);
        return 1;
    }
}
int vec_append(vector<elemtype> *elemlist,elemtype data)
{
    elemlist->push_back(data);
    return 0;
}
int main()
{
	BSTnode *T;
	elemtype searchelem,data;
	T=NULL;
	vector<elemtype> elemlist;
	cout<<"input the element you want to find"<<endl;
	cin>>searchelem;
	cout<<"input the list where you search the element"<<endl;
	elemlist.push_back(25);
	elemlist.push_back(18);
	elemlist.push_back(46);
	elemlist.push_back(2);
	elemlist.push_back(53);
	elemlist.push_back(39);
	elemlist.push_back(32);
	elemlist.push_back(4);
	elemlist.push_back(74);
	elemlist.push_back(67);
	elemlist.push_back(60);
	elemlist.push_back(11);
	while(cin>>data)
    {
        vec_append(&elemlist,data);
    }
	T=createBSTtree(T,elemlist);
	BSTnode *res=searchBST(T,searchelem);
	if(res==NULL)
        cout<<"cannot find the elem"<<endl;
    else
	    cout<<res->elem<<endl;
	return 0;
}






