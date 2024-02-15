
#include "packing.h"
#include <stdio.h>
#include <stdlib.h>
#define printErr(str) \
  _printErr(str, __FILE__, __LINE__)


bNode * loadTree(char * filename){
  FILE * f = fopen(filename, "r");
  char ** arr = NULL;
  if (!arr){
    fclose(f);
    return NULL;
  }
  char ** tempArr = NULL;
  char * str = malloc(sizeof(char) * 7);
  int size = 0;
  while (fgets(str, sizeof(str), f) != NULL){
    fprintf(stderr, "%s", str);
    tempArr = realloc(arr, sizeof(str) * (size + 1));
    if (!tempArr){
      free(arr);
      free(str);
      fclose(f);
      return NULL;
    }
    arr = tempArr;

    arr[size] = str;
    size++;
  }
  // bNode * head;
  free(arr);
  free(str);
  fclose(f);
  return NULL;
  // return head;
}

bNode * parsePR(char ** arr){
  bNode * head;
  return head;
}

void freeTree(bNode * head){
  if (head != NULL) {
    freeTree(head -> left);
    freeTree(head -> right);
    free(head);
  }
}



void _printErr(char * str, char * file, int line){
  fprintf("stderr", "%s %s %d\n", str, file, line);
}
