#include <iostream>
using namespace std;
struct tree_node
{
	int f;
	struct tree_node *left;
	struct tree_node *right;
};
void tree_cout(tree_node *tree)
{
	if (tree != NULL)
	{
		tree_cout(tree->left);
		cout << tree->f << " ";
		tree_cout(tree->right);
	}
}
struct tree_node *add(int x, tree_node *tree)
{
	if (tree == NULL)
	{
		tree = new tree_node;
		tree->f = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (x > tree->f)
		tree->left = add(x, tree->left);
	else
		tree->right = add(x, tree->right);
	return (tree);
}
void delete_tree(tree_node *tree)
{
	if (tree != NULL)
	{
		delete_tree(tree->left);
		delete_tree(tree->right);
		delete tree;
	}
}
int main()
{
	struct tree_node *root = NULL;
	setlocale(LC_ALL, " ");
	int a, n;
	cout << "Введите количество элементов дерева n=";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a = rand() % 20 - 10;
		cout << "Элемент " << i + 1 << ": " << a << endl;
		root = add(a, root);
	}
	tree_cout(root);
	delete_tree(root);
	return 0;
}