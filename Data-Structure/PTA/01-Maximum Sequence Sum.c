#include<stdio.h>
#include<stdlib.h>

int maxSeqSum (int A[], int N) {
    int thisSum, result[3];
    int start, end;
    thisSum = 0;
    result[0] = 0;
    result[1] = A[0];
    result[2] = A[N - 1];
    start = end = 0;
    for (int i = 0; i < N; i++) {
        thisSum += A[i];
        if (thisSum > result[0] || (thisSum == result[0]) && thisSum == 0) {
            result[0] = thisSum;
            end = i;
            result[1] = A[start];
            result[2] = A[end];
        } else if (thisSum < 0) {
            thisSum = 0;
            start = i + 1;
            end = -1;
        }
    }
    
    
    for (int j = 0; j < 3; j++) {
        printf("%d", result[j]);
        if (j != 2) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
    
}

int main (){
    int length;
    scanf("%d", &length);
    int list[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &list[i]);
    }
    /*for (int i = 0; i < 10; i++) {
        printf("%d ", list[i]);
    }*/
    maxSeqSum(list, length);
    
    return 0;
}