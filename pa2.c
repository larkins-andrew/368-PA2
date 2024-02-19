#include "nodes.h"
#include "packing.h"
#include <stdio.h>
#include <stdlib.h>

#define printErr(str) \
  _printErr(str, __FILE__, __LINE__)

int main (int argc, char ** argv){
  // if (argc != 5){
  //     printErr("Err: argc != 4");
  //     return EXIT_FAILURE;
  // }
  char * f_in;
  char * f_out1;
  char * f_out2;
  char * f_out3;
  //char * f_out3;
  if (argc == 1){
    f_in = "examples/8.pr";
    f_out1 = "8.po";
    f_out2 = "8.dim";
    f_out3 = "8.pck";
  }
  else{
    f_in = argv[1];
    f_out1 = argv[2];
    f_out2 = argv[3];
    f_out3 = argv[4];
  }
  // char * f_in =   argv[1];
  // char * f_out1 = argv[2];
  // char * f_out2 = argv[3];
  // char * f_out3 = argv[4];

  bNode * head = loadPR(f_in);
  if (!head) {
    printErr("Err: loadTree returns NULL");
    return EXIT_FAILURE;
  }
  printPO(f_out1, head);
  printDIM(f_out2, head);
  printPCK(f_out3, head);
  freeTree(head);
  return EXIT_FAILURE;
}
