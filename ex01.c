#include <stdio.h>
#include <stdlib.h>
#include "matrixFn.h"

#define ERR_NO_MEM -3;

int main() {

    float * m1 = NULL, * m2 = NULL, * m3 = NULL;
    int dim_row1, dim_clm1, dim_row2, dim_clm2;


    printf("Input matrix 1 dimensions (rxc): ");
    readDim(&dim_row1, &dim_clm1);

    if (dim_clm1 == -1) {
        return ERR_WRONG_INPUT;
    }

    printf("Input matrix 2 dimensions (rxc): ");
    readDim(&dim_row2, &dim_clm2);

    if (dim_clm2 == -1) {
        return ERR_WRONG_INPUT;
    }

    if(checkDim(dim_clm1, dim_row2) == 0){
        fprintf(stderr,"Error the two matrices are not compatible\n");
        return ERR_MATRICES_NOT_COMPATIBLE;
    }

    m1 = (float *) realloc(m1, (dim_clm1 * dim_row1) * sizeof(float));
    if(m1 == NULL){
        fprintf(stderr, "Error allocating memory");
        free(m1);
        return ERR_NO_MEM;
    }

    m2 = (float *) realloc(m2, (dim_clm2 * dim_row2) * sizeof(float));
    if(m2 == NULL){
        fprintf(stderr, "Error allocating memory");
        free(m2);
        return ERR_NO_MEM;
    }
    if(m1 == NULL){
        fprintf(stderr, "Error allocating memory");
        free(m1);
        return ERR_NO_MEM;
    }

    m3 = (float *) realloc(m3, (dim_clm2 * dim_row1) * sizeof(float));
    if(m3 == NULL){
        fprintf(stderr, "Error allocating memory");
        free(m3);
        return ERR_NO_MEM;
    }
    if(m2 == NULL){
        fprintf(stderr, "Error allocating memory");
        free(m2);
        return ERR_NO_MEM;
    }
    if(m1 == NULL){
        fprintf(stderr, "Error allocating memory");
        free(m1);
        return ERR_NO_MEM;
    }


    readMatrix(m1, dim_row1, dim_clm1);
    readMatrix(m2, dim_row2, dim_clm2);


    matrixProduct(m3, m1, dim_row1, m2, dim_clm2, dim_clm1);

    printf("_-_-_-[Matrix 1]-_-_-_\n");
    printMatrix(m1, dim_row1, dim_clm1);

    printf("_-_-_-[Matrix 2]-_-_-_\n");
    printMatrix(m1, dim_row2, dim_clm2);

    printf("_-_-_-[Matrix 3]-_-_-_\n");
    printMatrix(m1, dim_row1, dim_clm2);


    return 0;
}
