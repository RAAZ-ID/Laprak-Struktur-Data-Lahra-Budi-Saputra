#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

typedef string infotypeinduk; 
typedef string infotypeanak; 
typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

// Struktur Anak
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};

// Struktur Induk
struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak; 
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

// PROTOTYPE FUNGSI (PROGRAM 46)

// Pengecekan List Kosong
bool ListEmpty(listinduk L);
bool ListEmptyAnak(listanak L);

// Pembuatan List
void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

// Manajemen Memori
address alokasi(infotypeinduk X);
address_anak alokasiAnak(infotypeanak X);
void dealokasi(address P);
void dealokasiAnak(address_anak P);

// Pencarian
address findElm(listinduk L, infotypeinduk X);
address_anak findElm(listanak Lanak, infotypeanak X);

bool fFindElm(listinduk L, address P);
bool fFindElmanak(listanak Lanak, address_anak P);

address findBefore(listinduk L, address P);
address_anak findBeforeAnak(listanak Lanak, infotypeinduk X, address_anak P);

// Penambahan Elemen Induk
void insertFirst(listinduk &L, address P);
void insertLast(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);

// Penambahan Elemen Anak
void insertFirstAnak(listanak &L, address_anak P);
void insertLastAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);

// Penghapusan Elemen Induk
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X);

// Penghapusan Elemen Anak
void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X);

// Cetak & Hitung
void printInfo(listinduk L);
int nbList(listinduk L);
void printInfoAnak(listanak Lanak);
int nbListAnak(listanak Lanak);

// Proses Delete All
void delAll(listinduk &L);

#endif