//
// Created by serendipity on 2026/11/3.
//
/*链表
 * 顺序表本质还是数组,需要分配一块连续的内存空间
 * 链表不需要连续,只需要按顺序连接即可
 * 链表分类:带头节点,不带头节点
 *1.初始化链表
 *2.链表插入
 *3.链表删除
 *4.获取对应位置上的元素
 *5.查找元素位置
 *6.求链表长度(节点个数)
 */
#include<stdio.h>
#include <stdlib.h>
typedef int ElementType; //定义元素类型
struct ListNode
{
    ElementType element; //该节点的元素
    struct ListNode* next; //指向下一个节点的指针(存储下一个节点的地址值)
};

typedef struct ListNode* Node;
//1.链表初始化
int initLinkedList(Node node)
{
    node->next = NULL;
    return 1;
}

//2.链表插入,核心:前驱节点的下一个变成插入的节点
int insertLinkedList(Node prev, ElementType element, int index)
{
    if (index < 1) return 0; //有边界无法限制
    while (--index != 0)
    {
        prev = prev->next;
        if (prev == NULL) return 0; //越界非法位置
    }
    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->element = element;
    node->next = prev->next;
    prev->next = node;
    return 1;
}

//打印链表
void printLinkedList(Node prev)
{
    while (prev->next != NULL)
    {
        prev = prev->next;
        printf("→%d", prev->element);
    }
}

//3.节点的删除(操作某个节点,一定是先找前驱节点)
int deleteLinkedList(Node prev, int index)
{
    if (index < 1) return 0;
    while (--index != 0)
    {
        prev = prev->next;
        if (prev == NULL) return 0; //找到最后的节点了,该节点的指针指向NULL,不需要删除
    }
    Node temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
}

//4.获取对应位置的元素
ElementType getLinkedList(Node prev, int index)
{
    if (index < 1) return 0;
    while (index-- != 0) //这个地方要是index--,不能是--index,否则可能到底最后一个节点,导致元素为空
    {
        prev = prev->next;
    }
    return prev->element;
}

//5.查找对应元素的位置
int findLinkedList(Node prev, ElementType element)
{
    prev = prev->next;
    int i = 1;
    while (prev != NULL)
    {
        //先比较再移动节点
        if (prev->element == element) return i;
        i++;
        prev = prev->next;
    }
    return -1;
}

//6.链表长度(节点个数)
int sizeLinkedList(Node prev)
{
    int size = 0;
    prev = prev->next;
    while (prev != NULL)
    {
        size++;
        prev = prev->next;
    }
    return size;
}

int main()
{
    struct ListNode prev;
    //1.一定要初始化链表
    initLinkedList(&prev);
    //2.测试链表的插入
    for (int i = 1; i <= 3; i++)
    {
        insertLinkedList(&prev, i, i);
    }
    //3.测试删除节点
    deleteLinkedList(&prev, 1);
    printf("\n");
    printLinkedList(&prev);
    //4.获取节点位置的元素
    printf("\n");
    printf("%d\n", getLinkedList(&prev, 2));
    //5.测试寻找元素位置
    printf("%d\n", findLinkedList(&prev, 3));
    //6.返回链表长度
    printf("%d", sizeLinkedList(&prev));
    return 0;
}
//后续问题
//链表插入时间复杂度O(N),相比与顺序表,不需要搬动其他元素,效率比顺序表高
//删除同理也是O(N),获取元素O(N),不支持随机访问
//使用场景:插入,删除使用链表,获取使用顺序表