#include <iostream>
using namespace std;

// to maintain and union disjoint sets
// for connected components
class UnionFind
{
    int n;
    int *parent; // disjoint sets

public:
    UnionFind(int n)
    {
        this->n = n;
        parent = new int[n];

        // initially all are separate disjoint sets of single elements
        // parent[i] = i means set/component name
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (u == parent[u])
            return u;
        return find(parent[u]);
    }

    void union_sets(int a, int b)
    {
        int set_a = find(a);
        int set_b = find(b);

        // parent of set_a to set_b
        parent[set_a] = set_b;
    }
};

// edge construct - undirected
class Edge
{
public:
    int u, v, wt;
};

bool edge_comparator(Edge x, Edge y)
{
    return x.wt < y.wt;
}

// based on edge list
class Graph
{
    int n, e;
    Edge *edge_list;

public:
    Graph(int n, int e)
    {
        this->n = n;
        this->e = e;
        edge_list = new Edge[e];
    }

    ~Graph()
    {
        delete edge_list;
    }

    void input_weights()
    {
        cout << "Enter the edges and their weight (u, v, w)" << endl;
        for (int i = 0; i < e; i++)
            cin >> edge_list[i].u >> edge_list[i].v >> edge_list[i].wt;
    }

    void display()
    {
        for (int i = 0; i < e; i++)
            cout << edge_list[i].u << " " << edge_list[i].v << " " << edge_list[i].wt << endl;
    }
};

int main()
{
    int n, e;
    cout << "Enter #vertices and #edges : ";
    cin >> n >> e;
    Graph g(n, e);
    g.input_weights();
    g.display();
    return 0;
}

// https://www.interviewbit.com/blog/wp-content/uploads/2021/10/Image-4-1.jpg
// a(0) b(1) c(2) d(3) e(4) f(5)

/*
6 9
0 1 2
0 2 4
1 2 2
1 3 4
1 4 2
2 4 3
4 5 2
3 5 2
3 4 3

*/
