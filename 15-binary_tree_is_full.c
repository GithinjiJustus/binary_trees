#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is full - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If the tree is a leaf */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* If both left and right subtrees are not NULL, recur for both */
    if (tree->left && tree->right)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    /* If reach here, then one child is NULL and other is not, so not full */
    return (0);
}
