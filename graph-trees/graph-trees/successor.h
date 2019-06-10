#pragma once
#include "tree.h"
TreeNode* get_min(TreeNode* root);

TreeNode* get_successor(TreeNode* node)
{
	if (node->right != NULL)
	{
		return get_min(node->right);
	}
	else
	{
		while (node->parent != NULL && node->parent->left != node)
		{
			node = node->parent;
		}
		return node->parent;
	}
}

TreeNode* get_min(TreeNode* root)
{

	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

