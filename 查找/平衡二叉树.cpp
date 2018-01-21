#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef struct BSTnode
{
   int data;
   int bf;
   struct BSTnode *lchild,*rchild;
}BSTnode,* BSTree;
const int LH=1;
const int EH=0;
const int RH=-1;
const int max_num=100;
class BalanceTree
{
    public : BSTree root;
    public : bool taller;
    public : vector<int> Treenodelist;
    int initTreenodelist()
    {
        int elem;
        while(cin>>elem)
        {
            this->Treenodelist.push_back(elem);
        }
    }
    int createTree(void)
    {
        this->root=NULL;
        int elem;
        for(int i=0;i<this->Treenodelist.size();i++)
        {
            elem=this->Treenodelist[i];
            this->insertBSTtree(this->root,elem,this->taller);
        }
        return 0;
    }
    //平衡二叉树的插入操作，当成功插入的时候返回1，否则返回0;
    int insertBSTtree(BSTnode*&T,int elem,bool &taller)
    {
        //如果是树为空树：
        if(!T)
        {
            T=new BSTnode;
            T->data=elem;
            T->rchild=NULL;
            T->lchild=NULL;
            T->bf=EH;
            taller=true;
        }
        //如果树不为空:
        else
        {
            //如果树中已经存在相同的元素，则不插入。
            if(elem==T->data)
            {
                taller =false;
                return 0;
            }
            //如果插入的值小于树的节点值，则在左子树中插入。
            if(T->data>elem)
            {
                if(!this->insertBSTtree(T->lchild,elem,taller))
                    return 0;//没有插入;
                if(taller)
                {
                    switch(T->bf)
                    {
                        case LH:{this->Leftbalance(T);taller=false;break;}
                        case EH:{T->bf=LH,taller=true;break;}
                        case RH:{T->bf=EH,taller=false;break;}
                    }
                }
            }
            //如果插入的值大于树中的节点，应该在右子树中进行搜索。
            else
            {
                if(!this->insertBSTtree(T->rchild,elem,taller))
                    return 0;  //没有成功插入节点；
                if(taller)
                {
                    switch(T->bf)
                    {
                        case LH:{T->bf=EH;taller=false;break;}
                        case EH:{T->bf=RH;taller=true;break;}
                        case RH:{this->Rightbalance(T);taller=false;break;}
                    }
                }
            }
        }
        return 1;
    }//end of insertBSTree;
    void Rightrotate(BSTree &T)
    {
        BSTnode *lc=T->lchild;
        T->lchild=lc->rchild;
        lc->rchild=T;
        T=lc;
    }
    void Leftrotate(BSTnode *&T)
    {
        BSTnode *rc=T->rchild;
        T->rchild=rc->lchild;
        rc->lchild=T;
        T=rc;
    }
    void Leftbalance(BSTree &T)
    {
        BSTree lc=T->lchild;
        switch(lc->bf)
        {
            case LH:{T->bf=lc->bf=EH;this->Rightrotate(T);break;}
            case RH:{BSTree rd=lc->rchild;
              switch(rd->bf)
              {
                  case LH:T->bf=RH;lc->bf=EH;break;
                  case EH:T->bf=lc->bf=EH;break;
                  case RH:T->bf=EH;lc->bf=LH;break;
              }
              rd->bf=EH;
              Leftrotate(T->lchild);
              Rightrotate(T);
            }
        }
    }//end of Leftbalance;
    void Rightbalance(BSTnode*&T)
    {
        BSTree rc=T->rchild;
        switch(rc->bf)
        {
            case LH:{
                BSTree ld=rc->lchild;
                switch(ld->bf)
                {
                    case LH:T->bf=EH;rc->bf=RH;break;
                    case EH:T->bf=rc->bf=EH;break;
                    case RH:T->bf=LH;rc->bf=EH;break;
                }
                ld->bf=EH;
                Rightrotate(T->rchild);
                Leftrotate(T);
            }
            case RH:{
                T->bf=rc->bf=EH;this->Leftrotate(T);break;
            }
        }
    }//end of Rightbalance
    int inshow(BSTree T)
    {
        if(T)
        {
            if(this->inshow(T->lchild))
                cout<<T->data<<' ';
                if(this->inshow(T->rchild));
                    return 1;
            return 0;
        }
        else
            return 1;
    }
};
//end of class;
int main()
{
    BalanceTree Tree;
    Tree.initTreenodelist();
    Tree.createTree();
    Tree.inshow(Tree.root);
    return 0;
}
