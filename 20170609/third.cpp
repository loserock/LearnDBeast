#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

//#define DEBUG

class Graph
{
  public:
    using IndexType = unsigned int;
    using NodeType = set<IndexType>;
    using AdjMLineType = uint32_t;
    // using AdjMLineType = vector<bool>;
    using AdjMatrix = vector<AdjMLineType>;

  protected:
    IndexType vertexNumber;
    NodeType *connections;
    static const IndexType MAXVERTEXNUMBER = 8 * sizeof(AdjMLineType);
    //edge list?

  public:
    Graph(IndexType Vertexes) : vertexNumber(Vertexes)
    {
        if (Vertexes > MAXVERTEXNUMBER)
        {
            cerr << "Invalid vertex number: " << Vertexes << " > " << MAXVERTEXNUMBER << endl;
        }
        connections = new NodeType[vertexNumber];
    }
    ~Graph()
    {
        delete[] connections;
    }

    IndexType inline getVertexNumber() { return vertexNumber; }

    void addEdge(IndexType u, IndexType v)
    {
        // connections[u].push_back(v);
        // connections[v].push_back(u);
        connections[u].insert(v);
        connections[v].insert(u);
    }

    NodeType &getLinks(IndexType u)
    {
        return connections[u];
    }

    void removeEdge(IndexType u, IndexType v)
    {
        connections[u].erase(v);
        connections[v].erase(u);
    }

    AdjMatrix getAdjacencyMatrix()
    {
        AdjMatrix am(vertexNumber, 0);
        auto connectWith = [](AdjMLineType& l, IndexType i) -> void { l |= 1<<i; };
        // auto connectWith = [](AdjMLineType& l, IndexType i) -> void { l[i] = true; };

        for (IndexType i = 0; i < vertexNumber; ++i)
        {
            for (const auto j : connections[i])
            {
                connectWith(am[i], j);
                connectWith(am[j], i);
            }
        }
        return am;
    }

    IndexType BFS(IndexType root, unsigned int &length)
    {
        unordered_set<IndexType> visited;
        deque<IndexType> q;
        visited.insert(root);
        q.push_back(root);
        IndexType s = root;
        length = 0;
        while (!q.empty())
        {
            s = q.front();
            if (s != root)
                ++length;
            q.pop_front();
            for (auto i = connections[s].begin(); i != connections[s].end(); advance(i, 1))
            {
                if (visited.find(*i) == visited.end())
                {
                    visited.insert(*i);
                    q.push_back(*i);
                }
            }
        }
        return s;
    }
    unsigned int getDiameter(IndexType u = 0)
    {
        unsigned int diameter = 0;
        u = BFS(u, diameter);
        BFS(u, diameter);
        return diameter;
    }
    void checkTwoBFSByEdge(IndexType u, IndexType v, unsigned int &lengthOne, unsigned int &lengthTwo)
    {
        removeEdge(u, v);
        lengthOne = getDiameter(u);
        lengthTwo = getDiameter(v);
        addEdge(u, v);
    }
};

long long getNonIsomorphicNumber(Graph &G)
{
    long long result = G.getVertexNumber();

    if (result < 5)
        return result;

    // TODO

    return result;
}

int main()
{
    int n;
    cin >> n;
    Graph mainGraph(n);
    for (int a0 = 0; a0 < n - 1; a0++)
    {
        int u;
        int v;
        cin >> u >> v;
        mainGraph.addEdge(u - 1, v - 1);
    }

#ifdef DEBUG
    {
        Graph::AdjMatrix am = mainGraph.getAdjacencyMatrix();
        stringstream _ss;
        copy(am.begin(), am.end(), ostream_iterator<Graph::AdjMLineType>(_ss, " "));
        cout << "#adj matrix: " << _ss.str() << endl;
    }
#endif

    long long result = getNonIsomorphicNumber(mainGraph);
    cout << result << endl;

    return 0;
}
