#include <iostream>
#include <vector>
#include <algorithm>

class Graph {
private:
    int V;
    std::vector<std::tuple<int, int, int>> edges;

    static bool compare(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<2>(a) < std::get<2>(b);
    }

    int find(int i, std::vector<int>& parent) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i], parent);
    }

    void unionSet(int u, int v, std::vector<int>& parent, std::vector<int>& rank) {
        u = find(u, parent);
        v = find(v, parent);
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    void kruskalMST() {
        std::sort(edges.begin(), edges.end(), compare);

        std::vector<int> parent(V);
        std::vector<int> rank(V, 0);

        for (int i = 0; i < V; ++i)
            parent[i] = i;

        int mstWeight = 0;
        std::cout << "Edges in the Minimum Spanning Tree:\n";

        for (const auto& [u, v, weight] : edges) {
            int setU = find(u, parent);
            int setV = find(v, parent);

            if (setU != setV) {
                std::cout << u << " - " << v << " : " << weight << std::endl;
                mstWeight += weight;
                unionSet(setU, setV, parent, rank);
            }
        }

        std::cout << "Weight of MST: " << mstWeight << std::endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
