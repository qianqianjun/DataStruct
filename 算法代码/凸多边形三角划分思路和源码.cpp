/*
    多边形最优三角剖分，其中权函数为三角形的周长。
    计科1601 高谦 2016014302 测试数据可能不全面，有问题欢迎联系我进行更正
    E-mail : 2016014302@mail.buct.edu.cn
*/
/*
    算法分析：
        1.最优子结构性质：最优多边形的权值由三部分组成，分别为最优三角形的权值和由于这个三角形
        而彼此分开的另外两个子多边形的最优权值。
        2.动态规划算法的具体实现。可以定义两个二维数组S[i][j]和t[i][j],分别表示与标号为i-1和标号
        为j的两个顶点所构成的最优三角形的另外一个顶点的标号;标号为i-1到j的多边形的最优权值。
        当多边形只有两个顶点的时候认为权值为0 。
        3.由于两个顶点的多边形权值为0，所以t[i][i]=0  (1<=i<=n) 当 j-1>=1 时，拥有标号为i-1到j的
        子多边形的权值t[i][j]由标号为i-1,k,j三点组成的三角的权值getweight(i-1,k,j)和t[i][k]+t[k+1][j]
        k的位置不确定，但已知 i<=k<=j-1 ,需要去比较寻找。
        所以t[i][j]=0  (i=j);
            t[i][j]=min{t[i][k]+t[k+1][j]+getwright(i-1,k,j)}  (i<=k<=j-1);

*/
#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int **a;//存放顶点的坐标，其中a[0]a[1]非别代表横坐标的纵坐标。
//下面是已知三个点的编号求出对应的权值的函数，本程序把三个顶点组成的三角形的周长作为权值。
float getweight(int v1,int v2,int v3)
{
    int A=(a[v1][0]-a[v2][0])*(a[v1][0]-a[v2][0])+(a[v1][1]-a[v2][1])*(a[v1][1]-a[v2][1]);
    int B=(a[v1][0]-a[v3][0])*(a[v1][0]-a[v3][0])+(a[v1][1]-a[v3][1])*(a[v1][1]-a[v3][1]);
    int C=(a[v3][0]-a[v2][0])*(a[v3][0]-a[v2][0])+(a[v3][1]-a[v2][1])*(a[v3][1]-a[v2][1]);
    return sqrt(A)+sqrt(B)+sqrt(C);
}
//下面是动态规划的主算法，用于求最优三角形。
int MinWeightTreeDiv(int n,float **t,int **s)
{
    for(int i=1;i<=n;i++)
        t[i][i]=0;
    for(int r=1;r<n;r++)  //表示计算多边形顶点的个数，这里从三个顶点开始，因为两个顶点权值认为是零。
    {
        for(int i=1;i<= n-r;i++)
        {
            int j=i+r;
            t[i][j]=t[i+1][j]+getweight(i-1,i,j);
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int u=t[i][k]+t[k+1][j]+getweight(i-1,k,j);  //将已经计算出的结果进行了利用，避免重复计算。
                if(u<t[i][j]) //发现当前最优并非最终的最优，则要更新最优值和最优三角形的第三个顶点的标号。
                {
                    t[i][j]=u;
                    s[i][j]=k;
                }
            }
        }
    }
}
//递归的输出最优三角剖分的结果。
void PrintResult(int i,int j,int **s)
{
    if(i==j)
        return;
    PrintResult(i,s[i][j],s);
    PrintResult(s[i][j]+1,j,s);
    cout<<"三角剖分顶点：V"<<i-1<<",V"<<j<<",V"<<s[i][j]<<endl;
}
int main()
{
    int num,**s;//顶点的个数和用于存储划分位置的二维数组。
    float **t;//多边形最优权值的二维数组。
    cout<<"请输入多边形点的个数"<<endl;
    cin>>num;
    //分配内存操作：
    //以下数组没有用到第零行和第零列。
    a=new int *[num+1];
    t=new float *[num+1];
    s=new int *[num+1];
    for(int i=0;i<num+1;i++)
    {
        a[i]=new int [2];
        t[i]=new float [num+1];
        s[i]=new int [num+1];
    }
    cout<<"请输入点的坐标位置"<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    //动态规划找到最优的多边形。
    MinWeightTreeDiv(num,t,s);
    PrintResult(1,num-1,s);//输出结果
    //释放内存的操作：
    for(int i=0;i<num+1;i++)
    {
        delete [] a[i];
        delete [] t[i];
        delete [] s[i];
    }
    delete [] s;
    delete [] t;
    delete [] a;
    return 0;
}
