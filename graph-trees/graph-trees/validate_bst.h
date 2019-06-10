#pragma once
#include "tree.h"
#include <algorithm>

bool validate_bst(TreeNode* node, int& min, int& max);
bool validate_bst(TreeNode* node)
{
	int min, max;
	return	validate_bst(node, min, max);
}

bool validate_bst(TreeNode* node, int& min, int& max)
{
	min = node->value;
	max = node->value;
	int min_left, min_right, max_left, max_right;
	if (node->left != NULL)
	{
		if (!validate_bst(node->left, min_left, max_left))
		{
			return false;
		}
		if (max_left > node->value)
		{
			return false;
		}
		min = min_left;
	}
	if (node->right != NULL)
	{
		if (!validate_bst(node->right, min_right, max_right))
		{
			return false;
		}
		if (min_right < node->value)
		{
			return false;
		}
		max = max_right;
	}
	return true;
}

