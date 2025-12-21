#include "graph.h"
#include <stack>
#include <queue>

void createGraph(Graph &G) {
    G.first = NULL;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode last = G.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
    }
}

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void addEdge(adrNode NAsal, adrNode NTujuan) {
    adrEdge newEdge = new ElmEdge;
    newEdge->node = NTujuan;
    newEdge->next = NULL;

    if (NAsal->firstEdge == NULL) {
        NAsal->firstEdge = newEdge;
    } else {
        adrEdge last = NAsal->firstEdge;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newEdge;
    }
}

void connectNode(Graph &G, adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        addEdge(N1, N2);
        addEdge(N2, N1);
    }
}

void printInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

//  Implementasi(DFS & BFS)

void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void printDFS(Graph G, adrNode N) {
    if (N == NULL) return;
    
    resetVisited(G);
    
    stack<adrNode> S;
    S.push(N);
    
    cout << "DFS Traversal: ";
    
    while (!S.empty()) {
        adrNode curr = S.top();
        S.pop();
        
        if (curr->visited == 0) {
            curr->visited = 1;
            cout << curr->info << " ";
            
            adrEdge E = curr->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }
    cout << endl;
}

void printBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    resetVisited(G);

    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    cout << "BFS Traversal: ";

    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";

        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
    cout << endl;
}