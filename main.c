#include "btree.h"
#include <stdio.h>

void visit(Node* node){
  printf("%c",node->info);
}

int main(void) {

  Node *one = createNode('+');
  Node *two = createNode('*');
  Node *three = createNode('*');
  Node *four = createNode('a');
  Node *five = createNode('b');
  Node *six = createNode('c');
  Node *seven = createNode('+');
  Node *eight = createNode('d');
  Node *nine = createNode('e');

  int err = insertLeft(two, one);
  err = insertRight(three, one);
  err = insertLeft(four, two);
  err = insertRight(five, two);
  err = insertLeft(six, three);
  err = insertRight(seven, three);
  err = insertLeft(eight, seven);
  err = insertRight(nine, seven);

  walkInOrder(one, &visit);
  printf("\n\n");

  walkPreOrder(one, &visit);
  printf("\n\n");

  walkPostOrder(one, &visit);
  printf("\n\n");

  searchInLenght(one, &visit);
  printf("\n\n");
}