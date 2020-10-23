//Breadth first search algorithm

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *adjList;

public:
    Graph(int v) : V(v)
    {
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i;

            for (auto j : adjList[i])
                cout << "->" << j;
            cout << endl;
        }
    }

    void bfs(int src)
    {
        queue<int> q;
        bool *visited = new bool[V]{false};

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (auto neighbour : adjList[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
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

    g.bfs(2);
}
