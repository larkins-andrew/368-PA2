#include "packing.h"
#include <stdio.h>
#include <stdlib.h>

#define printErr(str) \
  _printErr(str, __FILE__, __LINE__)

int main (int argc, char ** argv){
  if (argc != 5){
      printErr("Err: argc != 4");
      return EXIT_FAILURE;
  }
  char * f_in = argv[1];
  char * f_out1 = argv[2];
  char * f_out2 = argv[3];
  char * f_out3 = argv[4];

  bNode * head = loadTree(f_in);
  if (!head) {
    printErr("Err: loadTree returns NULL");
    return EXIT_FAILURE;
  }

  #ifdef DEBUG
    //Print Tree
  #endif
    //Not Implemented
  //outPO(head, f_out1);

  freeTree(head);
  return EXIT_FAILURE;
}
