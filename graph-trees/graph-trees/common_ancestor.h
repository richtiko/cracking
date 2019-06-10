#pragma once
//########################
#include "tree.h"
#include <unordered_set>
TreeNode* get_common_ancestor(TreeNode* node1, TreeNode* node2)
{
	std::unordered_set<TreeNode*> parents;
	TreeNode* tmp = node1;
	while (tmp != NULL)
	{
		parents.insert(tmp);
		tmp = tmp->parent;
	}
	tmp = node2;
	while (tmp != NULL)
	{
		if (parents.find(tmp) != parents.end())
		{
			return tmp;
		}
		tmp = tmp->parent;
	}
	return NULL;
}
struct Result 
{
	TreeNode* node;
	bool  is_ancestor;
	Result():node(NULL), is_ancestor(false){}
	Result(TreeNode*n, bool is) :node(n), is_ancestor(is) {}
};
bool contains(TreeNode* root, TreeNode* node);
Result  get_common_ancestor_from_root(TreeNode* node1, TreeNode* node2, TreeNode* root);
TreeNode* get_common_ancestor(TreeNode* node1, TreeNode* node2, TreeNode* root)
{
	if (contains(node1, node2))
	{
		return node1;
	}
	if (contains(node2, node1))
	{
		return node2;
	}
	Result res = get_common_ancestor_from_root(node1, node2, root);
	if (res.is_ancestor == true)
	{
		return res.node;
	}
	return NULL;
}
Result  get_common_ancestor_from_root(TreeNode* node1, TreeNode* node2, TreeNode* root)
{
	if (node1->value == root->value)
	{
		return Result(node1, false);
	}
	if (node2->value == root->value)
	{
		return Result(node2, false);
	}
	Result res_l;
	if (root->left != NULL)
	{
		res_l = get_common_ancestor_from_root(node1, node2, root->left);
	}
	if (res_l.is_ancestor)
	{
		return res_l;
	}
	Result res_r;
	if (root->right != NULL)
	{
		res_r = get_common_ancestor_from_root(node1, node2, root->right);
	}
	if (res_r.is_ancestor)
	{
		return res_r;
	}
	if (res_r.node != NULL && res_l.node != NULL)
	{
		return Result(root, true);
	}
	return res_r.node != NULL ? res_r : res_l;
}
bool contains(TreeNode* root , TreeNode* node) 
{
	if (root == NULL) 
	{
		return false;
	}
	if (root->value == node->value) 
	{
		return true;
	}
	return contains(root->left, node) || contains(root->right, node);
}


