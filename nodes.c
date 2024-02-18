#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodes.h"

void freeTree(bNode * head){
  if (head) {
    freeTree(head -> left);
    freeTree(head -> right);
    free(head);
  }
}

int isLeaf(bNode * n){
    if (n -> left || n -> right){
        return 0;
    }
    else{
        return 1;
    }
}

void _printErr(char * str, char * file, int line){
  fprintf(stderr, "%s %s %d\n", str, file, line);
}