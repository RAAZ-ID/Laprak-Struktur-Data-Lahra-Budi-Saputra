#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        // spasi depan
        for (int s = 0; s < n - i; s++) cout << "  ";

        // kiri menurun
        for (int j = i; j >= 1; j--) cout << j << " ";

        cout << "* ";

        // kanan menaik
        for (int j = 1; j <= i; j++) cout << j << " ";

        cout << endl;
    }

    // spasi terakhir dan tanda *
    for (int s = 0; s < n; s++) cout << "  ";
    cout << "*" << endl;

    return 0;
}
