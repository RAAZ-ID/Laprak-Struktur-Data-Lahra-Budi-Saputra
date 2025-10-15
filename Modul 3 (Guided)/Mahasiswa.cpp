/*Nama Lengkap  : Lahra budi Saputra
NIM             : 103112430054
Kelas           : IF 12-06*/
#include "mahasiswa.h"
#include <iostream>
using namespace std;

void inputMhs(mahasiswa &m)
{
    cout << "Input NIM: ";
    cin >> (m.nim);
    cout << "Input Nilai 1: ";
    cin >> (m.nilai1);
    cout << "Input Nilai 2: ";
    cin >> (m.nilai2);
}

float rata2(mahasiswa m)
{
    return float(m.nilai1 + m.nilai2) / 2;
}