#include "packing.h"
#include <stdio.h>
#include <stdlib.h>
#define printErr(str) \
  _printErr(str, __FILE__, __LINE__)


bNode * loadTree(char * filename){
  FILE * f = fopen(filename, "r");
  char * str = NULL;
  char * tempstr;
  char n;
  int size = 0;
  while (n = fgetc(str[size]) != '\n'){

  }
}

// bNode * loadTree(char * filename){
//   FILE * f = fopen(filename, "r");
//   char * str = NULL;
//   char * tempStr = NULL;
//   Node * n = malloc(sizeof(Node));
//   Node * head = malloc(sizeof(Node));
//   if (!n){
//     fclose(f);
//     return NULL;
//   }
//   int size = 0;
//   while (fgets(n -> value, sizeof(n -> value), f) != NULL){
//     fprintf(stderr, "%s", n -> value);
//     tempArr = realloc(arr, sizeof() * (size + 1));
//     if (!tempArr){
//       free(arr);
//       free(str);
//       fclose(f);
//       return NULL;
//     }
//     arr = tempArr;

//     arr[size] = str;
//     size++;
//     str = malloc(sizeof(char) * 8);
//   }
//   #ifdef DEBUG
//   fprintf(stderr, "arr:\n");
//   for (int i = 0; i < size; i++){
//     fprintf(stderr, "%s", arr[i]);
//   }
//   #endif
//   bNode * head = parsePR(arr, size);
//   // bNode * head;
//   free(arr);
//   free(str);
//   fclose(f);
//   return NULL;
//   // return head;
// }

// bNode * parsePR(char ** arr, int size){
//   if (arr == NULL || size == 0){
//     return NULL;
//   }
//   bNode * head = malloc(sizeof(bNode));
//   if (arr[0][0] == 'H' || arr[0][0] == 'V'){
//     head -> value = arr[0][0];
//     char ** tempArr = arr;
//     head -> left = parsePR_H(&(tempArr[1]), size-1);
//   }
//   return head;
// }

// static bNode * parsePR_H(char *** arr, int size){
//   if (arr == NULL || size == 0){
//     return NULL;
//   }
//   bNode * head = malloc(sizeof(bNode));
//   if (arr[0][0] == 'H' || arr[0][0] == 'V'){
//     head -> value = arr[0][0];
//     char ** tempArr = arr;
//     head -> left = parsePR_H(&(tempArr[1]), size-1);
//   }
//   return head;
// }

void freeTree(bNode * head){
  if (head != NULL) {
    freeTree(head -> left);
    freeTree(head -> right);
    free(head);
  }
}



void _printErr(char * str, char * file, int line){
  fprintf(stderr, "%s %s %d\n", str, file, line);
}
