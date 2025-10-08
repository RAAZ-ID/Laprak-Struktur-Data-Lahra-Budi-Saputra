/*Nama Lengkap  : Lahra budi Saputra
NIM             : 103112430054
Kelas           : IF 12-06*/
#include <iostream>

using namespace std;

    void cetakSegitigaAngka(int n) {

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        
        cout << endl;
    }
}

int main() {
    int tinggi;

    cout << "Masukkan bilangan bulat (n): ";
    cin >> tinggi;

    cout << "Pola Segitiga Angka (n = " << tinggi << ")\n";

    // Memanggil Prosedur
    cetakSegitigaAngka(tinggi);

    return 0;
}