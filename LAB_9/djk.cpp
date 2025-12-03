#include <bits/stdc++.h>
#include<limits>
using namespace std;

void dijkstra(int start, const vector<vector<pair<int,int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    vector<vector<pair<int,int>>> graph = {
        {{1,4}, {2,1}},
        {{0,4}, {2,2}, {3,5}},
        {{0,1}, {1,2}, {3,8}},
        {{1,5}, {2,8}}
    };

    dijkstra(0, graph);
    return 0;
}
