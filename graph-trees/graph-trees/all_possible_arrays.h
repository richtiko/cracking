#pragma once
#include "tree.h"
#include <list>
typedef std::list<std::list<int>> result_t;
void weave(std::list<int>& l1, std::list<int>::iterator it1, std::list<int>& l2, std::list<int>::iterator it2, std::list<int> prefix, result_t& res);
void print(const result_t& res);
result_t  get_possible_arrays_list(TreeNode* root);
result_t  merge(result_t& res1, result_t& res2);
void weave(std::list<int>& l1, std::list<int>::iterator it1, std::list<int>& l2, std::list<int>::iterator it2, std::list<int> prefix, result_t& res);



void get_possible_arrays(TreeNode* node)
{
	result_t res = get_possible_arrays_list(node);
	print(res);
}
void print(const result_t& res)
{
	for (auto it = res.begin(); it != res.end(); ++it)
	{
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
		{
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
}
result_t  get_possible_arrays_list(TreeNode* root)
{
	if (root == NULL)
	{
		return result_t();
	}
	result_t right = get_possible_arrays_list(root->right);
	result_t left = get_possible_arrays_list(root->left);
	result_t res = merge(right, left);
	for (auto it = res.begin(); it != res.end(); ++it)
	{
		it->push_front(root->value);
	}
	if (res.empty()) 
	{
		std::list<int> tmp;
		tmp.push_back(root->value);
		res.push_back(tmp);
	}
	return res;
}
result_t  merge(result_t& res1, result_t& res2)
{
	result_t  res;
	for (auto it = res1.begin(); it != res1.end(); ++it)
	{
		for (auto it2 = res2.begin(); it2 != res2.end(); ++it2)
		{
			std::list<int> prefix;
			weave(*it, it->begin(), *it2, it2->begin(), prefix, res);
		}
	}
	return res;
}

void weave(std::list<int>& l1, std::list<int>::iterator it1, std::list<int>& l2, std::list<int>::iterator it2, std::list<int> prefix, result_t& res)
{
	if (it1 == l1.end())
	{
		prefix.insert(prefix.end(), it2, l2.end());
		res.push_back(prefix);
		return;
	}
	if (it2 == l2.end())
	{
		prefix.insert(prefix.end(), it1, l1.end());
		res.push_back(prefix);
		return;
	}
	prefix.push_back(*it1);
	++it1;
	weave(l1, it1, l2, it2, prefix, res);
	--it1;
	prefix.pop_back();

	prefix.push_back(*it2);
	++it2;
	weave(l1, it1, l2, it2, prefix, res);
	return;
}

