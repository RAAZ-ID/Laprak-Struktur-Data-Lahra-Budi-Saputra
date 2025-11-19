// // Nama : Lahra Budi Saputra
// // NIM  : 103112430054
// // Kelas: IF 12-06 Teknik Informatika A'24
#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong" << endl;
    } else {
        val = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
    }
    return val;
}

void printInfo(Queue Q) {

    if (Q.head >= 0) {
        cout << " "; 
    }
    cout << Q.head << " - ";

    if (Q.tail >= 0) {
        cout << " ";
    }
    cout << Q.tail << " : ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}

//* SOAL NOMOR 2*//
// Queue Alternatif 2 (head bergerak, tail bergerak)
#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}
bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}
bool isFullQueue(Queue Q) {
    return (Q.head == 0 && Q.tail == MAX - 1);
}
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            if (Q.tail == MAX - 1) {
                for (int i = Q.head; i <= Q.tail; i++) {
                    Q.info[i - Q.head] = Q.info[i];
                }
                // Sesuaikan posisi Tail dan Head setelah digeser
                Q.tail = Q.tail - Q.head; 
                Q.head = 0;

                // Setelah geser, barulah tambahkan elemen baru
                Q.tail++;
                Q.info[Q.tail] = x;
            } else {
                // Jika belum mentok, Tail cukup maju biasa
                Q.tail++;
                Q.info[Q.tail] = x;
            }
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong" << endl;
    } else {
        val = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++;
        }
    }
    return val;
}

void printInfo(Queue Q) {
    if (Q.head != -1 && Q.head < 10) cout << " ";
    cout << Q.head << " - ";
    if (Q.tail != -1 && Q.tail < 10) cout << " ";
    cout << Q.tail << " : ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}


//* SOAL NOMOR 3*//
//queue Alternatif 3 (head dan tail berputar)
#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong" << endl;
    } else {
        val = Q.info[Q.head];
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
    }
    return val;
}

void printInfo(Queue Q) {
    if (Q.head != -1 && Q.head < 10) cout << " ";
    cout << Q.head << " - ";
    if (Q.tail != -1 && Q.tail < 10) cout << " ";
    cout << Q.tail << " : ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break; // Berhenti jika sudah di posisi Tail
            i = (i + 1) % MAX;      // Pindah index memutar
        }
        cout << endl;
    }
}