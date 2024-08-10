#include <iostream>
#include <vector>
#include <tuple>

class Graph {
private:
    int V;
    std::vector<std::tuple<int, int, int>> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    void bellmanFord(int src) {
        std::vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int i = 1; i < V; ++i) {
            for (const auto& [u, v, weight] : edges) {
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        for (const auto& [u, v, weight] : edges) {
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                std::cout << "Graph contains a negative weight cycle" << std::endl;
                return;
            }
        }

        std::cout << "Vertex Distance from Source:\n";
        for (int i = 0; i < V; ++i)
            std::cout << i << "\t\t" << dist[i] << std::endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0);

    return 0;
}
