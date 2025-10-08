/*Nama Lengkap  : Lahra budi Saputra
NIM             : 103112430054
Kelas           : IF 12-06*/
#include <iostream>
#include <string>

using namespace std;

// Konstanta ukuran array
const int JUMLAH_MAHASISWA = 5;
const int JUMLAH_MATA_KULIAH = 3;

// Fungsi untuk menampilkan garis pemisah
void print_separator() {
    cout << "--------------------------------------------------------------------------------\n";
}

int main() {
    double nilai[JUMLAH_MAHASISWA][JUMLAH_MATA_KULIAH]; 
    string nama[JUMLAH_MAHASISWA]; 
    double rata2[JUMLAH_MAHASISWA]; 
    
    // Variabel untuk melacak mahasiswa terbaik
    double max_rata2 = -1.0;
    int best_idx = -1;

    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        cout << "\n===> Input Data Mahasiswa ke-" << i + 1 << " <===\n";
        
        cout << "Masukkan Nama: ";
        getline(cin >> ws, nama[i]); 

        double total = 0;
        
        // Input nilai 3 mata kuliah
        for (int j = 0; j < JUMLAH_MATA_KULIAH; j++) {
            cout << "Nilai Mata Kuliah ke-" << j + 1 << ": ";
            cin >> nilai[i][j];
            total += nilai[i][j];
        }

        // Hitung rata-rata
        rata2[i] = total / JUMLAH_MATA_KULIAH;

        // Tentukan terbaik
        if (rata2[i] > max_rata2) {
            max_rata2 = rata2[i];
            best_idx = i;
        }
    }

    cout << "\n\n=== TABEL HASIL NILAI AKHIR ===\n";
    print_separator();
    cout << "NO\tNAMA\t\tMK 1\tMK 2\tMK 3\tRATA-RATA\tKETERANGAN\n";

    // Mengatur presisi untuk tampilan
    cout.precision(4); 

    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        cout << i + 1 << "\t" << nama[i] << "\t";
        
        if (nama[i].length() < 12) {
            cout << "\t";
        }
        
        for (int j = 0; j < JUMLAH_MATA_KULIAH; j++) {
            cout << nilai[i][j] << "\t";
        }

        cout << rata2[i] << "\t\t";

        if (i == best_idx) {
            cout << "== TERBAIK ==";
        } else {
            cout << "-";
        }
        cout << "\n";
    }
    
    print_separator();
    cout << "\nMahasiswa dengan Rata-rata Tertinggi: " << nama[best_idx] 
         << " (Rata-rata: " << max_rata2 << ")\n";
         
    return 0;
}