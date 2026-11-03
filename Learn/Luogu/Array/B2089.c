//
// Created by serendipity on 2026/11/3.
//
// # B2089 数组逆序重存放
// ## 题目描述
// 将一个数组中的值按逆序重新存放。例如，原来的顺序为 $8,6,5,4,1$。要求改为 $1,4,5,6,8$。
// ## 输入格式
// 输入为两行：第一行数组中元素的个数 $n$（$1 \lt n \le 100$)，第二行是 $n$ 个整数，每两个整数之间用空格分隔。
// ## 输出格式
// 输出为一行：输出逆序后数组的整数，每两个整数之间用空格分隔。
// ## 输入输出样例 #1
// ### 输入 #1
// 5
// 8 6 5 4 1
// ### 输出 #1
// 1 4 5 6 8
#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);
    int nums[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < size - 1; i++)//外层定义需要交换的元素位置,从0开始,到size-1
    {
        for (int j = i + 1; j < size; j++)
        {   //内层选择交换两个元素
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}
