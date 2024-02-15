typedef struct _bNode {
    struct _bNode * left;
    struct _bNode * right;
    int val;
    int isLeaf;
    int dim[2];
} bNode;

void _printErr(char * str, char * file, int line);
void freeTree(bNode * head);
bNode * loadTree(char * filename);
bNode * parsePR(char ** arr);
