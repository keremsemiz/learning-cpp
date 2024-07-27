#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
private:
    std::unordered_map<int, std::vector<int>> adjList;

public:
    void addVertex(int v) {
        adjList[v] = std::vector<int>();
    }

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void displayGraph() const {
        for (const auto& pair : adjList) {
            std::cout << "Vertex " << pair.first << ":";
            for (int v : pair.second) {
                std::cout << " " << v;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph graph;
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    std::cout << "Graph adjacency list:\n";
    graph.displayGraph();

    return 0;
}
