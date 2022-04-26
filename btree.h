#ifndef __BTREE_H
#define __BTREE_H
#include <stdlib.h>

typedef struct _node {
  char info;
  struct _node *left, *right, *father;
} Node;

Node *createNode(char info);

void eraseNode(Node *no);

int insertRight(Node *son, Node *father);

int insertLeft(Node *son, Node *father);

void walkPreOrder(Node *root, void (*fn)(Node *));

void walkInOrder(Node *root, void (*fn)(Node *));

void walkPostOrder(Node *root, void (*fn)(Node *));

void searchInLenght(Node *root, void (*fn)(Node *));

void removeNode(Node *node, Node *root);

#endif //__BTREE_H