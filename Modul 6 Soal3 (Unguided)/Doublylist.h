#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
#include <algorithm>

struct kendaraan {
    std::string nopol;    // Nomor Polisi
    std::string warna;
    int thnBuat;          // Tahun Pembuatan
};

typedef struct ElmList* address;

struct ElmList {
    kendaraan info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address search(List L, std::string nopol_target);


void deleteFirst(List &L, address &P);

void deleteLast(List &L, address &P);

void deleteAfter(List &L, address Prec, address &P);

#endif