/*Nama Lengkap  : Lahra budi Saputra
NIM             : 103112430054
Kelas           : IF 12-06*/
#include <iostream>

using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah bilangan (N): ";
    cin >> N;

    int *arr = new int[N]; 
    int *p = arr; 

    cout << "Masukkan " << N << " bilangan:\n";
    for (; p < arr + N; ++p) {
        cout << " Bilangan ke-" << (p - arr + 1) << ": ";
        cin >> *p;
    }

    p = arr; 

    long long jumlah = 0;
    int maks = *arr;
    int min = *arr; 

    for (; p < arr + N; ++p) {
        jumlah += *p;
        if (*p > maks) maks = *p;
        if (*p < min) min = *p;
    }

    // Menampilkan Hasil
    cout << "\nHasil Perhitungan:\n";
    cout << "Jumlah      = " << jumlah << endl;
    cout << "Nilai Maks  = " << maks << endl;
    cout << "Nilai Min   = " << min << endl;

    // Bersihkan memori
    delete[] arr;

    return 0;
}