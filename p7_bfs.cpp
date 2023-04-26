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

    void bfs(int s)
    {
        queue<int> my_queue;
        my_queue.push(s);

        bool visited[n] = {false};
        visited[s] = true;

        int parent[n] = {-1};
        int curr;

        cout << "BFS Traversal -> ";
        while (!my_queue.empty())
        {
            curr = my_queue.front();
            cout << curr << " ";

            visited[curr] = true;
            my_queue.pop();

            // add unvisited children to queue and mark them visited
            for (auto &child : adj_matrix[curr])
            {
                if (!visited[child])
                {
                    my_queue.push(child);
                    parent[child] = curr;
                    visited[child] = true;
                }
            }
        }

        cout << endl;
        cout << "BFS tree (parent -> child)" << endl;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] != -1)
                cout << parent[i] << " -> " << i << endl;
        }
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

    // g.bfs(0);

    Graph g2(5);
    g2.add_edge(0, 2);
    g2.add_edge(0, 1);
    g2.add_edge(0, 3);
    g2.add_edge(1, 2);
    g2.add_edge(1, 3);
    g2.add_edge(2, 3);
    g2.add_edge(2, 4);
    g2.add_edge(4, 3);

    g2.bfs(0);
    return 0;
}