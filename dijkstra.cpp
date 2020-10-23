/*
    shortest path in a weighted graph using Dijkstra algorithm
*/
#include <iostream>
#include <map>
#include <list>
#include <set>
#include <climits>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<pair<T, int>>> adjlist;

public:
    void addEdge(T u, T v, int dist, bool bidir = true)
    {
        adjlist[u].push_back(make_pair(v, dist));
        if (bidir)
            adjlist[v].push_back(make_pair(u, dist));
    }

    void dijkstra(T src)
    {
        map<T, int> dist;

        for (auto j : adjlist)
        {
            dist[j.first] = INT_MAX;
        }

        //set to find a node with min dist
        set<pair<int, T>> s;

        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            //iterate over neighbours of current node
            for (auto childpair : adjlist[node])
            {
                if (nodeDist + childpair.second < dist[childpair.first])
                { // remove old pair and insert new one;

                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end())
                        s.erase(f);

                    dist[dest] = nodeDist + childpair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        //distance to all other nodes from src
        for (auto d : dist)
        {
            cout << d.first << " is located at a distance of " << d.second << endl;
        }
    }

    void print()
    {
        for (auto i : adjlist)
        {
            cout << i.first << "->";

            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ")";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph<string> g;
    g.addEdge("Amritsar", "Delhi", 1);
    g.addEdge("Amritsar", "Jaipur", 4);
    g.addEdge("Jaipur", "Delhi", 2);
    g.addEdge("Jaipur", "Mumbai", 8);
    g.addEdge("Bhopal", "Agra", 2);
    g.addEdge("Mumbai", "Bhopal", 3);
    g.addEdge("Agra", "Delhi", 1);
    g.dijkstra("Amritsar");

    /*
    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    g.print();
    g.dijkstra(1); */
}
