#include <cstdio>
#include <queue>
#include <vector>
#define INF 100000000
using namespace std;

int v, e, s, t;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> viii;

viii graph;
vi dist;


void input_graph() {
    freopen("data/sssp-weight.in", "r", stdin);
    scanf("%d %d %d %d", &v, &e, &s, &t);
    graph.assign(v, vii());
    dist.assign(v, INF);

    int a, b, c;
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(ii(b, c));
        graph[b].push_back(ii(a, c));
    }
}

void dijkstra() {
    priority_queue<ii, vii, greater<ii>> pq;

    pq.push(ii(0, s));
    dist[s] = 0;

    while(!pq.empty()) {
        ii p = pq.top(); pq.pop();
        int d = p.first;
        int v = p.second;

        if(d > dist[v]) continue;

        for(int i = 0; i < graph[v].size(); i++) {
            ii u = graph[v][i];

            int new_dist = dist[v] + u.second;
            if(new_dist < dist[u.first]) {
                dist[u.first] = new_dist;
                pq.push(ii(new_dist, u.first));
            }
        }
    }
}

int main() {
    input_graph();
    
    printf("Single Source Shortest Path: Weigthed Graph (Dijkstra)\n");
    dijkstra(); 
    printf("cost = %d\n", dist[t]);
}
