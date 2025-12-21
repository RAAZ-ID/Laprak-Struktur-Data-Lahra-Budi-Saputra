#include <iostream>
#include "multilist.h"
#include "multilist.cpp"

using namespace std;

int main() {
    listinduk L;
    CreateList(L);
    address P;
    address_anak Panak;

    cout << " ==> INSERT INDUK <==" << endl;
    
    P = alokasi("Saputra");
    insertLast(L, P);

    P = alokasi("Lahra");
    insertFirst(L, P);

    address Prec = findElm(L, "Lahra");
    if (Prec != Nil) { 
        P = alokasi("Budi");
        insertAfter(L, P, Prec);
    }

    printInfo(L);
    cout << "Jumlah Pegawai : " << nbList(L) << endl << endl;

    cout << "==> INSERT ANAK <==" << endl;
    
    address ortu = findElm(L, "Saputra");
    
    if (fFindElm(L, ortu)) {
        cout << "Pegawai Saputra ditemukan valid, menambahkan anak.." << endl;
        
        Panak = alokasiAnak("Kiki");
        insertLastAnak(ortu->lanak, Panak);
        
        Panak = alokasiAnak("Lala");
        insertLastAnak(ortu->lanak, Panak);

        address_anak PrecAnak = findElm(ortu->lanak, "Kiki");
        if (PrecAnak != Nil) {
            Panak = alokasiAnak("Momo");
            insertAfterAnak(ortu->lanak, Panak, PrecAnak);
        }
    }
    
    printInfo(L);
    if (ortu != Nil) {
        cout << "Jumlah anak Saputra: " << nbListAnak(ortu->lanak) << endl;
    }
    cout << endl;

    cout << "==> TEST <==" << endl;
    
    address target = findElm(L, "Budi");
    address before = findBefore(L, target);
    if (before != Nil) {
        cout << "Sebelum Budi adalah: " << before->info << endl;
    }

    if (ortu != Nil) {
        address_anak targetAnak = findElm(ortu->lanak, "Lala");
        address_anak beforeAnak = findBeforeAnak(ortu->lanak, "XXX", targetAnak); 
        if (beforeAnak != Nil) {
            cout << "Sebelum Lala adalah: " << beforeAnak->info << endl;
        }
    }
    cout << endl;

    cout << "==> TEST DELETE <==" << endl;

    if (ortu != Nil) {
        address_anak delAnak;
        delLastAnak(ortu->lanak, delAnak);
        cout << "Menghapus anak terakhir Saputra: " << delAnak->info << endl;
        dealokasiAnak(delAnak);
    }

    cout << "Menghapus Pegawai Budi..." << endl;
    delP(L, "Budi");

    printInfo(L);
    cout << endl;

    cout << "==> DELETE ALL <==" << endl;
    delAll(L);
    printInfo(L);

    return 0;
}