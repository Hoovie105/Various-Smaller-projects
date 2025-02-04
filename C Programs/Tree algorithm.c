#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} node_t;

node_t *search(node_t *root, int key);
node_t *insert(node_t *root, int key);
node_t *remove_node(node_t *root, int key);
node_t *find_min(node_t *node);
void inorder_traversal(node_t *root);

int main() {
    
  node_t *root = NULL;
  root = insert(root, 8);
  insert(root, 4);
  insert(root, 12);
  insert(root, 2);
  insert(root, 6);
  insert(root, 10);
  insert(root, 14);
  insert(root, 1);
  insert(root, 3);
  insert(root, 5);
  insert(root, 7);
  insert(root, 9);
  insert(root, 11);
  insert(root, 13);
  insert(root, 15);
  inorder_traversal(root);
  printf("\n");
  remove_node(root,8);
  inorder_traversal(root);
}
//times are slower due to the way the keys where inserted.

node_t *search(node_t *root, int key) {
  if (root == NULL || root->key == key) {
    return root;
  }
  if (key < root->key) {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
}

node_t *insert(node_t *root, int key) {
  if (root == NULL) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }
  if (key < root->key) {
    root->left = insert(root->left, key);
  } else if (key > root->key) {
    root->right = insert(root->right, key);
  }
  return root;
}

node_t *remove_node(node_t *root, int key) {
  if (root == NULL) {
    return root;
  }
  if (key < root->key) {
    root->left = remove_node(root->left, key);
  } else if (key > root->key) {
    root->right = remove_node(root->right, key);
  } else {
    if (root->left == NULL) {
      node_t *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node_t *temp = root->left;
      free(root);
      return temp;
    }
    node_t *temp = find_min(root->right);
    root->key = temp->key;
    root->right = remove_node(root->right, temp->key);
  }
  return root;
}
node_t *find_min(node_t *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}
void inorder_traversal(node_t *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->key);
  inorder_traversal(root->right);
}

