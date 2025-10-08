#include <iostream>
#include <string>

int main() {
    int num;
    
    std::cout << "Masukkan hanya angka 0-100: ";
    std::cin >> num;
    
    if (num < 0 || num > 100) {
        std::cout << "Input salah. Harus berupa bilangan bulat positif 0-100." << std::endl;
        return 1;
    }
    
    std::string result;
    
    std::string ones[20] = {
        "", "satu", "dua", "tiga", "empat", "lima", "enam",
        "tujuh", "delapan", "sembilan", "sepuluh", "sebelas",
        "dua belas", "tiga belas", "empat belas", "lima belas",
        "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
    };
    
    std::string tens[10] = {
        "", "", "dua puluh", "tiga puluh", "empat puluh",
        "lima puluh", "enam puluh", "tujuh puluh",
        "delapan puluh", "sembilan puluh"
    };
    
    if (num == 0) {
        result = "nol";
    } else if (num == 100) {
        result = "seratus";
    } else if (num < 20) {
        result = ones[num];
    } else {
        int ten = num / 10;
        int one = num % 10;
        result = tens[ten];
        if (one != 0) {
            result += " " + ones[one];
        }
    }
    
    std::cout << "Angka " << num << " dalam bentuk tulisan: " << result << std::endl;
    
    return 0;
}
