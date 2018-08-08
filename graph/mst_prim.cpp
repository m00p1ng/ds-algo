#include <cstdio>
#include <queue>
#define MAX_NODE 100000
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> viii;

viii graph;

int n, e;

void input_graph() {
    freopen("data/mst.in", "r", stdin);
    scanf("%d %d", &n, &e);
    graph.assign(n+1, vii());

    int a, b, c;
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(ii(c, b));
        graph[b].push_back(ii(c, a));
    }
}

int prim() {
    bool visited[MAX_NODE] = {0};
    int cnt = n;
    int cost = 0;
    priority_queue<ii, vii, greater<ii>> pq;

    pq.push(ii(0, 0));

    while(!pq.empty() && cnt > 0) {
        ii p = pq.top(); pq.pop();

        if(visited[p.second]) continue;

        visited[p.second] = true;
        cnt--;
        cost += p.first;

        for(int i = 0; i < graph[p.second].size(); i++) {
            pq.push(graph[p.second][i]);
        }
    }

    return cost;
}

int main() {
    input_graph();
    
    printf("Minimum Spanning Tree: Prim\n");
    printf("cost = %d\n", prim());
}
