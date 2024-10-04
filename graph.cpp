#include <iostream>
using namespace std;

int main()
{
    int vertex, edges;

    cin >> vertex >> edges;
    bool adj[vertex][vertex]; // Declare the adjacency matrix as a 2D array

    // Initialize the adjacency matrix to false
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            adj[i][j] = false;
        }
    }

    int u, v;
    for (int i = 0; i < edges; i++)
    {

        cin >> u >> v;
        adj[u][v] = true; // Set the edge from u to v
        adj[v][u] = true; // Set the edge from v to u (undirected)
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
