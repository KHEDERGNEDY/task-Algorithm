#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int numberVertex;
    vector<vector<int>> adj;  //Neighborhood List

    Graph(int V) {
        this->numberVertex  = V;
        adj.resize(V);
    }

    // Function to add an arrow from node v to node u
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    //Function to perform DFS on chart
    void dfs(int u, vector<bool>& visited, stack<int>& Stack) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, visited, Stack);
            }
        }
        Stack.push(u); //Function to perform DFS on chart
    }

    //Function to transpose a graph
    void transposeGraph(Graph& gt) {
        for (int u = 0; u < numberVertex; u++) {
            for (int v : adj[u]) {
                gt.addEdge(v, u); // reverse
            }
        }
    }

    // Function to find strongly connected components (SCC)
    void cheriyanMehlhornGabow() {
        stack<int> Stack;
        vector<bool> visited(numberVertex, false);

       //DFS procedure to fill the stack
        for (int i = 0; i < numberVertex; i++) {
            if (!visited[i]) {
                dfs(i, visited, Stack);
            }
        }

        // Create an inverted chart
        Graph gt(numberVertex);
        transposeGraph(gt);

        // Reset visited for all nodes
        fill(visited.begin(), visited.end(), false);

        // Perform DFS on the inverted graph based on stack order
        while (!Stack.empty()) {
            int u = Stack.top();
            Stack.pop();

            if (!visited[u]) {
                cout << "SCC: ";
                dfsOnTranspose(u, visited, gt);
                cout << endl;
            }
        }
    }

    // Function to perform DFS on inverse graph
    void dfsOnTranspose(int u, vector<bool>& visited, Graph& gt) {
        visited[u] = true;
        cout << u << " ";
        for (int v : gt.adj[u]) {
            if (!visited[v]) {
                dfsOnTranspose(v, visited, gt);
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertex ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edge ";
    cin >> E;

    cout << "add edge for vertex form (edge,vertex) " << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

   //use Alogrithm Cheriyan-Mehlhorn-Gabow to discover strongly connected components
    cout << "Part Strongly connected " << endl;
    g.cheriyanMehlhornGabow();

    return 0;
}