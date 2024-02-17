typedef struct _bNode {
    struct _bNode * left;
    struct _bNode * right;
    int value;
    int dim[2];
} bNode;

typedef struct _Node{
    struct _Node * next;
    char * value;
} Node;

void _printErr(char * str, char * file, int line);
void freeTree(bNode * head);
bNode * loadTree(char * filename);
bNode * parsePR(char ** arr, int size);
