#include "multilist.h"

// PRIMITIF UMUM & MEMORI

bool ListEmpty(listinduk L) {
    return (L.first == Nil);
}

bool ListEmptyAnak(listanak L) {
    return (L.first == Nil);
}

void CreateList(listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotypeinduk X) {
    address P = new elemen_list_induk;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
        P->prev = Nil;
        CreateListAnak(P->lanak); 
    }
    return P;
}

address_anak alokasiAnak(infotypeanak X) {
    address_anak P = new elemen_list_anak;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

// PENCARIAN (SEARCHING)

address findElm(listinduk L, infotypeinduk X) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == X) return P;
        P = P->next;
    }
    return Nil;
}

address_anak findElm(listanak Lanak, infotypeanak X) {
    address_anak P = Lanak.first;
    while (P != Nil) {
        if (P->info == X) return P;
        P = P->next;
    }
    return Nil;
}

bool fFindElm(listinduk L, address P) {
    address Q = L.first;
    while (Q != Nil) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

bool fFindElmanak(listanak Lanak, address_anak P) {
    address_anak Q = Lanak.first;
    while (Q != Nil) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

address findBefore(listinduk L, address P) {
    if (P == L.first) {
        return Nil;
    } else {
        return P->prev;
    }
}

address_anak findBeforeAnak(listanak Lanak, infotypeinduk X, address_anak P) {
    if (P == Lanak.first) {
        return Nil;
    } else {
        return P->prev;
    }
}

// INSERT (PENAMBAHAN)

void insertFirst(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(listinduk &L, address P, address Prec) {
    P->next = Prec->next;
    P->prev = Prec;
    if (Prec->next != Nil) {
        Prec->next->prev = P;
    } else {
        L.last = P;
    }
    Prec->next = P;
}

void insertFirstAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec) {
    P->next = Prec->next;
    P->prev = Prec;
    if (Prec->next != Nil) {
        Prec->next->prev = P;
    } else {
        L.last = P;
    }
    Prec->next = P;
}

// DELETE (PENGHAPUSAN)

void delFirst(listinduk &L, address &P) {
    if (!ListEmpty(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    } else {
        P = Nil;
    }
}

void delLast(listinduk &L, address &P) {
    if (!ListEmpty(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    } else {
        P = Nil;
    }
}

void delAfter(listinduk &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}

void delP(listinduk &L, infotypeinduk X) {
    address P = findElm(L, X);
    if (P != Nil) {
        address_anak anakDel;
        while (!ListEmptyAnak(P->lanak)) {
            delFirstAnak(P->lanak, anakDel);
            dealokasiAnak(anakDel);
        }

        address Pdel;
        if (P == L.first) {
            delFirst(L, Pdel);
        } else if (P == L.last) {
            delLast(L, Pdel);
        } else {
            delAfter(L, Pdel, P->prev);
        }
        dealokasi(Pdel);
    }
}

void delFirstAnak(listanak &L, address_anak &P) {
    if (!ListEmptyAnak(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    } else {
        P = Nil;
    }
}

void delLastAnak(listanak &L, address_anak &P) {
    if (!ListEmptyAnak(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    } else {
        P = Nil;
    }
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}

void delPAnak(listanak &L, infotypeanak X) {
    address_anak P = findElm(L, X);
    if (P != Nil) {
        address_anak Pdel;
        if (P == L.first) {
            delFirstAnak(L, Pdel);
        } else if (P == L.last) {
            delLastAnak(L, Pdel);
        } else {
            delAfterAnak(L, Pdel, P->prev);
        }
        dealokasiAnak(Pdel);
    }
}

// PROSES & INFO

void printInfo(listinduk L) {
    if (ListEmpty(L)) {
        cout << "[List Kosong]" << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "Pegawai: " << P->info << endl;
            printInfoAnak(P->lanak);
            P = P->next;
        }
    }
}

void printInfoAnak(listanak Lanak) {
    if (ListEmptyAnak(Lanak)) {
        cout << "   (Tidak ada anak)" << endl;
    } else {
        address_anak Q = Lanak.first;
        cout << "   Anak: ";
        while (Q != Nil) {
            cout << Q->info;
            if (Q->next != Nil) cout << ", ";
            Q = Q->next;
        }
        cout << endl;
    }
}

int nbList(listinduk L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

int nbListAnak(listanak Lanak) {
    int count = 0;
    address_anak P = Lanak.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void delAll(listinduk &L) {
    address P;
    while (!ListEmpty(L)) {

        delFirst(L, P);
        
        address_anak anakDel;
        while (!ListEmptyAnak(P->lanak)) {
            delFirstAnak(P->lanak, anakDel);
            dealokasiAnak(anakDel);
        }
        
        dealokasi(P);
    }
}