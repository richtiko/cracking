#pragma once
#include "tree.h"
#include <algorithm>
bool get_balanced_haight(TreeNode* node, int& height);
bool check_balanced(TreeNode* node)
{
	int height;
	return(get_balanced_haight(node, height));
}

bool get_balanced_haight(TreeNode* node, int& height)
{
	int left_h;
	int right_h;
	if (node == NULL)
	{
		height = 0;
		return true;
	}
	if (!get_balanced_haight(node->left, left_h))
	{
		return false;
	}
	if (!get_balanced_haight(node->right, right_h))
	{
		return false;
	}
	height = std::max(right_h, left_h) + 1;
	return abs(right_h - left_h) <= 1;
}
