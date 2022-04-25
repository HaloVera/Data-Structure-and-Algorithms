#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct SNode *Stack;
typedef struct SNode {
    int Data[MAX_SIZE];
    int Top;
}SNode;

int Push(Stack s, int element, int maxCapacity) {
    if (s->Top + 1 == maxCapacity) {
        return 0;
    } else {
        s->Data[++(s->Top)] = element;
        return 1;
    }
}

int Pop(Stack s) {
    return s->Data[s->Top--];
}

int Check(int list[], int maxCapacity, int N) {
    int num = 1, i = 0, t;
    Stack s = malloc(sizeof(struct SNode));
    s->Top = 0;
    s->Data[s->Top] = num;
    num = 2;
    while (i < N) {
        if (list[i] > s->Data[s->Top]) {
            t = Push(s, num, maxCapacity);
            if (t == 0) {
                return 0;
            } else {
                num++;
            }
        } else if (list[i] == s->Data[s->Top]) {
            t = Pop(s);
            i++;
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int maxCapacity, N, K;
    if (scanf("%d %d %d", &maxCapacity, &N, &K)) {
       int list[N];
        for (int i=0; i<K; i++) {
            for (int j=0; j<N; j++) {
                if (scanf("%d", &list[j])) {

                }
            }
            int flag = Check(list, maxCapacity, N);
            
            if (flag == 0) {
                printf("NO\n");
            } else if (flag == 1){
                printf("YES\n");
            }
        }
    }
    return 0;
}