#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, w;
};
int parent[100];
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int a, int b) {
    parent[find(a)] = find(b);
}
bool compare(Edge a, Edge b) {
    return a.w < b.w;
}
int main() {
    int V = 5, E = 7;
    Edge edges[] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8},
        {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };
    sort(edges, edges + E, compare);
     for (int i = 0; i < V; i++)
        parent[i] = i;
    int total = 0, count = 0;
    cout << "Edge \tWeight\n";
    for (int i = 0; i < E && count < V - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);
        if (a != b) {                 
            cout << edges[i].u << " - " << edges[i].v
                 << " \t" << edges[i].w << endl;
            total += edges[i].w;
            unite(a, b);
            count++;
        }
    }
    cout << "Total weight of MST = " << total << endl;
    return 0;
}
