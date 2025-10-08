#include <iostream>

int main() {
    float num1, num2;
    
    std::cout << "Masukkan bilangan pertama: ";
    std::cin >> num1;
    std::cout << "Masukkan bilangan kedua: ";
    std::cin >> num2;

    float penjumlahan = num1 + num2;
    float pengurangan = num1 - num2;
    float perkalian = num1 * num2;
    float pembagian = (num2 != 0) ? (num1 / num2) : 0;

    std::cout << "\nHasil operasi:" << std::endl;
    std::cout << "Penjumlahan (" << num1 << " + " << num2 << "): " << penjumlahan << std::endl;
    std::cout << "Pengurangan (" << num1 << " - " << num2 << "): " << pengurangan << std::endl;
    std::cout << "Perkalian (" << num1 << " * " << num2 << "): " << perkalian << std::endl;
    std::cout << "Pembagian (" << num1 << " / " << num2 << "): " << pembagian << std::endl;
    
    return 0;
}
