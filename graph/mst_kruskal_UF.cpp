#include <cstdio>
#include <algorithm>
#include "disjoint_set.cpp"
#define MAX_EDGE 100000
using namespace std;

struct edge {
    int src, dest, weight;
};

int n, e;

edge graph[MAX_EDGE];

void input_graph() {
    freopen("data/mst.in", "r", stdin);
    scanf("%d %d", &n, &e);


    int a, b, c;
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[i] = {a, b, c};
    }
}

bool cmp(edge a, edge b) {
    return a.weight < b.weight;
}

int kruskal() {
    DisjointSet ds = DisjointSet(n);
    sort(graph, graph+e, cmp);

    int cnt = n;
    int cost = 0;
    int i = 0;

    while(cnt > 1) {
        if(ds.union_set(graph[i].src, graph[i].dest)) {
            cost += graph[i].weight;
            cnt--;
        }
        i++;
    }

    return cost;
}

int main() {
    input_graph();
    
    printf("Minimum Spanning Tree: Kruskal (Union-Find)\n");
    printf("cost = %d\n", kruskal());
}
