//
// Created by serendipity on 2026/11/3.
//
// # B2105 矩阵乘法
// ## 题目描述
// 计算两个矩阵的乘法。$n \times m$ 阶的矩阵 $A$ 乘以 $m \times k$ 阶的矩阵 $B$ 得到的矩阵 $C$ 是 $n \times k$ 阶的，且 $C_{i,j}=A_{i,0} \times B_{0,j}+A_{i,1} \times B_{1,j}+\cdots+A_{i,m-1} \times B_{m-1,j}$（$C_{i,j}$ 表示 $C$ 矩阵中第 $i$ 行第 $j$ 列元素）。
// ## 输入格式
// 第一行为 $n,m,k$，表示 $A$ 矩阵是 $n$ 行 $m$ 列，$B$ 矩阵是 $m$ 行 $k$ 列，$n,m,k$ 均小于等于 $100$。
// 然后先后输入 $A$ 和 $B$ 两个矩阵，$A$ 矩阵 $n$ 行 $m$ 列，$B$ 矩阵 $m$ 行 $k$ 列，矩阵中每个元素的绝对值不会大于 $1000$。
// ## 输出格式
// 输出矩阵 $C$，一共 $n$ 行，每行 $k$ 个整数，整数之间以一个空格分开。
// ## 输入输出样例 #1
// ### 输入 #1
// 3 2 3
// 1 1
// 1 1
// 1 1
// 1 1 1
// 1 1 1
// ### 输出 #1
// 2 2 2
// 2 2 2
// 2 2 2
#include <stdio.h>

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int matrixA[n][m], matrixB[m][k],matrixC[n][k];
    printf("%d %d %d", m, n, k);
    //输入矩阵A
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &matrixA[i][j]);
        }
        printf("\n");
    }
    //输入矩阵B
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            scanf("%d", &matrixB[i][j]);
        }
        printf("\n");
    }
    //计算矩阵A和矩阵B的乘积
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {   matrixC[i][j] = 0;
            for (int p = 0; p < m; ++p)//设置累加维度
            {
                matrixC[i][j] += matrixA[i][p] * matrixB[p][j];
            }
        }
    }
    //打印矩阵A
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }
    //打印矩阵B
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }
    //打印矩阵C
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    return 0;
}
