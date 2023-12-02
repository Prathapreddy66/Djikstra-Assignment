#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& graph, int src, int dst) {
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<int> prev(V, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dst] == INF) {
        cout << "No path from source to destination.";
        return;
    }

    cout << "Shortest distance from " << src << " to " << dst << ": " << dist[dst] << "\n";
    cout << "Path: ";
    int curr = dst;
    vector<int> path;
    while (curr != -1) {
        path.push_back(curr);
        curr = prev[curr];
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
}

int main() {
    int V = 6;  
    vector<vector<pii>> graph(V);
    int src;
    int dst;

    graph[0].push_back({1, 5});
    graph[0].push_back({2, 3});
    graph[1].push_back({3, 6});
    graph[1].push_back({2, 2});
    graph[2].push_back({4, 4});
    graph[2].push_back({5, 2});
    graph[2].push_back({3, 7});
    graph[3].push_back({4, 1});
    graph[4].push_back({5, 2});

    cout<<"Enter source node";
    cin>>src;
    cout<<"Enter destination node";
    cin>>dst;

    dijkstra(graph, src, dst);

    return 0;
}
