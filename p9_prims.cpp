#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// based on adj matrix
class Graph
{
    int n;
    int **adj_matrix;

public:
    Graph(int n)
    {
        this->n = n;
        adj_matrix = new int *[n];
        for (int i = 0; i < n; i++)
            adj_matrix[i] = new int[n];
    }

    ~Graph()
    {
        delete adj_matrix;
    }

    void input_weights()
    {
        cout << "Enter the edge weight / adjacency matrix" << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> adj_matrix[i][j];
    }

    int select_min_edge_len(vector<int> edge_length, vector<bool> processed)
    {

        int edge = -1;
        int weight = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!processed[i] && edge_length[i] < weight)
            {
                edge = i;
                weight = edge_length[i];
            }
        }
        return edge;
    }

    void prims()
    {
        vector<int> edge_length(n, INT_MAX);
        edge_length[0] = 0;

        vector<bool> processed(n, false);
        int parent[n] = {-1}; // for mst

        // span n-1 vertices
        int curr;
        for (int i = 0; i < n - 1; i++)
        {
            curr = select_min_edge_len(edge_length, processed);
            processed[curr] = true;

            // relax the neighbors
            // greedy param : adj_matrix[i][neighbor] <= edge_length[neighbor]
            for (int neighbor = 0; neighbor < n; neighbor++)
            {
                if (adj_matrix[curr][neighbor] && !processed[neighbor] && adj_matrix[curr][neighbor] <= edge_length[neighbor])
                {
                    parent[neighbor] = curr;
                    edge_length[neighbor] = adj_matrix[curr][neighbor];
                }
            }
        }

        cout << "\nMST edges nodeA -> nodeB" << endl;
        int cost = 0;
        for (int i = 1; i < n; i++)
        {
            cout << parent[i] << " -> " << i << endl;
            cost += edge_length[i];
        }
        cout << "COST to build it : " << cost << endl;
    }
};

int main()
{
    int n;
    cout << "Enter #vertices : ";
    cin >> n;
    Graph g(n);
    g.input_weights();
    g.prims();
    return 0;
}

// https://www.interviewbit.com/blog/wp-content/uploads/2021/10/Image-4-1.jpg
// a(0) b(1) c(2) d(3) e(4) f(5)

/*

6
0 2 4 0 0 0
2 0 2 4 2 0
4 2 0 0 3 0
0 4 0 0 3 2
0 2 3 3 0 2
0 0 0 2 2 0

*/