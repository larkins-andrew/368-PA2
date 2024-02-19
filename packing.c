#include "nodes.h"
#include "packing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define printErr(str) \
  _printErr(str, __FILE__, __LINE__)


static bNode * parsePR(FILE * f);
static char * getStr(FILE * f);
static void poRecur(FILE * f, bNode * n);
static int getHeight(bNode * n);
static int getWidth(bNode * n);
static void PCKrecur(FILE * f, bNode * n, int dim[2]);

bNode * loadPR(char * filename){
  FILE * f = fopen(filename, "r");
  return parsePR(f);
}

static char * getStr(FILE * f){
  long start = ftell(f);
  if (start == -1L){
    return NULL;
  }
  char c;
  int len = 0;
  c = fgetc(f);
  while(c != EOF && c != '\n'){
    len += 1;
    c = fgetc(f);
  }
  if (len == 0 || c == EOF){
    return NULL;
  }
  if (fseek(f, start, SEEK_SET) != 0){
    return NULL;
  }
  char * str = malloc(len + 1);
  if (!str){
    return NULL;
  }
  for (int i = 0; i < len; i++){
    str[i] = fgetc(f);
  }
  str[len] = '\0';
  fgetc(f);
  return str;
}

static bNode * parsePR(FILE * f){
  char * str = getStr(f);
  if (!str){
    return NULL;
  }
  bNode * node = calloc(1, sizeof(bNode));
  if (strlen(str) == 1){
    (node -> dim)[0] = -1;
    (node -> dim)[1] = -1;
    node -> value = str[0];
    node -> left = parsePR(f);
    node -> right = parsePR(f);
  }
  else{
    sscanf(str, "%d(%d,%d)", &(node -> value), node -> dim, (node -> dim) + 1);
  }
  free(str);
  return node;
}

void printPO(char * filename, bNode * head){
  FILE * f = fopen(filename, "w");
  if (!f){
    return;
  }
  poRecur(f, head);
}
static void poRecur(FILE * f, bNode * n){
  if(!n){
    return;
  }
  poRecur(f, n -> left);
  poRecur(f, n -> right);
  if(isLeaf(n)){
    fprintf(f, "%d(%d,%d)\n", n -> value, n -> dim[0], n -> dim[1]);
  }
  else{
    if (n -> dim[0] != -1 || n -> dim[1] != -1){
      fprintf(f, "%c(%d,%d)\n", n -> value, n -> dim[0], n -> dim[1]);
    }
    else{
      fprintf(f, "%c\n", n -> value);
    }
  }
}

void printDIM(char * filename, bNode * head){
  getWidth(head);
  getHeight(head);
  //PRINT TO FILE
  printPO(filename, head);
  return;
}

static int getWidth(bNode * n){
  if (!n){
    return 0;
  }
  if (!isLeaf(n)){
    int w1 = getWidth(n -> left);
    int w2 = getWidth(n -> right);
    if (n -> value == 'H'){
      n -> dim[0] = w1 > w2 ? w1 : w2;
    }
    if (n -> value == 'V'){
      n -> dim[0] = w1 + w2;
    }
    return n-> dim[0];
  }
  else{
    return n -> dim[0];
  }
}

static int getHeight(bNode * n){
  if (!n){
    return 0;
  }
  if (!isLeaf(n)){
    int w1 = getHeight(n -> left);
    int w2 = getHeight(n -> right);
    if (n -> value == 'H'){
      n -> dim[1] = w1 + w2;
    }
    if (n -> value == 'V'){
      n -> dim[1] = w1 > w2 ? w1 : w2;
    }
    return n-> dim[1];
  }
  else{
    return n -> dim[1];
  }
}

void printPCK(char * filename, bNode * head){
  if (isLeaf(head)){
    return;
  }
  FILE * f = fopen(filename, "w");
  if (!f){
    return;
  }

  if (head -> value == 'H'){
    PCKrecur(f, head -> left, (int[]) {0, head -> right -> dim [1]});
    PCKrecur(f, head -> right, (int[]) {0,0});
  }
  if(head -> value == 'V'){
    PCKrecur(f, head -> left, (int[]) {0,0});
    PCKrecur(f, head -> right, (int[]) {head -> right -> dim [0], 0});
  }
}

static void PCKrecur(FILE * f, bNode * n, int dim[2]){
  // dim refurs 
  if (!n){
    return;
  }
  if (isLeaf(n)){
    fprintf(f, "%d((%d,%d)(%d,%d))\n", n -> value, n -> dim[0], n -> dim[1], dim[0], dim[1]);
    return;
  }
  else{
    if (n -> value == 'V'){
      PCKrecur(f, n -> left, dim);
      PCKrecur(f, n -> right, (int[]) {dim[0] + n -> left -> dim[0], dim[1]});
    }
    else if (n -> value == 'H')
    {
      PCKrecur(f, n -> left, (int[]) {dim[0], dim[1] + n -> right -> dim[1]});
      PCKrecur(f, n -> right, dim);
    } 
  }
}