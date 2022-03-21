#include <stdio.h>
#include <stdlib.h>

#define NotFound 0
#define MAXSIZE 10

typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};


Position BinarySearch(List L, ElementType X ) {
    Position result;
    Position left = 1;
    Position right = L->Last;
    while (left <= right) {
        Position mid = (left + right) >> 1;
        if (L->Data[mid] > X) {
            right = mid - 1;
        } else if (L->Data[mid] < X){
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return NotFound;
}