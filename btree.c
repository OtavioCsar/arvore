#include "btree.h"

typedef struct _nodeq {
  Node *node;
  struct _nodeq *next;
} NodeQ;

typedef struct _queue {
  NodeQ *head, *tail;
} Queue;

Queue *createQueue() {
  Queue *temp = (Queue *)malloc(sizeof(Queue));
  if (!temp)
    return NULL;
  temp->head = NULL;
  temp->tail = NULL;
  return temp;
}

void eraseQueue(Queue *q) {
  if (q->head && !q->tail)
    free(q);
  if (q->head) {
    while (q->head) {
      NodeQ *aux = q->head;
      q->head = aux->next;
      free(aux);
    }
  }
  free(q);
}

void push(Node *node, Queue *q) {
  if (!q || !node)
    return;
  NodeQ *aux = (NodeQ *)malloc(sizeof(NodeQ));
  aux->node = node;
  aux->next = NULL;
  if (!q->head) {
    q->head = aux;
    q->tail = aux;
    return;
  }
  q->tail->next = aux;
  q->tail = aux;
}

Node *pop(Queue *q) {
  if (!q || !q->head)
    return NULL;
  Node *temp = q->head->node;
  NodeQ *aux = q->head;
  q->head = q->head->next;
  if (!q->head) {
    q->tail = NULL;
  }
  aux->node = NULL;
  free(aux);
  return temp;
}

Node *createNode(char info) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->left = NULL;
  temp->right = NULL;
  temp->father = NULL;
  temp->info = info;

  return temp;
}

void eraseNode(Node *node) {
  node->left = NULL;
  node->right = NULL;
  node->father = NULL;
  free(node);
  node = 0;
}

int insertLeft(Node *son, Node *father) {
  if (!son && !father)
    return 1;
  father->left = son;
  son->father = father;
  return 0;
}

int insertRight(Node *son, Node *father) {
  if (!son && !father)
    return 1;
  father->right = son;
  son->father = father;
  return 0;
}

void walkInOrder(Node *root, void (*fn)(Node *)) {
  if (!root)
    return;
  walkInOrder(root->left, fn);
  fn(root);
  walkInOrder(root->right, fn);
}

void walkPreOrder(Node *root, void (*fn)(Node *)) {
  if (!root)
    return;
  fn(root);
  walkPreOrder(root->left, fn);
  walkPreOrder(root->right, fn);
}

void walkPostOrder(Node *root, void (*fn)(Node *)) {
  if (!root)
    return;
  walkPostOrder(root->left, fn);
  walkPostOrder(root->right, fn);
  fn(root);
}

void searchInLenght(Node *root, void (*fn)(Node *)) {
  Queue *q = createQueue();

  push(root, q);
  while(q->head){
    Node *r = pop(q);
    fn(r);
    if(r->left)
      push(r->left, q);
    if(r->right)
      push(r->right, q);
    
  }
  eraseQueue(q);
}