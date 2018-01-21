#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "link_queue.h"
typedef char telemtype;
int printelement(telemtype e)
{
    putchar(e);
    return 1;
}
int createbintree(binode **tree)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ')
    {
        (*tree) = NULL;
    }
    else
    {
        if (!((*tree) = (binode *)malloc(sizeof(binode))))
            exit(0);
        (*tree)->data = ch;
        createbintree(&((*tree)->leftchild));
        createbintree(&((*tree)->nextsibing));
    }
    return 1;
}

int main()
{
    struct linkqueue*q;
    struct linkqueue que;
    q=&que;
    initqueue(q);
    binode *T;
    bitree t;
	printf("请用左孩子右兄弟的方式输入一棵二叉树\n");
    createbintree(&T);
    addqueue(q,T);
    while(q->top!=q->bottom)
    {
        t=delqueue(q);
        printf("%c ",t->data);
        if(t->leftchild!=NULL)
        {
            addqueue(q,t->leftchild);
            if(t->leftchild->nextsibing!=NULL)
            {
                bitree target=t->leftchild;
                while(target->nextsibing!=NULL)
                {
                    addqueue(q,target->nextsibing);
                    target=target->nextsibing;
                }
            }
        }
    }
    return 0;
}
