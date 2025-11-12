//*Soal 1*//
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;            
};

void createStack(Stack &S);

void push(Stack &S, infotype x);

infotype pop(Stack &S);

void printInfo(Stack S);

void balikStack(Stack &S);

//*Soal 2* Tambahan Code//
void pushAscending(Stack &S, infotype x);

//*Soal 3* Tambahan Code//
void getInputStream(Stack &S);

#endif

