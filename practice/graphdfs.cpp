/* Graph depth first search :
 * Given a set of vertices, construct a graph and implement a depth-first search algorithm on it.
 * $Author: Kalyan Subramanain
 * $Date$: Sep 4, 2014
 * $email$: kalyan dot sub at gmail dot com
 */

#include <iostream>
#include <list>
#include <cassert>
using std::list;
using std::cout;

class Graph
{
    public:
        Graph(int numV); // c'tor takes number of vertices
        void addEdge(int v, int w); // adds an edge to graph
        void dfs(); // Depth first search of vertices reachable from v

    private:
        Graph(const Graph& gref); // disallow copy c'tor
        Graph& operator=(const Graph& gref); // disallow assignment operator

        int m_numV;
        list<int> *adj; // pointer to array containing adjacency lists
        void dfsUtil(int v, bool visited[]); // A helper fn. used by DFS
};

Graph::Graph(int numV): m_numV(numV), adj(new list<int>[numV])
{
}

void Graph::addEdge(int v, int w)
{
    assert (adj != NULL);
    adj[v].push_back(w); // Add vertex w to the vertex v's adjacency list
}

void Graph::dfsUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])
        {
            dfsUtil(*i, visited);
        }
    }
}

void Graph::dfs()
{
    bool *visited = new bool[m_numV];
    assert(visited != NULL);
    
    // Mark all the vertices as not visited
    for(int i = 0; i < m_numV; i++)
    {
        visited[i] = false;
    }
    // Call the recursive helper function to print DFS traversal
    // starting at each vertex
    for(int i = 0; i < m_numV; i++)
    {
        if(visited[i] == false)
        {
            dfsUtil(i, visited);
        }
    }
}

int main(int argc, char* argv[])
{
    Graph g(4); //create a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.dfs();

}

