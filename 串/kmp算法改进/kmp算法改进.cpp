#include <stdio.h>
#include <string.h>
int next[100];
int nextval[100];
int index_kmp(char *S, char *T, int pos)
{
    int i;
    int j;
    i = pos;
    j = 0;
    while (i < strlen(S) && j < strlen(T))
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (strlen(T)==j)
        return i-strlen(T)+1;
    else
        return -1;
}
void get_next(char *T, int *next)
{
    int k = -1;
    int j = 0;
    next[j] = k;
    while (j < strlen(T))
    {
        if (k==-1||T[j]==T[k])
        {
            ++k;
            ++j;
            if(T[j]!=T[k]) next[j]=k;
            else
            next[j] = next[k];
        }
        else
        {
            k = next[k];
        }
    }
}
/*int index_KMP(char *S, char *T, int pos)
{
    int i;
    int j;
    i = pos;
    j = 0;
    while ( (i < strlen(S)) && (j < strlen(T)) )
    {
        if ( (j == -1)  || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (strlen(T) == j)
        return i - strlen(T);
    else
       return -1;
}  */
void print_next(int next[], int n)
{
   int i;
   for (i = 0; i < n; i++)
      printf("next[%d] = %d\n", i, next[i]);
}
int main(void)
{
	char muo[100];
	char mainstr[300];
	printf("请输入主串!\n");
	gets(mainstr);
    char *s =mainstr;
	printf("请输入模式串\n");
	gets(muo);
    char *t =muo;
    int pos = 0;
    int index;
    index = index_kmp(s, t, pos);
	if(index==-1)
		printf("不匹配\n");
	else
		printf("模式串的匹配位置为(-1表示不匹配)：%d\n", index);
    printf("模式串的next\n");
    get_next(t, next);
    print_next(next, strlen(t));
}
