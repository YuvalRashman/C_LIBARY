#include <stdio.h>
#include "stringL.h"
#include "matrix.h"

void main() {
    unsigned short matrix1[4][4] = {{1,2,3,4},
                                    {5,6,7,8},
                                    {1,2,3,4},
                                    {1,2,3,4}};
    unsigned short matrix2[6][6] = {0};
    unsigned short pos[2] = {0, 0};
    printf("%d", countNeighbors(4, 4, pos));
}
