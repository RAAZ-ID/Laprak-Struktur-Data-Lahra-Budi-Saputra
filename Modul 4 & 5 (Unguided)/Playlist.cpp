#include "Playlist.h"

void createList(list &L) {
    L.first = Nil;
}

address alokasi(infotype X) {
    address P = new elmlist;
    P->info = X;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

// Mencari elemen berdasarkan judul
address findElm(list L, string judulLagu) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.judul == judulLagu) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Tambah lagu di awal playlist
void insertFirst(list &L, address P) {
    P->next = L.first;
    L.first = P;
}

// Tambah lagu di akhir playlist
void insertLast(list &L, address P) {
    if (L.first == Nil) {
        insertFirst(L, P);
    } else {
        address Last = L.first;
        while (Last->next != Nil) {
            Last = Last->next;
        }
        Last->next = P;
    }
}

void insertAfter(list &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

// Hapus lagu berdasarkan judul
void delP(list &L, string judulLagu) {
    address P = L.first;
    address Prec = Nil;
    
    // Cari elemen yang akan dihapus
    while (P != Nil && P->info.judul != judulLagu) {
        Prec = P;
        P = P->next;
    }
    
    if (P == Nil) {
        cout << "Lagu \"" << judulLagu << "\" tidak ditemukan." << endl;
        return;
    }
    
    // Proses penghapusan
    address DeletedNode = P;
    if (P == L.first) {
        // Hapus First
        L.first = P->next;
    } else {
        // Hapus di tengah/akhir
        Prec->next = P->next;
    }
    
    // P harus diputus dari rantai sebelum dealokasi
    DeletedNode->next = Nil; 
    dealokasi(DeletedNode);
    cout << "Lagu \"" << judulLagu << "\" berhasil dihapus." << endl;
}

// Tampilkan seluruh lagu dalam playlist
void printInfo(list L) {
    address P = L.first;
    if (P == Nil) {
        cout << "Playlist kosong." << endl;
    } else {
        cout << "\n=> Playlist\n";
        int counter = 1;
        while (P != Nil) {
            cout << counter++ << ". " << P->info.judul 
                 << " (" << P->info.penyanyi << ", " << P->info.durasi << " menit)" << endl;
            P = P->next;
        }
    }
}