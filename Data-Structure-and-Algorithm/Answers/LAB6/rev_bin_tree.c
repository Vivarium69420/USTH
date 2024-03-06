/*
 * RULES:
 *    1. Create a complete bintree with all leaves at one level
 *       height = cell(log2(n)+1)
 *       Each empty leave store an element E > any element
 *    2. Starting from the bottem, each node is the min of its 2 childrens
 *       so that the node is the min of all nodes
 *    3. If a leaf node is removed, replaced by a new node with parent value
 *    4. If a node is added, it will be the leaf node (verify validity after
 *       modification)
 * FUNCTIONS:
 *    1. Init an array with n random values
 *    2. Build a complete binary tree
 *    3. Display tree info
 *    4. Search an input value using recursion
 *    5. Insert and remove a node
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int val;
  struct TreeNode *parent;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode_t;

TreeNode_t *init_node(TreeNode_t *parent, int val) {
  TreeNode_t *node = malloc(sizeof(TreeNode_t));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  node->parent = parent;
  return node;
}

TreeNode_t *create_empty_bin_tree(TreeNode_t *node, int depth) {
  if (depth == 0) {
    return node;
  }
  if (node->left == NULL) {
    node->left = init_node(node, 0);
  }
  if (node->right == NULL) {
    node->right = init_node(node, 0);
  }
  create_empty_bin_tree(node->left, depth - 1);
  create_empty_bin_tree(node->right, depth - 1);
  return node;
}

TreeNode_t *assign_leave(TreeNode_t *node, int arr[], int size, int *index,
                         int max) {
  if (node == NULL) {
    return node;
  }
  assign_leave(node->left, arr, size, index, max);
  assign_leave(node->right, arr, size, index, max);

  // Check if the node is a leaf node
  if (node->left == NULL && node->right == NULL) {
    if (*index < size) {
      node->val = arr[*index];
      (*index)++;
    } else {
      node->val = max;
    }
  }
  return node;
}

TreeNode_t *assign_parent_value(TreeNode_t *node) {
  if (node == NULL) {
    return node;
  }
  assign_parent_value(node->left);
  assign_parent_value(node->right);
  if (node->left != NULL && node->right != NULL) {
    node->val = (node->left->val < node->right->val) ? node->left->val
                                                     : node->right->val;
  }
  return node;
}

void print_tree(TreeNode_t *node, int depth) {
  if (node == NULL) {
    return;
  }
  print_tree(node->right, depth + 1);
  for (int i = 0; i < depth; i++) {
    printf("  ");
  }
  printf("%d", node->val);
  printf("\n");
  print_tree(node->left, depth + 1);
}

int main() {
  TreeNode_t *node = init_node(NULL, 0);
  int max = 42;
  int arr[] = {8, 20, 41, 7, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  int index = 0;

  node = create_empty_bin_tree(node, 3);
  assign_leave(node, arr, size, &index, max);
  assign_parent_value(node);
  print_tree(node, 0);
}
