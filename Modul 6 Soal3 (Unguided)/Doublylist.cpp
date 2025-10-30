#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(kendaraan x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
        P->prev = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (P == NULL) {
        return;
    }
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P; 
        P->prev = L.Last; 
        L.Last = P;       
    }
    P->next = NULL;
}

address search(List L, std::string nopol_target) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol_target) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void printInfo(List L) {
    if (L.First == NULL) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    address P = L.Last; // Mulai dari Last
    std::cout << "\nDATA LIST 1" << std::endl;
    while (P != NULL) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;
        std::cout << "warna     : " << P->info.warna << std::endl;
        std::cout << "tahun     : " << P->info.thnBuat << std::endl;
        
        P = P->prev;
    }
}


// IMPLEMENTASI BARU UNTUK LATIHAN 3 

void deleteFirst(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL; // List kosong
        return;
    }
    
    P = L.First; // Simpan elemen pertama
    
    if (L.First == L.Last) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.First = P->next;
        L.First->prev = NULL;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.Last == NULL) {
        P = NULL;
        return;
    }
    
    P = L.Last;
    
    if (L.First == L.Last) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.Last = P->prev;
        L.Last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
        return;
    }
    
    P = Prec->next; // Simpan elemen yang akan dihapus
    
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
        
        P->next = NULL;
        P->prev = NULL;
    }
}
