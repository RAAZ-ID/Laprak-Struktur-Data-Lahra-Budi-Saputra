#include <iostream>

using namespace std;

void tampilkanArray(const int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarElemenArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarNilaiPointer(int* pA, int* pB) {
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}

int main() {
    int ArrayA[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int ArrayB[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int *ptr1, *ptr2;
    int nilaiX = 1000, nilaiY = 2000;

    ptr1 = &nilaiX;
    ptr2 = &nilaiY;

    cout << "===> Sebelum Pertukaran <===" << endl;
    cout << "Array A:" << endl;
    tampilkanArray(ArrayA);
    cout << "Array B:" << endl;
    tampilkanArray(ArrayB);
    cout << "Pointer 1: " << *ptr1 << ", Pointer 2: " << *ptr2 << endl << endl;

    //OPERASI PERTUKARAN

    tukarElemenArray(ArrayA, ArrayB, 0, 0);

    tukarNilaiPointer(ptr1, ptr2);

    cout << "===> Sesudah Pertukaran <===" << endl;
    cout << "Array A:" << endl;
    tampilkanArray(ArrayA);
    cout << "Array B:" << endl;
    tampilkanArray(ArrayB);
    cout << "Pointer 1: " << *ptr1 << ", Pointer 2: " << *ptr2 << endl;

    return 0;
}