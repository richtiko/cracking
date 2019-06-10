#pragma once
#include "graph.h"
#include <iostream>
void dfs_visit(Node* node, std::list<std::string>& result);
void get_order(Graph& graph)
{
	std::list<std::string> result;
	for (auto it = graph.nodes.begin(); it != graph.nodes.end(); ++it)
	{
		dfs_visit(it->second, result);
	}
	for (auto it = result.rbegin(); it != result.rend(); ++it)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

}
void dfs_visit(Node* node, std::list<std::string>& result)
{
	if (node->visited)
	{
		return;
	}
	for (auto it = node->adj.begin(); it != node->adj.end(); ++it)
	{
		dfs_visit(*it, result);
	}
	node->visited = true;
	result.push_back(node->name);
}

