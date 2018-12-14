#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "treeStructure.h"
#include "tree.h"
#include "print.h"

void destroyTree(Node *node)
{
  int i;
  if(node->child[0] == NULL){
    return;
  }
  else{
     for(i = 0;i < 4;i++)
     {
        destroyTree(node->child[i]);
        free(node->child[i]);
        node->child[i] = NULL;
     }
  }
}

int main( int argc, char **argv ) {

  Node *head;
  head = makeNode( 0.0,0.0, 0 );

  // a full tree at Level 2.
  growtree(head);
  growtree(head);

  //a non-uniform tree that you define.
  growtree(head);
  makeChildren( head->child[0]);
  makeChildren( head->child[1]);

  //frees memory for all tree nodes.
  destroyTree(head);
  free(head);
  head = NULL;

  writeTree( head );

}






























