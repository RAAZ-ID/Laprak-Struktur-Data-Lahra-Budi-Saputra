#include "Playlist.h"
#include "Playlist.cpp"

// Fungsi bantu untuk mendapatkan alamat node ke-N
address getAddressNth(list L, int N) {
    address P = L.first;
    int count = 1;
    while (P != Nil && count < N) {
        P = P->next;
        count++;
    }
    return P;
}

int main() {
    list PlaylistSaya;
    createList(PlaylistSaya);
    address P;

    // Data Lagu Awal
    Lagu L1 = {"Mimpi", "Isyana Sarasvati", 4.3f};
    Lagu L2 = {"Monokrom", "Tulus", 3.4f};
    Lagu L3 = {"Raja", "Dewa 19", 4.0f};
    Lagu L4 = {"Laskar Pelangi", "Nidji", 4.8f};
    
    // Tambah Lagu di Awal
    P = alokasi(L1);
    insertFirst(PlaylistSaya, P);
    P = alokasi(L2);
    insertFirst(PlaylistSaya, P);
    
    // Tambah Lagu di Akhir
    P = alokasi(L3);
    insertLast(PlaylistSaya, P);

    cout << "====> PLAYLIST AWAL <====";
    printInfo(PlaylistSaya);
    
    // Tambah Lagu Setelah Posisi Ke-3
    P = alokasi(L4);
    int posisiInsert = 3;
    address Prec = getAddressNth(PlaylistSaya, posisiInsert);
    
    if (Prec != Nil) {
        insertAfter(PlaylistSaya, P, Prec);
        cout << "\nOperasi: Tambah " << L4.judul << " setelah lagu ke-" << posisiInsert << "\n";
    } else {
        cout << "\nOperasi: Posisi ke-" << posisiInsert << " tidak ditemukan.\n";
    }

    // Tampilkan Seluruh Lagu
    cout << "=====> PLAYLIST SETELAH INSERT AFTER <====";
    printInfo(PlaylistSaya); 
    // Urutan: [Monokrom, Mimpi, Raja, Laskar Pelangi]

    // Hapus Lagu Berdasarkan Judul
    string judulHapus1 = "Monokrom";
    cout << "\nOperasi: Hapus lagu \"" << judulHapus1 << "\"\n";
    delP(PlaylistSaya, judulHapus1);

    string judulHapus2 = "Raja";
    cout << "Operasi: Hapus lagu \"" << judulHapus2 << "\"\n";
    delP(PlaylistSaya, judulHapus2);

    cout << "\n====> PLAYLIST AKHIR <====";
    printInfo(PlaylistSaya);
    // Urutan Akhir: [Mimpi, Laskar Pelangi]
    
    return 0;
}