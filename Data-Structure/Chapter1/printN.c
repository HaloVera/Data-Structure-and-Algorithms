// print interger from 1 to N with 2 ways
// demostrate even a simple requirment can have different ways to implement


#include <stdio.h>

void printN(int N);

int main () {
    int N;
    scanf("%d", &N);
    printN(N);
    return 0;
}

// loop implementation
void printN(int N) {
   int i;
   for (i = 1; i <= N; i++) {
       printf("%d\n", i);
    }
    return;
};

// recursive implementation
// when N = 1000000, terminal can not work
/*void printN(int N) {
    if (N) {
        printN(N - 1);
        printf("%d\n", N);
    }
    return;
}*/