#include <iostream>
#include "bstree.h" 

using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = Nil;

    // Insert data 
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    // cout << "\nInOrder  : ";
    printInorder(root);

    // Latihan 3: Print PreOrder dan PostOrder
    cout << "\nPreOrder : ";
    printPreOrder(root);
    
    cout << "\nPostOrder: ";
    printPostOrder(root);
    cout << "\n";

    // Latihan 2: Hitung-hitungan
    cout << "\nKedalaman   : " << hitungKedalaman(root, 0) << endl; 
    cout << "Jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "Total Info  : " << hitungTotalInfo(root) << endl;

    return 0;
}