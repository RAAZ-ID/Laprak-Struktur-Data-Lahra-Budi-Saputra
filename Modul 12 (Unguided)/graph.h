#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited; 
    adrEdge firstEdge; 
    adrNode next;       
};

struct ElmEdge {
    adrNode node;  
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, adrNode N1, adrNode N2);
void printInfoGraph(Graph G);

adrNode findNode(Graph G, infoGraph X);
void addEdge(adrNode NAsal, adrNode NTujuan);

void resetVisited(Graph &G);
void printDFS(Graph G, adrNode N);
void printBFS(Graph G, adrNode N);

#endif 