#pragma once
#include <unordered_map>
#include <string>
class Graph
{
public:
	struct Node;
	typedef std::unordered_map<std::string, Node*> nodes_t;
	typedef std::list<Node*> nodes_list_t;
	struct Node
	{
		Node(std::string name) :name(name), visited(false) {}
		nodes_list_t adj;
		std::string name;
		bool visited;
	};
	nodes_t nodes;
	void reset() 
	{
		for (auto it = nodes.begin(); it != nodes.end(); ++it) 
		{
			it->second->visited = false;
		}
	}
};
typedef Graph::Node Node;