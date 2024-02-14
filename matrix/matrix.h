#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdbool.h>
#include <stddef.h>

#define MATRIX_LOGGING_ENABLE 

// structure for Matrix 
typedef struct Matrix {
    size_t rows;
    size_t cols;
    double* data;
} Matrix;

Matrix* matrix_create(size_t rows, size_t cols);

void matrix_deallocate(Matrix* matrix);
void matrix_print(Matrix* matrix);
bool matrix_set(Matrix* matrix, size_t rows, size_t cols, double value);

#endif 