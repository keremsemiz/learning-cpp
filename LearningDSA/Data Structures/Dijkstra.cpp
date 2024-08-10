#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Graph {
private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);  // undiretced graph
    }

    void dijkstra(int src) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        std::vector<int> dist(V, INT_MAX);

        pq.emplace(0, src);
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.emplace(dist[v], v);
                }
            }
        }

        std::cout << "Vertex Distance from Source:\n";
        for (int i = 0; i < V; ++i)
            std::cout << i << "\t\t" << dist[i] << std::endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 9);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(0, 4, 3);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 4);

    g.dijkstra(0);

    return 0;
}
