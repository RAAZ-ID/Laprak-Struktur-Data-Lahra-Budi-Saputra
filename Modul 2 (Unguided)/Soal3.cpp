/*Nama Lengkap  : Lahra budi Saputra
NIM             : 103112430054
Kelas           : IF 12-06*/
#include <iostream>

using namespace std;

float rata(const float a[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) total += a[i];
    return total / n;
}

void minmax(const float a[], int n, float &min, float &max) {
    min = max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
}

int main() {
    int n;
    cout << "Jumlah siswa: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Jumlah siswa harus > 0." << endl;
        return 1;
    }

    float nilai[n]; 

    // Input nilai ujian untuk N siswa
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    float min_val, max_val;

    // Memanggil fungsi untuk perhitungan
    float avg = rata(nilai, n);
    minmax(nilai, n, min_val, max_val);

    // Menampilkan hasil perhitungan
    cout << "\n--- Hasil Analisis ---\n";
    cout << "Rata-rata: " << avg << endl;
    cout << "Tertinggi: " << max_val << endl;
    cout << "Terendah : " << min_val << endl;

    return 0;
}