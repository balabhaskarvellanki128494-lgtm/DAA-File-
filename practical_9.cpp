#include <iostream>
#include <climits>
using namespace std;

#define V 5

int minKey(int key[], bool inMST[]) {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++)
        if (!inMST[v] && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

void primMST(int graph[V][V]) {
    int parent[V];     
    int key[V];        
    bool inMST[V];     

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    key[0] = 0;        
    parent[0] = -1;    

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST);
        inMST[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // Print MST
    int total = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
    }
    cout << "Total weight of MST = " << total << endl;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}
