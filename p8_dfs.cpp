#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<vector<int>> adj_matrix;
    int n;

public:
    Graph(int n)
    {
        this->n = n;
        adj_matrix.resize(n);
    }

    void add_edge(int u, int v)
    {
        // Undirected graph
        adj_matrix[u].push_back(v);
        adj_matrix[v].push_back(u);
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> ";
            for (auto &child : adj_matrix[i])
                cout << child << ", ";
            cout << endl;
        }
    }

    // helper recursive func
    void dfs_helper(int s, int visited[], int parent[])
    {
        visited[s] = true;
        cout << s << " ";

        for (auto &child : adj_matrix[s])
        {
            if (!visited[child])
            {
                parent[child] = s;
                dfs_helper(child, visited, parent);
            }
        }
    }

    void dfs(int s)
    {
        int visited[n] = {false};
        int parent[n] = {-1};

        cout << "DFS Traversal -> ";
        dfs_helper(s, visited, parent);

        cout << endl
             << "DFS Tree (parent -> child)" << endl;
        for (int i = 0; i < n; i++)
            if (parent[i] != -1)
                cout << parent[i] << " -> " << i << endl;
    }
};

int main()
{
    // Example 1
    Graph g(4);
    g.add_edge(0, 2);
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);

    // g.dfs(0);

    Graph g2(5);
    g2.add_edge(0, 2);
    g2.add_edge(0, 1);
    g2.add_edge(0, 3);
    g2.add_edge(1, 2);
    g2.add_edge(1, 3);
    g2.add_edge(2, 3);
    g2.add_edge(2, 4);
    g2.add_edge(4, 3);

    g2.dfs(0);
    return 0;
}