template<typename T>
class StrassenClass
{
    public:
          void FillMatrix( T** MatrixA, T** MatrixB, int length);  //A,B矩阵赋值
          void ADD(T** MatrixA, T** MatrixB, T** MatrixResult, int Size );  //矩阵相加
          void SUB(T** MatrixA, T** MatrixB, T** MatrixResult, int Size );  //矩阵相减
          void MUL( T** MatrixA, T** MatrixB, T** MatrixResult, int Size );  //矩阵相乘
          void Strassen(int N, T **MatrixA, T **MatrixB, T **MatrixC);//Strassen算法实现
          void PrintMatrix(T **MatrixA,int Size);//打印矩阵
};
template<typename T>
void StrassenClass<T>::ADD(T** MatrixA, T** MatrixB, T** MatrixResult, int Size )
{
    for ( int i = 0; i < Size; i++)
    {
        for ( int j = 0; j < Size; j++)
        {
            MatrixResult[i][j] =  MatrixA[i][j] + MatrixB[i][j];
        }
    }
}
template<typename T>
void StrassenClass<T>::SUB(T** MatrixA, T** MatrixB, T** MatrixResult, int Size )
{
    for ( int i = 0; i < Size; i++)
    {
        for ( int j = 0; j < Size; j++)
        {
            MatrixResult[i][j] =  MatrixA[i][j] - MatrixB[i][j];
        }
    }
}
template<typename T>
void StrassenClass<T>::MUL( T** MatrixA, T** MatrixB, T** MatrixResult, int Size )
{
    for (int i=0;i<Size ;i++)
    {
        for (int j=0;j<Size ;j++)
        {
            MatrixResult[i][j]=0;
            for (int k=0;k<Size ;k++)
            {
                MatrixResult[i][j]+=MatrixA[i][k]*MatrixB[k][j];
            }
        }
    }
}
template<typename T>
void StrassenClass<T>::Strassen(int N, T **MatrixA, T **MatrixB, T **MatrixC)
{
    int HalfSize = N/2;
    int newSize = N/2;
    if (N<=2) //可以直接计算出结果的，不再递归。
    {
        MUL(MatrixA,MatrixB,MatrixC,N);
    }
    else
    {
        T** A11;
        T** A12;
        T** A21;
        T** A22;

        T** B11;
        T** B12;
        T** B21;
        T** B22;

        T** C11;
        T** C12;
        T** C21;
        T** C22;

        T** M1;
        T** M2;
        T** M3;
        T** M4;
        T** M5;
        T** M6;
        T** M7;
        T** AResult;
        T** BResult;

        A11 = new T *[newSize];
        A12 = new T *[newSize];
        A21 = new T *[newSize];
        A22 = new T *[newSize];

        B11 = new T *[newSize];
        B12 = new T *[newSize];
        B21 = new T *[newSize];
        B22 = new T *[newSize];

        C11 = new T *[newSize];
        C12 = new T *[newSize];
        C21 = new T *[newSize];
        C22 = new T *[newSize];

        M1 = new T *[newSize];
        M2 = new T *[newSize];
        M3 = new T *[newSize];
        M4 = new T *[newSize];
        M5 = new T *[newSize];
        M6 = new T *[newSize];
        M7 = new T *[newSize];

        AResult = new T *[newSize];
        BResult = new T *[newSize];

        //int newSize = newSize;
        for ( int i = 0; i < newSize; i++)
        {
            A11[i] = new T[newSize];
            A12[i] = new T[newSize];
            A21[i] = new T[newSize];
            A22[i] = new T[newSize];

            B11[i] = new T[newSize];
            B12[i] = new T[newSize];
            B21[i] = new T[newSize];
            B22[i] = new T[newSize];

            C11[i] = new T[newSize];
            C12[i] = new T[newSize];
            C21[i] = new T[newSize];
            C22[i] = new T[newSize];

            M1[i] = new T[newSize];
            M2[i] = new T[newSize];
            M3[i] = new T[newSize];
            M4[i] = new T[newSize];
            M5[i] = new T[newSize];
            M6[i] = new T[newSize];
            M7[i] = new T[newSize];

            AResult[i] = new T[newSize];
            BResult[i] = new T[newSize];
        }
        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                A11[i][j] = MatrixA[i][j];
                A12[i][j] = MatrixA[i][j + newSize];
                A21[i][j] = MatrixA[i + newSize][j];
                A22[i][j] = MatrixA[i + newSize][j + newSize];

                B11[i][j] = MatrixB[i][j];
                B12[i][j] = MatrixB[i][j + newSize];
                B21[i][j] = MatrixB[i + newSize][j];
                B22[i][j] = MatrixB[i + newSize][j + newSize];

            }
        }
        //M1[][]
        ADD( A11,A22,AResult, HalfSize);
        ADD( B11,B22,BResult, HalfSize);                //p5=(a+d)*(e+h)
        Strassen( HalfSize, AResult, BResult, M1 );


        //M2[][]
        ADD( A21,A22,AResult, HalfSize);              //M2=(A21+A22)B11   p3=(c+d)*e
        Strassen(HalfSize, AResult, B11, M2);

        //M3[][]
        SUB( B12,B22,BResult, HalfSize);              //M3=A11(B12-B22)   p1=a*(f-h)
        Strassen(HalfSize, A11, BResult, M3);

        //M4[][]
        SUB( B21, B11, BResult, HalfSize);           //M4=A22(B21-B11)    p4=d*(g-e)
        Strassen(HalfSize, A22, BResult, M4);

        //M5[][]
        ADD( A11, A12, AResult, HalfSize);           //M5=(A11+A12)B22   p2=(a+b)*h
        Strassen(HalfSize, AResult, B22, M5);


        //M6[][]
        SUB( A21, A11, AResult, HalfSize);
        ADD( B11, B12, BResult, HalfSize);             //M6=(A21-A11)(B11+B12)   p7=(c-a)(e+f)
        Strassen( HalfSize, AResult, BResult, M6);

        //M7[][]
        SUB(A12, A22, AResult, HalfSize);
        ADD(B21, B22, BResult, HalfSize);             //M7=(A12-A22)(B21+B22)    p6=(b-d)*(g+h)
        Strassen(HalfSize, AResult, BResult, M7);

        //计算C矩阵:
        //C11 = M1 + M4 - M5 + M7;
        ADD( M1, M4, AResult, HalfSize);
        SUB( M7, M5, BResult, HalfSize);
        ADD( AResult, BResult, C11, HalfSize);
        //C12 = M3 + M5;
        ADD( M3, M5, C12, HalfSize);
        //C21 = M2 + M4;
        ADD( M2, M4, C21, HalfSize);
        //C22 = M1 + M3 - M2 + M6;
        ADD( M1, M3, AResult, HalfSize);
        SUB( M6, M2, BResult, HalfSize);
        ADD( AResult, BResult, C22, HalfSize);
        //结果合并;
        for (int i = 0; i < newSize ; i++)
        {
            for (int j = 0 ; j <newSize; j++)
            {
                MatrixC[i][j] = C11[i][j];
                MatrixC[i][j + newSize] = C12[i][j];
                MatrixC[i + newSize][j] = C21[i][j];
                MatrixC[i + newSize][j + newSize] = C22[i][j];
            }
        }
        // 释放矩阵内存空间
        for (int i = 0; i < newSize; i++)
        {
            delete[] A11[i];delete[] A12[i];delete[] A21[i];
            delete[] A22[i];

            delete[] B11[i];delete[] B12[i];delete[] B21[i];
            delete[] B22[i];
            delete[] C11[i];delete[] C12[i];delete[] C21[i];
            delete[] C22[i];
            delete[] M1[i];delete[] M2[i];delete[] M3[i];delete[] M4[i];
            delete[] M5[i];delete[] M6[i];delete[] M7[i];
            delete[] AResult[i];delete[] BResult[i] ;
        }
        delete[] A11;delete[] A12;delete[] A21;delete[] A22;
        delete[] B11;delete[] B12;delete[] B21;delete[] B22;
        delete[] C11;delete[] C12;delete[] C21;delete[] C22;
        delete[] M1;delete[] M2;delete[] M3;delete[] M4;delete[] M5;
        delete[] M6;delete[] M7;delete[] AResult;delete[] BResult ;
    }
}
template<typename T>
void StrassenClass<T>::FillMatrix(T** MatrixA,T** MatrixB,int length)
{
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            MatrixA[i][j]=rand()%5;
            MatrixB[i][j]=rand()%5;
        }
    }
}
template<typename T>
void StrassenClass<T>::PrintMatrix(T **MatrixA,int Size)
{
    for(int i= 0;i<Size;i++)
    {
        for(int j= 0;j<Size;j++)
        {
            printf("%3d ",MatrixA[i][j]);
        }
        cout<<endl;
    }
}
