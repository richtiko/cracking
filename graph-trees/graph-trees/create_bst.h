#pragma once
#include <vector>
#include <cmath>
#include "tree.h"
TreeNode* create_BST(std::vector<int> arr, int start, int len);
TreeNode* create_BST(std::vector<int> arr)
{
	return create_BST(arr, 0, arr.size());
}
TreeNode* create_BST(std::vector<int> arr, int start, int len)
{
	if (len == 0)
	{
		return NULL;
	}
	if (len == 1)
	{
		return new TreeNode(arr[start]);
	}
	int root_index = start + std::ceil(len / 2);
	TreeNode* root = new TreeNode(arr[root_index]);
	root->left = create_BST(arr, start, root_index - start);
	root->right = create_BST(arr, root_index + 1, len - (root_index - start + 1));
	return root;
}
