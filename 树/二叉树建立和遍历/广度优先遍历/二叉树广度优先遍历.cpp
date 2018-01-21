#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "link_queue.h"
typedef char telemtype;
int createbintree(bitree*tree)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ')
    {
        (*tree) = NULL;
    }
    else
    {
        if (!((*tree) = (bitree)malloc(sizeof(binode))))
            exit(0);
        (*tree)->data = ch;
        createbintree(&((*tree)->leftchild));
        createbintree(&((*tree)->rightchild));
    }
    return 1;
}
int main()
{
    bitree T;
    struct linkqueue *q;
    struct linkqueue que;
    q=&que;
    bitree m;
    initqueue(q);
	printf("��������ʽ������,�սڵ�Ҫ�ÿո��ʾ\n");
    createbintree(&T);
    addqueue(q,T);
    printf("������ȱ����Ľ��Ϊ\n");
    while(q->top!=q->bottom)
    {
        m=delqueue(q);
        printf("%c",m->data);
        if(m->leftchild!=NULL)
            addqueue(q,m->leftchild);
        if(m->rightchild!=NULL)
            addqueue(q,m->rightchild);
    }
    printf("\n");
    return 0;
}
