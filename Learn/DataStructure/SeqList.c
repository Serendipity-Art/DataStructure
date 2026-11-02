//
// Created by serendipity on 2026/11/2.
//
/*线性表(Sequential List)功能
 *1.初始化线性表
 *2.获取指定位置的元素
 *3.获取元素位置
 *4.输入元素
 *5.输出元素
 *6.插入元素
 *7.删除元素
 */
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType; //设置元素类型为整型
struct SeqList
{
    ElementType* array;
    int length;
    int size;
};

typedef struct SeqList* Arraylist;
//1.初始化线性表
int initSeqList(Arraylist list) //传入的参数一定要是结构体的指针
{
    list->length = 10; //等价(*list).length=10;一定要*list解引
    list->size = 0;
    //设置线性表的长度(不固定),需要使用动态内存,要申请堆内存,不要使用局部变量申请内存(局部变量在栈内存里面),离开作用域就被销毁了
    list->array = malloc(sizeof(ElementType) * list->length); //手动申请内存空间,申请的是堆内存
    if (list->array == NULL) return 0;
    return 1;
}

//2.插入元素(数组下标+1=位序),核心思想搬元素
int insertSeqList(Arraylist list, ElementType item, int index)
{
    //判断位序的合法性
    if (index < 1 || index > list->length + 1) return 0; //判断位序的合法性
    if (list->size == list->length)
    {
        ElementType* newArray = realloc(list->array, sizeof(ElementType) * list->length << 1); //扩展原来的内存为2倍
        if (newArray == NULL) return 0;
        list->array = newArray;
        list->length = list->length << 1;
    };
    for (int i = list->size; i > index - 1; --i)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = item;
    list->size++;
    return 1;
}

//打印线性表元素
void printSeqList(Arraylist list)
{
    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", list->array[i]);
    }
}

//3.删除元素,后一个元素覆盖前一个被删除的元素
int deleteSeqList(Arraylist list, int index) //index是位序,默认从1开始
{
    if (index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; ++i) list->array[i] = list->array[i + 1];
    list->size--;
}

//4.获取线性表长度
int sizeSeqList(Arraylist list)
{
    return list->size;
}

//5.获取指定位置元素
//第一种方式:返回的是地址值,需要解引才能获取值
int* getSeqList(Arraylist list, int index)
{
    if (index < 1 || index > list->size) return 0;
    return &list->array[index - 1];
}

int getSeqList2(Arraylist list, int index)
{
    return list->array[index - 1];
}

//6.寻找元素出现的位置,返回位序
int findSeqList(Arraylist list, ElementType item)
{
    for (int i = 0; i < list->size; ++i)
    {
        if (list->array[i] == item) return i + 1; //找到就返回
    }
    return -1; //没找到就返回-1
}

int main(void)
{
    struct SeqList list;
    if (initSeqList(&list) != 0)
    {
        //1.测试线性表插入功能
        for (int i = 1; i <= 20; ++i)
        {
            insertSeqList(&list, i * 10, i);
        }
        printSeqList(&list);
        printf("\n");
        printf("%d\n", list.size);
        //2.测试线性表删除功能
        for (int i = 1; i < (list.length / 2); ++i)
        {
            deleteSeqList(&list, 1);
        }
        printSeqList(&list);
        printf("\n");
        //3.测试获取元素的功能
        printf("%d\n", *getSeqList(&list, 1));
        printf("%d\n", getSeqList2(&list, 1));
        //4.测试寻找元素位置的功能
        printf("%d\n", findSeqList(&list, 100));
    }
    else
    {
        printf("线性表初始化失败,无法启动程序");
    }
    return 0;
}
//后续问题:顺序表插入,删除,获取元素的复杂度是多少?
//插入:O(N)元素需要移动,删除:O(N)元素需要移动,获取:O(1)可以通过数组下标访问元素
