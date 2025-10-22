#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include <iostream>
#include <string>

#define Nil NULL
using namespace std;

// Struktur Node Lagu
struct Lagu {
    string judul;
    string penyanyi;
    float durasi; 
};

typedef Lagu infotype;
typedef struct elmlist *address; 

struct elmlist {
    infotype info;
    address next;
}; 

struct list {
    address first; 
}; 

// Prototipe Fungsi
void createList(list &L);
address alokasi(infotype X);
void dealokasi(address &P);
address findElm(list L, string judulLagu);

void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address P, address Prec);
void delP(list &L, string judulLagu); 
void printInfo(list L);

#endif
