#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) return root;
    if (x < root->info) return findNode(x, root->left);
    else return findNode(x, root->right);
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

// Implementasi Fungsi Tambahan (Latihan 2 & 3)

// Soal Latihan 2
// Menghitung Jumlah Node
int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// Menghitung Total Info
int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

// Menghitung Kedalaman (Max Depth)
int hitungKedalaman(address root, int lvl) {
    if (root == Nil) {
        return lvl;
    }

    int leftDepth = hitungKedalaman(root->left, lvl + 1);
    int rightDepth = hitungKedalaman(root->right, lvl + 1);
    
    if (leftDepth > rightDepth) return leftDepth;
    else return rightDepth;
}

// Soal Latihan 3
// PreOrder (Root -> Kiri -> Kanan)
void printPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// PostOrder (Kiri -> Kanan -> Root)
void printPostOrder(address root) {
    if (root != Nil) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}