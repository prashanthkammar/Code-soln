//Depth first search algorithm

#include <iostream>
#include <list>
using namespace std;

class Graph
{
    list<int> *adjList;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFS_util(int v, bool *visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (auto node : adjList[v])
            if (!visited[node])
                DFS_util(node, visited);
    }

    void DFS(int v) //connected
    {
        bool *visited = new bool[V]{false};
        DFS_util(v, visited);
    }

    void DFS() //disconnected graph
    {
        bool *visited = new bool[V]{false};

        cout << endl;
        for (int i = 0; i < V; i++)
            if (!visited[i])
                DFS_util(i, visited);
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);
}