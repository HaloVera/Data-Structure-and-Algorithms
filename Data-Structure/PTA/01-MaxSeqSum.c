#include <stdio.h>

// method 1: brute force(暴力解法)
// T(n) = O(N^3)
int maxSeqSum1(int A[], int N) {
    int maxSum = 0;
    int thisSum = 0;
    for(int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            thisSum = 0;
            for (int k = i; k <= j; k++) {
                thisSum += A[k];
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

// method 2
// T(n) = O(n^2)
int maxSeqSum2(int A[], int N) {
    int thisSum, maxSum;
    for (int i = 0; i < N; i++) {
        thisSum = 0;
        for (int j = i; j < N; j++) {
            thisSum += A[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
        
    }
    return maxSum;
}

// method 3: Divide and Conquer(分而治之)
// T(n) = O(nlogn)


// method 4：在线处理
// T(n) = O(n)
int maxSeqSum4(int A[], int N) {
    int thisSum = 0;
    int maxSum = 0;
    for (int i=0; i < N; i++) {
        thisSum += A[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    
    return maxSum;
}

int main () {
     int length;
     scanf("%d", &length);
     int a[length];
     for (int i=0; i < length; i++) {
         scanf("%d", &a[i]);
     }
     int result = maxSeqSum4(a, length);
     printf("%d\n", result);
     return 0;
}


