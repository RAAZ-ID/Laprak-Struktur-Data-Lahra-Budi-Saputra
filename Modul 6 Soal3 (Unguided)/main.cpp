#include "Doublylist.h"

void processInput(List &L, std::string nopol, std::string warna, int thnBuat) {
    kendaraan k;
    k.nopol = nopol;
    k.warna = warna;
    k.thnBuat = thnBuat;
    
    std::cout << "masukkan nomor polisi: " << nopol << std::endl;
    std::cout << "masukkan warna kendaraan: " << warna << std::endl;
    std::cout << "masukkan tahun kendaraan: " << thnBuat << std::endl;
    
    if (search(L, k.nopol) == NULL) {
        address P = alokasi(k);
        if (P) {
            insertLast(L, P);
        }
    } else {
        std::cout << "nomor polisi sudah terdaftar" << std::endl << std::flush;
    }
    std::cout << std::endl; 
}

int main() {
    List L;
    CreateList(L);
    
    // ===> Latihan 1: Memasukkan Data <===
    std::cout << "===> Latihan 1: Input Data <===" << std::endl;
    processInput(L, "D001", "hitam", 90);
    processInput(L, "D003", "putih", 70);
    processInput(L, "D001", "merah", 80); 
    processInput(L, "D004", "kuning", 90); 
    
    // ===> Latihan 2: Mencari Data <===
    std::cout << "\n===> Latihan 2: Mencari Data <===" << std::endl;
    std::string nopol_dicari;
    
    std::cout << "Masukkan Nomor Polisi yang dicari : D001" << std::endl;
    nopol_dicari = "D001";
    
    address found = search(L, nopol_dicari);
    
    if (found != NULL) {
        std::cout << "Nomor Polisi \t: " << found->info.nopol << std::endl;
        std::cout << "Warna \t\t: " << found->info.warna << std::endl;
        std::cout << "Tahun \t\t: " << found->info.thnBuat << std::endl;
    } else {
        std::cout << "Data dengan nomor polisi " << nopol_dicari << " tidak ditemukan." << std::endl;
    }
    
    // ===> LATIHAN 3: MENGHAPUS DATA <=== 
    std::cout << "\n===> Latihan 3: Menghapus Data <===" << std::endl;
    std::string nopol_hapus;
    
    std::cout << "Masukkan Nomor Polisi yang akan dihapus : D003" << std::endl;
    nopol_hapus = "D003";

    address P_hapus = NULL;
    address P_target = search(L, nopol_hapus);
    
    if (P_target == NULL) {
        std::cout << "Data dengan nomor polisi " << nopol_hapus << " tidak ditemukan." << std::endl;
    } else {
        // Tentukan prosedur delete yang tepat
        if (P_target == L.First) {
            deleteFirst(L, P_hapus);
        } else if (P_target == L.Last) {
            deleteLast(L, P_hapus);
        } else {
            deleteAfter(L, P_target->prev, P_hapus);
        }
        
        // Dealokasi node yang dikembalikan
        dealokasi(P_hapus); 
        
        // Cetak pesan sukses 
        std::cout << "Data dengan nomor polisi " << nopol_hapus << " berhasil dihapus." << std::endl;
    }

    // Tampilkan list terakhir 
    printInfo(L); 
    
    return 0;
}