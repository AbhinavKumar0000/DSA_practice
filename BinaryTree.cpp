#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

static int idx = -1;

Node *createNode(int val)
{
  Node *newNode = new Node();
  newNode->data = val;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

Node *buildTree(int preOrder[], int size)
{
  idx++;
  if (idx >= size || preOrder[idx] == -1)
  {
    return nullptr;
  }
  Node *root = createNode(preOrder[idx]);
  root->left = buildTree(preOrder, size);
  root->right = buildTree(preOrder, size);

  return root;
}

void printPreOrder(Node *root)
{
  if (root == nullptr)
  {
    return;
  }

  cout << root->data;
  printPreOrder(root->left);
  printPreOrder(root->right);
}

void printInOrder(Node *root)
{
  if (root == nullptr)
  {
    return;
  }

  printInOrder(root->left);
  cout << root->data;
  printInOrder(root->right);
}

void printPostOrder(Node *root)
{
  if (root == nullptr)
  {
    return;
  }

  printPostOrder(root->left);
  printPostOrder(root->right);
  cout << root->data;
}

int main()
{
  int preOrder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  int size = sizeof(preOrder) / sizeof(preOrder[0]);

  Node *root = buildTree(preOrder, size);
  printPreOrder(root);
  cout << endl;

  printInOrder(root);
  cout << endl;

  printPostOrder(root);
  cout << endl;

  return 0;
}