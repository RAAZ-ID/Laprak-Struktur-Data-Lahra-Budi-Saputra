  /*Nama Lengkap : Lahra budi Saputra
NIM : 103112430054
Kelas : IF 12-06*/
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

// Rumus: 0.3*uts + 0.4*uas + 0.3*tugas
float hitungNilaiAkhir(float nilai_uts, float nilai_uas, float nilai_tugas) {
    return (0.3 * nilai_uts) + (0.4 * nilai_uas) + (0.3 * nilai_tugas);
}

void dataMhs(Mahasiswa &mhs) {
    cin.ignore(); 
    
    cout << "Masukkan Nama Lengkap : ";
    getline(cin, mhs.nama);
    
    cout << "Masukkan NIM          : ";
    cin >> mhs.nim;
    
    cout << "Masukkan Nilai UTS    : ";
    cin >> mhs.uts;
    
    cout << "Masukkan Nilai UAS    : ";
    cin >> mhs.uas;
    
    cout << "Masukkan Nilai Tugas  : ";
    cin >> mhs.tugas;

    // Hitung dan simpan Nilai Akhir
    mhs.nilai_akhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
}

void tampilkanData(const Mahasiswa mhs[], int jumlah) {
    cout << "\n======================================================\n";
    cout << "No\tNIM\t\tNama\t\tNilai Akhir\n";
    cout << "------------------------------------------------------\n";
    
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t" 
             << mhs[i].nim << "\t"
             << mhs[i].nama << "\t\t"
             << mhs[i].nilai_akhir << endl;
    }
    cout << "======================================================\n";
}

int main() {
    Mahasiswa list[10];
    int jumlah = 0;
    char lagi;

    cout << "===> INPUT DATA MAHASISWA <===\n";

    do {
        if (jumlah >= 10) {
            cout << "\n Tidak dapat menambah data lagi (maks. 10).\n";
            break;
        }

        dataMhs(list[jumlah]);
        jumlah++;

        cout << "\nTambah data lagi? (y/t): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    tampilkanData(list, jumlah);
    return 0;
}