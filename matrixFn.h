//
// Created by skyle on 18/10/2021.
//

#ifndef LAB02_MATRIXFN_H
#define LAB02_MATRIXFN_H

#define ERR_WRONG_INPUT -1
#define ERR_MATRICES_NOT_COMPATIBLE -2

#include <stdio.h>
#include <ctype.h>

void readDim(int *row_dim, int *clm_dim); // read dimension of matrix from std input r x c
int checkDim(int clm_dim1, int row_dim2); // checks if two matrices are compatible for product
void readMatrix(float **matrix,int row_dim, int clm_dim); // reads matrix from standard input
void matrixProduct(float **result, float **matrix1, int row_dim1, float **matrix2, int clm_dim2, int clm1_or_row2_dim); //computes the product of m1 and m2 stores in result
void printMatrix(float **matrix, int row_dim, int clm_dim); // prints the matrix

#endif //LAB02_MATRIXFN_H
