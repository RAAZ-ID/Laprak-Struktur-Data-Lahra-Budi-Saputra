//*Soal 1*//
#include "stack.h"
#include <iostream>

void createStack(Stack &S) {
    S.top = 0; 
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top = S.top + 1; 
        S.info[S.top] = x;
    } else {
        std::cout << "Stack penuh!" << std::endl;
    }
}

infotype pop(Stack &S) {
    infotype data;
    if (S.top > 0) {
        data = S.info[S.top];
        S.top = S.top - 1; 
        return data;
    } else {
        std::cout << "Stack kosong!" << std::endl;
        return -1; 
    }
}

void printInfo(Stack S) {
    std::cout << "[TOP] ";
    for (int i = S.top; i >= 1; i--) {
        std::cout << S.info[i] << " ";
    }
    std::cout << std::endl;
}

void balikStack(Stack &S) {
    Stack S_temp;
    createStack(S_temp);

    while (S.top != 0) {
        push(S_temp, pop(S));
    }

    S = S_temp;
}

//*Soal 2* Tambahan Code//
void pushAscending(Stack &S, infotype x) {
    Stack S_temp;
    createStack(S_temp);

    while (S.top > 0 && x < S.info[S.top]) {
        push(S_temp, pop(S));
    }

    push(S, x);

    while (S_temp.top > 0) {
        push(S, pop(S_temp));
    }
}

// *Soal 3* Tambahan Code
void getInputStream(Stack &S) {
    char ch;
    ch = std::cin.get();

    while (ch != '\n') {
        infotype x = ch - '0'; 

        push(S, x);

        ch = std::cin.get();
    }
}