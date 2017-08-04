#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph
{
  public:
	typedef unsigned int IndexType;
	typedef set<IndexType> NodeType;

  protected:
	IndexType vertexNumber;
	NodeType *connections;
	//edge list?
  public:
	Graph(IndexType Vertexes) : vertexNumber(Vertexes)
	{
		connections = new NodeType[vertexNumber];
	}
	~Graph()
	{
		delete[] connections;
	}
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

int main()
{
	//fill the Graph
	Graph::IndexType vert = 0;
	cin >> vert;
	Graph tree(vert);
	vector<pair<Graph::IndexType, Graph::IndexType>> edgeList;
	edgeList.reserve(vert - 1);
	while (--vert)
	{
		Graph::IndexType u, v;
		cin >> u >> v;
		--u, --v;
		tree.addEdge(u, v);
		edgeList.emplace_back(u, v);
	}

	//run byEdge searches separatedly
	// TODO this is a draft method, not good

	unsigned int maxLength = 0;

	for (auto e : edgeList)
	{
		unsigned int l1, l2, l;
		tree.checkTwoBFSByEdge(e.first, e.second, l1, l2);
		l = l1 + l2 + 1;
		if (l > maxLength)
			maxLength = l;
	}
	cout << maxLength << endl;

	return 0;
}

// # Agorithm Plan
//
// f1(): get (sub)tree's longest path
// run f1() by edge selection (<= needs optimalization!)
// what is the two max diametered subtrees by edge runs?
// put the selected edge to the end points ot the two max diametered subtree
