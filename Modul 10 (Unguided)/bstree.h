#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Fungsi Dasar (Latihan 1)
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

// Fungsi Tambahan (Latihan 2 & 3)
// Menghitung jumlah node dalam tree
int hitungJumlahNode(address root);

// Menghitung total penjumlahan nilai info dalam tree
int hitungTotalInfo(address root);

// Menghitung kedalaman (tinggi) tree
int hitungKedalaman(address root, int lvl);

// Mencetak secara PreOrder dan PostOrder
void printPreOrder(address root);
void printPostOrder(address root);

#endif