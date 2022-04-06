#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef; // 系数
    int expon; // 指数
    Polynomial link;
};

void Attach(int c, int e, Polynomial *pRear) {
    Polynomial P;
    
    P = malloc(sizeof(struct PolyNode));
    P->link = NULL;
    P->expon = e;
    P->coef = c;
    (*pRear)->link = P;
    *pRear = P;
    
}

Polynomial ReadPoly() {
    Polynomial P, Rear;
    int c, e, N;
    // read first input number to know how many terms this polynomial has 
    scanf("%d", &N);
    P = malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(N--) {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    };
    
    Polynomial temp = P;
    P = P->link;
    free(temp);
    return P; 
}

Polynomial Add(Polynomial P1, Polynomial P2) {
    // copy head of two polynomials
    Polynomial t1 = P1;
    Polynomial t2 = P2;
    // result pointer
    Polynomial PS = malloc(sizeof(struct PolyNode));
    PS->link = NULL;
    Polynomial temp = PS;
    Polynomial Rear = PS;
    int sum = 0;
    while (t1 && t2) {
        if(t1->expon > t2->expon) {
            Attach(t1->coef, t1->expon, &Rear);
            t1 = t1->link;
        } else if (t1->expon < t2->expon) {
            Attach(t2->coef, t2->expon, &Rear);
            t2 = t2->link;
        } else if(t1->expon == t2->expon) {
            sum = t1->coef + t2->coef;
            if (sum) Attach(sum, t1->expon, &Rear);
            t1 = t1->link;
            t2 = t2->link;
        }
    };
    
    while(t1) {
        Attach(t1->coef, t1->expon, &Rear);
        t1 = t1->link;
    };
    
    while(t2) {
        Attach(t2->coef, t2->expon, &Rear);
        t2 = t2->link;
    };
    
    temp = PS;
    PS = PS->link;
    free(temp);
    
    return PS;
};

Polynomial Mult(Polynomial P1, Polynomial P2) {
    Polynomial t1 = P1;
    Polynomial t2 = P2;
    Polynomial P = malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Polynomial Rear = P;
    Polynomial PP = NULL;
    while(t1) {
        t2 = P2;
        P->link = NULL;
        Rear = P;
        while (t2) {
            Attach(t1->coef*t2->coef, t1->expon+t2->expon, &Rear);
            t2 = t2->link;
        }
        PP = Add(PP, P->link);
        t1 = t1->link;
    }
    free(P);
    return PP;
}

void PrintPoly(Polynomial P) {
    int flag = 0;
    if (!P) {printf("0 0\n"); return;}
    
    while(P) {
        if (!flag) {
            flag = 1;
        } else {
            printf(" ");
        };
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

int main() {
    
    // read 2 polynomials
    Polynomial P1 = ReadPoly();
    Polynomial P2 = ReadPoly();
    
    // multiply 2 polynomials
    Polynomial PP = Mult(P1, P2);
    
    // print multiply result
    PrintPoly(PP);
    
    // add 2 polynomials
    Polynomial PS = Add(P1, P2);
    
    // print sum result
    PrintPoly(PS);
    
    return 0;
}