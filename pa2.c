#include "nodes.h"
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
  FILE * f_in =   fopen(argv[1], "r");
  if (!f_in){
    return EXIT_FAILURE;
  }
  FILE * f_out1 = fopen(argv[2], "w");
  if (!f_out1) {
    fclose(f_in);
    return EXIT_FAILURE;
  }
  FILE * f_out2 = fopen(argv[3], "w");
  if (!f_out2) {
    fclose(f_in);
    fclose(f_out1);
    return EXIT_FAILURE;
  }
  FILE * f_out3 = fopen(argv[4], "w");
  if (!f_out3) {
    fclose(f_in);
    fclose(f_out1);
    fclose(f_out2);
    return EXIT_FAILURE;
  }

  bNode * head = loadPR(f_in);
  if (!head) {
    printErr("Err: loadTree returns NULL");
    return EXIT_FAILURE;
  }

  printPO(f_out1, head)
  printDIM(f_out2, head)
  printPCK(f_out3, head)
  freeTree(head);
  return EXIT_SUCCESS;
}
