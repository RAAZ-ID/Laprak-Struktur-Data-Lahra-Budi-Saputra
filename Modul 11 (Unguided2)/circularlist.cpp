#include "circularlist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        P->next = P; 
    } else {
        address Last = L.First;
        while (Last->next != L.First) {
            Last = Last->next;
        }
        P->next = L.First;
        Last->next = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        P->next = P;
    } else {
        address Last = L.First;

        while (Last->next != L.First) {
            Last = Last->next;
        }
        Last->next = P;
        P->next = L.First;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        if (P->next == L.First) {
            L.First = Nil;
        } else {
            address Last = L.First;
            while (Last->next != L.First) {
                Last = Last->next;
            }
            L.First = P->next;
            Last->next = L.First;
        }
        P->next = Nil;
    } else {
        P = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != Nil) {
        address Last = L.First;
        address PrecLast = Nil;
        
        while (Last->next != L.First) {
            PrecLast = Last;
            Last = Last->next;
        }
        
        P = Last;
        if (PrecLast == Nil) {
            L.First = Nil;
        } else {
            PrecLast->next = L.First;
        }
        P->next = Nil;
    } else {
        P = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != L.First) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

address findElm(List L, infotype x) {
    address P = L.First;
    if (P != Nil) {
        do {
            if (P->info.nim == x.nim) {
                return P;
            }
            P = P->next;
        } while (P != L.First);
    }
    return Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List Kosong" << endl;
        return;
    }
    
    address P = L.First;
    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl;
        cout << endl; 
        P = P->next;
    } while (P != L.First);
}