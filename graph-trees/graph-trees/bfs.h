#pragma once
#include <string>
#include <queue>
#include "graph.h"
#include <stdexcept>
bool is_path_present(const std::string& node1, const std::string& node2, Graph& graph)
{
	std::queue<Graph::Node*> queue;
	if (graph.nodes.find(node1) == graph.nodes.end())
	{
		throw std::runtime_error("node " + node1 + " is not found in graph");
	}
	Graph::Node* root = graph.nodes.find(node1)->second;
	queue.push(root);
	while (!queue.empty())
	{
		Graph::Node* node = queue.front();
		queue.pop();
		if (node->name == node2)
		{
			return true;
		}
		for (auto it = node->adj.begin(); it != node->adj.end(); ++it)
		{
			if ((*it)->name == node2)
			{
				return true;
			}
			if ((*it)->visited == false)
			{
				queue.push(*it);
			}
		}
	}
}
