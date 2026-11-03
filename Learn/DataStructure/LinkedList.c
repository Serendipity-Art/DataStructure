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
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#include<stdio.h>
#include <stdlib.h>
typedef int ElementType; //定义元素类型
struct ListNode
{
    ElementType element;   //该节点的元素
    struct ListNode* next; //指向下一个节点的指针(存储下一个节点的地址值)
};

typedef struct ListNode* Node;
//1.链表初始化
void initLinkedList(Node node)
{
    node->next = NULL;
}

//2.链表插入,核心:前驱节点的下一个变成插入的节点
int insertLinkedList(Node head, ElementType element, int index)
{
    if (index < 1) return 0; //有边界无法限制
    while (--index != 0)
    {
        head = head->next;
        if (head == NULL) return 0; //越界非法位置
    }
    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

//打印链表
void printLinkedList(Node head)
{
    while (head->next != NULL)
    {   head=head->next;
        printf("%d ", head->element);
    }
}

int main()
{
    struct ListNode head;
    //2.测试链表的插入
    for (int i = 1; i <= 3; i++)
    {
        insertLinkedList(&head, i, i);
    }
    printLinkedList(&head);
    return 0;
}
