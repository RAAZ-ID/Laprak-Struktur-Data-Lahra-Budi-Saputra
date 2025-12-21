#include <iostream>
#include "graph.h"
#include "graph.cpp"

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    adrNode A = findNode(G, 'A');
    adrNode B = findNode(G, 'B');
    adrNode C = findNode(G, 'C');
    adrNode D = findNode(G, 'D');
    adrNode E = findNode(G, 'E');
    adrNode F = findNode(G, 'F');
    adrNode G_Node = findNode(G, 'G');
    adrNode H = findNode(G, 'H');

    connectNode(G, A, B);
    connectNode(G, A, C);

    connectNode(G, B, D);
    connectNode(G, B, E);

    connectNode(G, C, F);
    connectNode(G, C, G_Node);

    connectNode(G, D, H);
    connectNode(G, E, H);
    connectNode(G, F, H);
    connectNode(G, G_Node, H);

    cout << "==> INFO GRAPH (ADJACENCY LIST) <==" << endl;
    printInfoGraph(G);
    cout << endl;

    cout << "==> PENELUSURAN DFS (Start Node A) <==" << endl;
    printDFS(G, A);
    cout << endl;

    cout << "==> PENELUSURAN BFS (Start Node A) <==" << endl;
    printBFS(G, A);
    cout << endl;

    return 0;
}