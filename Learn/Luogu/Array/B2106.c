//
// Created by serendipity on 2026/11/3.
//
// # B2106 矩阵转置
// ## 题目描述
// 输入一个 $n$ 行 $m$ 列的矩阵 $A$，输出它的转置 $A^T$。
// $A^T$ 可以通过将 $A$ 的行与列互换得到，即
// $$A^T_{i,j}=A_{j,i}$$
// ## 输入格式
// 第一行包含两个整数 $n$ 和 $m$，表示矩阵 $A$ 的行数和列数。$1 \le n \le 100$，$1 \le m \le 100$。
// 接下来 $n$ 行，每行 $m$ 个整数，表示矩阵 $A$ 的元素。相邻两个整数之间用单个空格隔开，每个元素均在 $1 \sim 1000$ 之间。
// ## 输出格式
// $m$ 行，每行 $n$ 个整数，为矩阵 $A$ 的转置。相邻两个整数之间用单个空格隔开。
// ## 输入输出样例 #1
// ### 输入 #1
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// ### 输出 #1
// 1 4 7
// 2 5 8
// 3 6 9
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    int newmatrix[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    //矩阵转置
    for (int i = 0; i < m; i++) //行
    {
        for (int j = 0; j < n; j++) //列
        {
            newmatrix[i][j] = matrix[j][i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", newmatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
