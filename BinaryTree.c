#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

static int idx = -1;

Node *createNode(int val)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *buildTree(int preOrder[], int size)
{
  idx++;
  if (idx >= size || preOrder[idx] == -1)
  {
    return NULL;
  }
  Node *root = createNode(preOrder[idx]);
  root->left = buildTree(preOrder, size);
  root->right = buildTree(preOrder, size);

  return root;
}

void printPreOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  printf("%d", root->data);
  printPreOrder(root->left);
  printPreOrder(root->right);
}

void printInOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  printInOrder(root->left);
  printf("%d", root->data);
  printInOrder(root->right);
}

void printPostOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  printPostOrder(root->left);
  printPostOrder(root->right);
  printf("%d", root->data);
}

int main()
{
  int preOrder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  int size = sizeof(preOrder) / sizeof(preOrder[0]);

  Node *root = buildTree(preOrder, size);
  printPreOrder(root);
  printf("\n");

  printInOrder(root);
  printf("\n");

  printPostOrder(root);
  printf("\n");
}