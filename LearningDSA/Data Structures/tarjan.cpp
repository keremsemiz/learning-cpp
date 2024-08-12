#include <iostream>
#include <vector>
#include <stack>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adj;
    int time;
    std::vector<int> disc;
    std::vector<int> low;
    std::stack<int> stk;
    std::vector<bool> inStack;

    void SCCUtil(int u) {
        disc[u] = low[u] = ++time;
        stk.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                SCCUtil(v);
                low[u] = std::min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = std::min(low[u], disc[v]);
            }
        }

        int w = 0;
        if (low[u] == disc[u]) {
            while (stk.top() != u) {
                w = stk.top();
                std::cout << w << " ";
                inStack[w] = false;
                stk.pop();
            }
            w = stk.top();
            std::cout << w << std::endl;
            inStack[w] = false;
            stk.pop();
        }
    }

public:
    Graph(int V) : V(V), adj(V), time(0), disc(V, -1), low(V, -1), inStack(V, false) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void SCC() {
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                SCCUtil(i);
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    std::cout << "Strongly connected components in the given graph:\n";
    g.SCC();

    return 0;
}