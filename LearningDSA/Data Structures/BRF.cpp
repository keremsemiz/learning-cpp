#include <iostream>
#include <list>
#include <vector>
#include <queue>

class Graph {
private:
    int V;
    std::vector<std::list<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        std::vector<bool> visited(V, false);
        std::queue<int> queue;

        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            std::cout << s << " ";
            queue.pop();

            for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push(*i);
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Breadth First Traversal starting from vertex 2:\n";
    g.BFS(2);

    return 0;
}