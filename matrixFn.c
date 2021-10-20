//
// Created by skyle on 18/10/2021.
//

#include "matrixFn.h"



void readDim(int *row_dim, int *clm_dim){

    scanf("%d x %d", row_dim, clm_dim);



    if(isalpha(*row_dim) || isalpha(*clm_dim)){
        fprintf(stderr,"Error wrong input type for dimensions, please input digits\n");
        *clm_dim = -1;
    }
}



int checkDim( int clm_dim1, int row_dim2){

    int isOk = 1;

    if(clm_dim1 != row_dim2){
        isOk = 0;
    }
    return isOk;
}


void readMatrix(float **matrix,int row_dim, int clm_dim){

    int newRow = 0, value_r = 0, value_c = 0;

    for (int j = 0; j < row_dim * clm_dim; j++) {
        setbuf(stdout, 0);
        printf("Input row %d column %d of the matrix: ", value_r, value_c);
        scanf("%f", matrix[j]); // ???

        if(newRow == clm_dim - 1){
            value_r++;
            value_c = 0;
            newRow = 0;
        }

        value_c++;
        newRow++;

    }

    printf("\n");
}



void matrixProduct(float **result, float **matrix1, int row_dim1, float **matrix2, int clm_dim2, int clm1_or_row2_dim){

// multiplication of matrices
    for(int i = 0; i < row_dim1; i++){
        for(int j = 0; j < clm_dim2; j++){
            for(int k = 0; k < clm1_or_row2_dim; k++){
                *result[(i * clm_dim2) + j] += *matrix1[(i * clm1_or_row2_dim) + k] * *matrix2[(k * clm_dim2) + j];
            }
        }
    }
}



void printMatrix(float **matrix, int row_dim, int clm_dim){
    int newRow = 0;
    for(int i = 0; i < row_dim * clm_dim; i++){
        if(newRow == clm_dim){
            printf("\n");
            newRow = 0;
        }

        printf("%f", *matrix[i]);
        newRow++;
    }
    printf("\n");
}








