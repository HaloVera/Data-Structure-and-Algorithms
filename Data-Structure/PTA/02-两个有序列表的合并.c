#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Merge( List L1, List L2 )
{
    List L, rear, temp;
    L = (List)malloc(sizeof(struct Node)); L->Next = NULL;
    rear = L;
    while ( L1->Next && L2->Next ) {
        if (L1->Next->Data < L2->Next->Data) {
            temp = L1->Next;
            L1->Next = temp->Next;
            rear->Next = temp;
            rear = temp;
        }
        else if (L1->Next->Data > L2->Next->Data) {
            temp = L2->Next;
            L2->Next = temp->Next;
            rear->Next = temp;
            rear = temp;
        }
        else {
            temp = L1->Next;
            L1->Next = temp->Next;
            rear->Next = temp;
            rear = temp;

            temp = L2->Next;
            L2->Next = temp->Next;
            rear->Next = temp;
            rear = temp;
        }
    }
    if (L1->Next) {
        rear->Next = L1->Next;
        L1->Next = NULL;
    }
    if (L2->Next) {
        rear->Next = L2->Next;
        L2->Next = NULL;
    }
    return L;
}