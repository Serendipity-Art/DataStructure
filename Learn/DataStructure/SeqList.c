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
void insertSeqList(Arraylist list, ElementType item, int index)
{
    for (int i = list->size; i > index - 1; --i)
    {
        list->array[i] = list->array[i - 1];
    }
        list->array[index - 1] = item;
        list->size++;
}

//3.打印线性表元素
void printSeqList(Arraylist list)
{
    for (int i = 0; i < list->size; ++i)
    {
        printf("%d\n", list->array[i]);
    }
}

int main(void)
{
    struct SeqList list;
    if (initSeqList(&list) != 0)
    {
        //1.测试线性表插入功能
        insertSeqList(&list, 111, 1);
        printSeqList(&list);
        printf("\n");
        insertSeqList(&list, 222, 1);
        printSeqList(&list);
        printf("\n");
        insertSeqList(&list, 333, 2);
        printSeqList(&list);
        printf("\n");
    }
    else
    {
        printf("线性表初始化失败,无法启动程序");
    }
    return 0;
}
