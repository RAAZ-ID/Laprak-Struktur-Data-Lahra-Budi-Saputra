#include <iostream>
using namespace std;

// Mendeklarasikan prototype fungsi
int maks3(int a, int b, int c);

int main() {
    int x, y, z;
    cout << "Memasukan nilai bilangan ke-1 = ";
    cin >> x;
    cout << " Memasukan nilai bilangan ke-2 = ";
    cin >> y;
    cout << " Memasukan nilai bilangan ke-3 = ";
    cin >> z;

    cout << "Nilai maksimumnya adalah = "
    << maks3(x, y, z);
    return 0;
} 

// badan fungsi
int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max)
        temp_max = b;
    if (c > temp_max)
        temp_max = c;
    return temp_max;     
}