#pragma once
#include <iostream>
struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	
	TreeNode(int val) :value(val), left(NULL), right(NULL), parent(NULL){}

	TreeNode* add_left(int val)
	{
		this->left = new TreeNode(val);
		this->left->parent = this;
		return this->left;
	}

	TreeNode* add_right(int val)
	{
		this->right = new TreeNode(val);
		this->right->parent = this;
		return this->right;
	}

	TreeNode* find(int val)
	{
		TreeNode* node = this;
		while (node != NULL) 
		{
			if (node->value == val) 
			{
				return node;
			}
			if (node->value > val) 
			{
				node = node->left;
			}
			else 
			{
				node = node->right;
			}
		}
		return node;
	}

};

void print(TreeNode* root)
{
	if (root == NULL) 
	{
		std::cout << " null ";
	}
	else 
	{
		std::cout << root->value<<" ";
		print(root->left);
		print(root->right);
	}
}