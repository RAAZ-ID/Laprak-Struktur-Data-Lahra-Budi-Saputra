#include "pelajaran.h"
#include <iostream>

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran P;
    
    P.namaMapel = namapel;
    P.kodeMapel = kodepel;
    
    return P;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran: " << pel.namaMapel << endl;
    cout << "kode: " << pel.kodeMapel << endl;
}