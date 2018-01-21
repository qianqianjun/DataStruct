#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
const int n=5;
const int m=2*n-1;
typedef struct
{
    float weight;
    int parent;
    int leftchild;
    int rightchild;
}htnode;
typedef htnode huffmantree[m];
void createhuffmantree(huffmantree T,float fr[])
{
    int i;
    float min1,min2;
    for(i=0;i<n;i++)
        T[i].weight=fr[i];
    for(i=0;i<m;i++)
    {
        T[i].parent=-1;
        T[i].leftchild=-1;
        T[i].rightchild=-1;
    }
    for(i=n;i<m;i++)
    {
        min1=min2=1;
        int pos1=0,pos2=0;
        for(int j=0;j<i;j++)
        {
            if(T[j].parent==-1)
            {
                if(T[j].weight<min1)
                {
                    pos2=pos1;
                    min2=min1;
                    pos1=j;
                    min1=T[j].weight;
                }
                else
                {
                    if(T[j].weight<min2)
                    {
                        pos2=j;
                        min2=T[j].weight;
                    }
                }
            }
            T[i].leftchild=pos1;
            T[i].rightchild=pos2;
            T[i].weight=T[pos1].weight+T[pos2].weight;
            T[pos1].parent=T[pos2].parent=i;
        }
    }
}
int main()
{
    float weight[n],b;
    huffmantree T;
    printf("请输入霍夫曼树的权重(频率，百分比)\n");
    float sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%f",&b);
        weight[i]=b;
        sum+=weight[i];
    }
    if(sum!=1.00)
    {
        cout<<"您输入的权重之和不是一，请检查是否输入有误"<<endl;
        exit(0);
    }
    createhuffmantree(T,weight);
    cout<<"生成的哈夫曼树为:"<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<T[i].weight<<' '<<T[i].parent<<' '<<T[i].leftchild<<' '<<T[i].rightchild<<' '<<endl;
    }
}
