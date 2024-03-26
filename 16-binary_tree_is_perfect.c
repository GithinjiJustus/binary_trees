#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is perfect - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height, size, pow;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	size = binary_tree_size(tree);

	if (size == 1)
		return (1);

	if (left_height >= 0 && right_height >= 0 && left_height == right_height)
	{
		pow = get_power(left_height + 1);

		if (pow - 1 == size)
			return (1);
	}

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree.
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL)
		return (0);

	count = binary_tree_size(tree->left) + 1;
	count += binary_tree_size(tree->right);

	return (count);
}

/**
 * get_power - Computes the power of 2 for a given exponent.
 * @exp: The exponent.
 *
 * Return: The power of 2 for the given exponent.
 */
int get_power(int exp)
{
	int pow, i;

	for (i = 0, pow = 1; i <= exp; i++)
		pow *= 2;

	return (pow);
}
