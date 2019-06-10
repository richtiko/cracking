//########################
#include "graph.h"
#include "bfs.h"
#include <iostream>
#include "tree.h"
#include "create_bst.h"
#include "get_depth_list.h"
#include "check_balanced.h"
#include "validate_bst.h"
#include "successor.h"
#include "order.h"
#include "common_ancestor.h"
#include "all_possible_arrays.h"
/*int main() 
{
	Graph graph;
	graph.nodes.insert(Graph::nodes_t::value_type("a", new Node("a")));
	graph.nodes.insert(Graph::nodes_t::value_type("b", new Node("b")));
	graph.nodes.insert(Graph::nodes_t::value_type("c", new Node("c")));
	graph.nodes.insert(Graph::nodes_t::value_type("d", new Node("d")));
	graph.nodes.insert(Graph::nodes_t::value_type("e", new Node("e")));
	graph.nodes.insert(Graph::nodes_t::value_type("f", new Node("f")));
	graph.nodes.insert(Graph::nodes_t::value_type("g", new Node("g")));
	graph.nodes["a"]->adj.push_back(graph.nodes["b"]);
	graph.nodes["b"]->adj.push_back(graph.nodes["c"]);
	graph.nodes["b"]->adj.push_back(graph.nodes["d"]);
	graph.nodes["b"]->adj.push_back(graph.nodes["e"]);
	graph.nodes["d"]->adj.push_back(graph.nodes["c"]);
	graph.nodes["f"]->adj.push_back(graph.nodes["d"]);

	std::cout << is_path_present("a", "c", graph) << std::endl;
	graph.reset();
	std::cout << is_path_present("a", "f", graph) << std::endl;

	std::cout << "-------------order-----------" << std::endl;
	graph.reset();
	get_order(graph);
	return 0;
}*/

int main()
{
	/*std::vector<int> arr;
	int ar[] = { 1,2,3,4,5,6,7,8 };
	arr.insert(arr.end(), ar, ar + 8);

	TreeNode* root= create_BST(arr);
	print(root);

	print(get_depth_lists(root));
	
	std::cout <<"------------------------" << std::endl;
	std::cout<<check_balanced(root)<<std::endl;

	std::cout << "-----------validate-------------" << std::endl;
	std::cout << validate_bst(root) << std::endl;

	root->right->right->value = 0;
	std::cout << "-------------validate-----------" << std::endl;
	std::cout << validate_bst(root) << std::endl;

	std::cout << "-------------successor-----------" << std::endl;

	TreeNode* root2 = new TreeNode(5);
	root2->add_left(4)->add_left(2)->add_left(1);
	root2->left->left->add_right(3);

	root2->add_right(10)->add_right(12)->add_right(13)->parent->add_left(11);
	root2->right->add_left(9)->add_left(8);
	std::cout << "valid = "<<validate_bst(root2) << std::endl;

	std::cout << get_successor(root2->left)->value << std::endl;
	std::cout << get_successor(root2->left->left->right)->value << std::endl;
	std::cout << get_successor(root2->right->right->right) << std::endl;
	std::cout << get_successor(root2)->value << std::endl;

	std::cout << "-------------common ancestor-----------" << std::endl;
	std::cout << get_common_ancestor(root2->find(13), root2->find(4))->value << std::endl;
	std::cout << get_common_ancestor(root2->find(13), root2->find(4), root2)->value << std::endl;
	std::cout << get_common_ancestor(root2->find(3), root2->find(4), root2)->value << std::endl;
	std::cout << get_common_ancestor(root2->find(3), new TreeNode(6), root2)<< std::endl;
	*/

	TreeNode* root3 = new TreeNode(4);
	root3->add_left(2)->add_left(1)->parent->add_right(3);
	root3->add_right(5);
	std::cout << "valid = " << validate_bst(root3) << std::endl;

	get_possible_arrays(root3);

	return 0;
}