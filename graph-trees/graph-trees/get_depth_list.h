#pragma once
#include <list>
#include <unordered_map>
#include "tree.h"
typedef std::unordered_map<int, std::list<int>> lists_t;
void get_depth_lists(TreeNode* root, lists_t& result, int depth);
lists_t get_depth_lists(TreeNode* root)
{
	lists_t result;
	get_depth_lists(root, result, 0);
	return result;
}

void get_depth_lists(TreeNode* root, lists_t& result, int depth)
{
	if (root == NULL)
	{
		return;
	}
	result[depth].push_back(root->value);
	get_depth_lists(root->left, result, depth + 1);
	get_depth_lists(root->right, result, depth + 1);
}

void print(const lists_t& lists) 
{
	int i = 0;
	std::cout << std::endl;
	while (true)
	{
		if(lists.find(i) == lists.end())
		{
			return;
		}
		auto& ls = lists.find(i)->second;
		for (auto it = ls.begin() ; it != ls.end(); ++it) 
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		++i;
	}
}