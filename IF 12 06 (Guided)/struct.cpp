#include <iostream>
using namespace std;


struct Mahasiswa
{
    string nama;
    string NIM;
};

int main()
{
    Mahasiswa mhs;
    mhs.nama = "lahra budi saputra";
    mhs.NIM = "103112430054";

    cout << "Nama: " << mhs.nama << endl
         <<  "NIM: " << mhs.NIM;

}
