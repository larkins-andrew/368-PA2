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

void freeTree(bNode * head);
void _printErr(char * str, char * file, int line);
int isLeaf(bNode * n);