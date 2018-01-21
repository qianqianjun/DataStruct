#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef char telemtype;
struct binode
{
    telemtype data;
    struct binode *leftchild;
	struct binode *rightchild;
};
int printelement(telemtype e)
{
    putchar(e);
    return 1;
}
int createbintree(struct binode **tree)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ')
    {
        (*tree) = NULL;
    }
    else
    {
        if (!((*tree) = (struct binode *)malloc(sizeof(struct binode))))
            exit(0);
        (*tree)->data = ch;
        createbintree(&((*tree)->leftchild));
        createbintree(&((*tree)->rightchild));
    }
    return 1;
}
int preshow(struct binode* T, int(*visit)(telemtype e))
{
    if (T)
    {
        if (visit(T->data))
            if (preshow(T->leftchild, visit))
                if (preshow(T->rightchild, visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}
int inshow(struct binode * T, int(*visit)(telemtype e))
{
    if (T)
    {
        if (inshow(T->leftchild, visit))
            if (visit(T->data))
                if (inshow(T->rightchild, visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}
 
int postshow(struct binode* T, int(*visit)(telemtype e))
{
    if (T)
    {
        if (postshow(T->leftchild, visit))
            if (postshow(T->rightchild, visit))
                if (visit(T->data))
                    return 1;
        return 0;
    }
    else
        return 1;
}
int main()
{
    struct binode *T;
	printf("请用先序方式输入树,空节点要用空格表示\n");
    createbintree(&T);
	printf("先序输出为:\n");
    preshow(T, printelement);printf("\n");
	printf("中序输出为:\n");
    inshow(T, printelement);printf("\n");
	printf("后序输出为:\n");
    postshow(T, printelement);printf("\n");
    return 0;
}

//以下是问题程序，未解决。
/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef char telemtype;
struct binode
{
    telemtype data;
    struct binode *leftchild;
	struct binode *rightchild;
};
int printelement(telemtype e)
{
    putchar(e);
    return 1;
}
int createbintree(struct binode *T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == ' ')
    {
        T = NULL;
    }
    else
    {
        if (!(T = (struct binode *)malloc(sizeof(struct binode))))
            exit(0);
        T->data = ch;
        createbintree(T->leftchild);
        createbintree(T->rightchild);
    }
    return 1;
}
int preshow(struct binode* T, int(*visit)(telemtype e))
{
    if (T)
    {
        if (visit(T->data))
            if (preshow(T->leftchild, visit))
                if (preshow(T->rightchild, visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}
int inshow(struct binode * T, int(*visit)(telemtype e))
{
    if (T)
    {
        if (inshow(T->leftchild, visit))
            if (visit(T->data))
                if (inshow(T->rightchild, visit))
                    return 1;
        return 0;
    }
    else
        return 1;
}
 
int postshow(struct binode* T, int(*visit)(telemtype e))
{
    if (T)
    {
        if (postshow(T->leftchild, visit))
            if (postshow(T->rightchild, visit))
                if (visit(T->data))
                    return 1;
        return 0;
    }
    else
        return 1;
}
int main()
{
	struct binode tree;
    struct binode *T;
	T=&tree;
    createbintree(T);
    preshow(T, printelement); putchar('\n');
    inshow(T, printelement); putchar('\n');
    postshow(T, printelement); putchar('\n');
    return 0;
}*/