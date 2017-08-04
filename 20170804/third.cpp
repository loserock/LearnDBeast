#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class SimpleTree
{
  protected:
    using Node = unsigned int;
    using Neighbours = vector<Node>;
    struct InDistance
    {
        unsigned int distance;
        Neighbours nodes;
    };

    size_t _numberOfNodes;
    map<Node, Neighbours> _tree;
    map<Node, InDistance> _farests;

  public:
    SimpleTree(size_t N) : _numberOfNodes(N){};
    void AddEdge(Node i, Node j)
    {
        _tree[i].push_back(j);
        _tree[j].push_back(i);
    }
    InDistance GetFarestFrom(Node i)
    {
        auto it = _farests.find(i);
        if (it != _farests.end())
            return it->second;
        // TODO seek and cash the result, and return with it
        // can be useful: http://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
