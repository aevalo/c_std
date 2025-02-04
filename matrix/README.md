# Matrix Lib in C 

## Example 1 : how to create matrix object and set and get value from it also print 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(3, 4);

    if (!matrix) {
        fmt_fprintf(stderr, "Can not create matrix object");
        exit(-1);
    }
    
    matrix_set(matrix, 1, 1, 15.32); // row 1 and colon 1
    matrix_print(matrix);

    fmt_printf("Value of matrix in row %zu and col %zu is %lf\n", 1, 1, matrix_get(matrix, 1, 1));

    matrix_deallocate(matrix);
    return 0;
}
```

## Example 2 : how to add two Matrix with `matrix_add`

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"
#include <time.h>

void fillMatrix(Matrix *mat) {
    matrix_set(mat, 0, 0, rand() % 10 + 1);
    matrix_set(mat, 0, 1, rand() % 10 + 1);
    matrix_set(mat, 1, 0, rand() % 10 + 1);
    matrix_set(mat, 1, 1, rand() % 10 + 1);
}

int main() {
    srand(time(NULL));
    Matrix* matrix1 = matrix_create(2, 2);
    Matrix* matrix2 = matrix_create(2, 2);

    if (!matrix1 || !matrix2) {
        fmt_fprintf(stderr, "Can not create matrix object");
        exit(-1);
    }

    fillMatrix(matrix1);
    fillMatrix(matrix2);

    matrix_print(matrix1);
    fmt_printf("\n");
    matrix_print(matrix2);

    Matrix* sum = matrix_add(matrix1, matrix2);

    fmt_printf("\n");
    matrix_print(sum);

    matrix_deallocate(sum);
    matrix_deallocate(matrix1);
    matrix_deallocate(matrix2);
    
    return 0;
}
```

## Example 3 : subtract two matrix with `matrix_subtract`

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"
#include <time.h>

void fillMatrix(Matrix *mat) {
    matrix_set(mat, 0, 0, rand() % 10 + 1);
    matrix_set(mat, 0, 1, rand() % 10 + 1);
    matrix_set(mat, 1, 0, rand() % 10 + 1);
    matrix_set(mat, 1, 1, rand() % 10 + 1);
}

int main() {
    srand(time(NULL));
    Matrix* matrix1 = matrix_create(2, 2);
    Matrix* matrix2 = matrix_create(2, 2);

    if (!matrix1 || !matrix2) {
        fmt_fprintf(stderr, "Can not create matrix object");
        exit(-1);
    }

    fillMatrix(matrix1);
    fillMatrix(matrix2);

    Matrix* subtraction = matrix_subtract(matrix1, matrix2);

    fmt_printf("\n");
    matrix_print(subtraction);

    matrix_deallocate(subtraction);
    matrix_deallocate(matrix1);
    matrix_deallocate(matrix2);
    
    return 0;
}
```

## Example 4 : multiply two Matrix with `matrix_multiply`

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"
#include <time.h>

void fillMatrix(Matrix *mat) {
    matrix_set(mat, 0, 0, rand() % 10 + 1);
    matrix_set(mat, 0, 1, rand() % 10 + 1);
    matrix_set(mat, 1, 0, rand() % 10 + 1);
    matrix_set(mat, 1, 1, rand() % 10 + 1);
}

int main() {
    srand(time(NULL));
    Matrix* matrix1 = matrix_create(2, 2);
    Matrix* matrix2 = matrix_create(2, 2);

    if (!matrix1 || !matrix2) {
        fmt_fprintf(stderr, "Can not create matrix object");
        exit(-1);
    }

    fillMatrix(matrix1);
    fillMatrix(matrix2);

    matrix_print(matrix1);
    fmt_printf("\n");
    matrix_print(matrix2);

    Matrix* product = matrix_multiply(matrix1, matrix2);

    fmt_printf("\n");
    matrix_print(product);

    matrix_deallocate(product);
    matrix_deallocate(matrix1);
    matrix_deallocate(matrix2);
    
    return 0;
}
```

## Example 5 : mutiply elements of Matrix with a scalar 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    // create 2 X 3 Matrices
    Matrix* matrix = matrix_create(2, 3); 
    if (!matrix) {
        fmt_fprintf(stderr, "Cannot create matrix object\n");
        exit(-1);
    }

    matrix_set(matrix, 0, 0, 1.0);
    matrix_set(matrix, 0, 1, 2.0);
    matrix_set(matrix, 0, 2, 3.0);
    matrix_set(matrix, 1, 0, 4.0);
    matrix_set(matrix, 1, 1, 5.0);
    matrix_set(matrix, 1, 2, 6.0);

    fmt_printf("Original matrix:\n");
    matrix_print(matrix);

    double scalar = 2.0;
    if (matrix_scalar_multiply(matrix, scalar)) {
        fmt_printf("\nMatrix after scalar multiplication by %lf:\n", scalar);
        matrix_print(matrix);
    } 
    else {
        fmt_fprintf(stderr, "Scalar multiplication failed\n");
    }

    matrix_deallocate(matrix);
    return 0;
}
```

## Example 6 : check Matrix is square or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* mat = matrix_create(2, 3);

    if (!mat) {
        fmt_fprintf(stderr, "Can not create matrix");
        exit(-1);
    }

    if (matrix_is_square(mat)) {
        fmt_printf("Matrix is square");
    }
    else {
        fmt_printf("Matrix is not square");
    }
    
    return 0;
}
```

## Example 7 : create identity matrix and check is equal with other one or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    // Create two identity matrix of size 3x3
    Matrix* matrix1 = matrix_create_identity(3);
    Matrix* matrix2 = matrix_create_identity(3);

    if (!matrix1 || !matrix2) {
        fmt_fprintf(stderr, "Failed to create identity matrices\n");
        exit(-1); 
    }

    if (matrix_is_equal(matrix1, matrix2)) {
        fmt_printf("Matrix1 and Matrix2 are equal.\n");
    } 
    else {
        fmt_printf("Matrix1 and Matrix2 are not equal.\n");
    }

    matrix_set(matrix1, 2, 2, 2.0); 

    if (matrix_is_equal(matrix1, matrix2)) {
        fmt_printf("After modification, Matrix1 and Matrix2 are still equal.\n");
    } 
    else {
        fmt_printf("After modification, Matrix1 and Matrix2 are not equal.\n");
    }

    matrix_deallocate(matrix1);
    matrix_deallocate(matrix2);

    return 0;
}
```

## Example 8 : check Matrix is identity or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* identityMatrix = matrix_create_identity(3);
    if (!identityMatrix) {
        fmt_fprintf(stderr, "Failed to create identity matrix\n");
        exit(-1);
    }

    if (matrix_is_identity(identityMatrix)) {
        fmt_printf("The matrix is an identity matrix.\n");
    } 
    else {
        fmt_printf("The matrix is not an identity matrix.\n");
    }

    Matrix* nonIdentityMatrix = matrix_create(3, 3);
    if (!nonIdentityMatrix) {
        fmt_fprintf(stderr, "Failed to create non-identity matrix\n");
        exit(-1);
    }

    matrix_set(nonIdentityMatrix, 0, 0, 1.0);
    matrix_set(nonIdentityMatrix, 1, 1, 1.0);
    matrix_set(nonIdentityMatrix, 2, 2, 0.5);


    if (matrix_is_identity(nonIdentityMatrix)) {
        fmt_printf("The matrix is an identity matrix.\n");
    } 
    else {
        fmt_printf("The matrix is not an identity matrix.\n");
    }

    matrix_deallocate(identityMatrix);
    matrix_deallocate(nonIdentityMatrix);

    return 0;
}
```

## Example 9 : check Matrix is idempotent or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    // Idempotent matrix
    Matrix* matrix1 = matrix_create(3, 3);
    double data1[] = {-1, 1, 1, -1, 1, 1, -1, 1, 1};
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            matrix_set(matrix1, i, j, data1[i * 3 + j]);
        }
    }

    // Non-idempotent matrix
    Matrix* matrix2 = matrix_create(2, 2);
    double data2[] = {1, 2, 3, 4};
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 2; j++) {
            matrix_set(matrix2, i, j, data2[i * 2 + j]);
        }
    }

    if (matrix_is_idempotent(matrix1)) {
        printf("Matrix 1 is idempotent.\n");
    } 
    else {
        printf("Matrix 1 is not idempotent.\n");
    }

    if (matrix_is_idempotent(matrix2)) {
        printf("Matrix 2 is idempotent.\n");
    } 
    else {
        printf("Matrix 2 is not idempotent.\n");
    }

    matrix_deallocate(matrix1);
    matrix_deallocate(matrix2);

    return 0;
}
```

## Example 10 : check row and columnar Matrix 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* rowMatrix = matrix_create(1, 3); 
    Matrix* columnMatrix = matrix_create(3, 1); 
    Matrix* regularMatrix = matrix_create(2, 2);

    if (matrix_is_row(rowMatrix)) {
        fmt_printf("RowMatrix is a row matrix.\n");
    } 
    else {
        fmt_printf("RowMatrix is not a row matrix.\n");
    }

    if (matrix_is_columnar(columnMatrix)) {
        fmt_printf("ColumnMatrix is a columnar matrix.\n");
    } 
    else {
        fmt_printf("ColumnMatrix is not a columnar matrix.\n");
    }

    if (!matrix_is_row(regularMatrix) && !matrix_is_columnar(regularMatrix)) {
        fmt_printf("RegularMatrix is neither a row matrix nor a columnar matrix.\n");
    }

    matrix_deallocate(rowMatrix);
    matrix_deallocate(columnMatrix);
    matrix_deallocate(regularMatrix);

    return 0;
}
```

## Example 11 : get diagonal Matrix as row or columns 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(3, 3);
    Matrix* diagonalMatrix = matrix_get_main_diagonal_as_column(matrix);
    Matrix* diagonalRowMatrix = matrix_get_main_diagonal_as_row(matrix);

    if (diagonalMatrix) {
        fmt_printf("Main diagonal as a column matrix:\n");
        matrix_print(diagonalMatrix); 
    } 
    else {
        fmt_printf("Failed to get the main diagonal as a column matrix.\n");
    }

    if (diagonalRowMatrix) {
        fmt_printf("Main diagonal as a row matrix:\n");
        matrix_print(diagonalRowMatrix);
    } 
    else {
        fmt_printf("Failed to get the main diagonal as a row matrix.\n");
    }

    matrix_deallocate(matrix);
    matrix_deallocate(diagonalMatrix);
    matrix_deallocate(diagonalRowMatrix);

    return 0;
}
```

## Example 12 : get minor diagonal as row and columns 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(3, 3);
    if (!matrix) {
        printf("Failed to create matrix.\n");
        return -1;
    }

    double values[9] = {
        1.0, 2.0, 3.0, // First row
        4.0, 5.0, 6.0, // Second row
        7.0, 8.0, 9.0  // Third row
    };

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            matrix_set(matrix, i, j, values[i * 3 + j]);
        }
    }

    Matrix* minorDiagonalRow = matrix_get_minor_diagonal_as_row(matrix);
    if (minorDiagonalRow) {
        printf("Minor diagonal as a row matrix:\n");
        matrix_print(minorDiagonalRow); 
    } 
    else {
        printf("Failed to get the minor diagonal as a row matrix.\n");
    }

    Matrix* minorDiagonalColumn = matrix_get_minor_diagonal_as_column(matrix);
    if (minorDiagonalColumn) {
        printf("Minor diagonal as a column matrix:\n");
        matrix_print(minorDiagonalColumn); 
    } 
    else {
        printf("Failed to get the minor diagonal as a column matrix.\n");
    }

    matrix_deallocate(matrix);
    matrix_deallocate(minorDiagonalRow);
    matrix_deallocate(minorDiagonalColumn);

    return 0;
}
```

## Example 13 : create transpose Matrix 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(2, 3);
    if (!matrix) {
        fmt_fprintf(stderr, "Cannot create matrix object\n");
        exit(-1);
    }

    matrix_set(matrix, 0, 0, 1.0);
    matrix_set(matrix, 0, 1, 2.0);
    matrix_set(matrix, 0, 2, 3.0);
    matrix_set(matrix, 1, 0, 4.0);
    matrix_set(matrix, 1, 1, 5.0);
    matrix_set(matrix, 1, 2, 6.0);

    fmt_printf("Original matrix:\n");
    matrix_print(matrix);

    Matrix* transposedMatrix = matrix_transpose(matrix);
    if (!transposedMatrix) {
        fmt_fprintf(stderr, "Failed to transpose the matrix\n");
        matrix_deallocate(matrix);
        exit(-1);
    }

    fmt_printf("\nTransposed matrix:\n");
    matrix_print(transposedMatrix);

    matrix_deallocate(matrix);
    matrix_deallocate(transposedMatrix);

    return 0;
}
```

## Example 14 : check Matrix is symmetric or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrixA = matrix_create(4, 4);
    double valuesA[16] = {9, 13, 3, 6, 13, 11, 7, 6, 3, 7, 4, 7, 6, 6, 7, 10};

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            matrix_set(matrixA, i, j, valuesA[i * 4 + j]);
        }
    }

    if (matrix_is_symmetric(matrixA)) {
        fmt_printf("Matrix A is symmetric.\n");
    } 
    else {
        fmt_printf("Matrix A is not symmetric.\n");
    }

    matrix_deallocate(matrixA);
    return 0;
}
```

## Example 15 : Matrix is upper or lower triangular.

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* upperTriangular = matrix_create(3, 3);
    matrix_set(upperTriangular, 0, 0, 1);
    matrix_set(upperTriangular, 0, 1, 2);
    matrix_set(upperTriangular, 0, 2, 3);
    

    Matrix* lowerTriangular = matrix_create(3, 3);
    matrix_set(lowerTriangular, 0, 0, 1);
    matrix_set(lowerTriangular, 1, 0, 2);
    matrix_set(lowerTriangular, 1, 1, 3);
    matrix_set(lowerTriangular, 2, 0, 4);
    matrix_set(lowerTriangular, 2, 1, 5);
    matrix_set(lowerTriangular, 2, 2, 6);
    

    if (matrix_is_upper_triangular(upperTriangular)) {
        fmt_printf("The first matrix is upper triangular.\n");
    } 
    else {
        fmt_printf("The first matrix is not upper triangular.\n");
    }

    if (matrix_is_lower_triangular(lowerTriangular)) {
        fmt_printf("The second matrix is lower triangular.\n");
    } 
    else {
        fmt_printf("The second matrix is not lower triangular.\n");
    }

    matrix_deallocate(upperTriangular);
    matrix_deallocate(lowerTriangular);

    return 0;
}
```

## Example 16 : is skew symmetric or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    // Create a 2x2 skew-symmetric matrix
    Matrix* skewSymmetric = matrix_create(2, 2);
    
    matrix_set(skewSymmetric, 0, 0, 0); 
    matrix_set(skewSymmetric, 0, 1, 2); 
    matrix_set(skewSymmetric, 1, 0, -2); 
    matrix_set(skewSymmetric, 1, 1, 0); 

    if (matrix_is_skew_symmetric(skewSymmetric)) {
        fmt_printf("The matrix is skew-symmetric.\n");
    } 
    else {
        fmt_printf("The matrix is not skew-symmetric.\n");
    }

    matrix_deallocate(skewSymmetric);
    return 0;
}
```

## Example 17: Determinant of a 2X2 Matrix

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(2, 2);

    matrix_set(matrix, 0, 0, 4); 
    matrix_set(matrix, 0, 1, 7); 
    matrix_set(matrix, 1, 0, 2); 
    matrix_set(matrix, 1, 1, 6); 

    double det = matrix_determinant(matrix);
    fmt_printf("Determinant of the 2x2 matrix is: %lf\n", det);

    matrix_deallocate(matrix);
    return 0;
}
```

## Example 18: Determinant of a 3X3 Matrix

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(3, 3);

    matrix_set(matrix, 0, 0, 6); 
    matrix_set(matrix, 0, 1, 1); 
    matrix_set(matrix, 0, 2, 1); 
    matrix_set(matrix, 1, 0, 4); 
    matrix_set(matrix, 1, 1, -2);
    matrix_set(matrix, 1, 2, 5); 
    matrix_set(matrix, 2, 0, 2); 
    matrix_set(matrix, 2, 1, 8); 
    matrix_set(matrix, 2, 2, 7); 

    double det = matrix_determinant(matrix);
    fmt_printf("Determinant of the 3x3 matrix is: %lf\n", det);

    matrix_deallocate(matrix);
    return 0;
}
```

## Example 19: Determinant Calculation with Identity Matrix

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    // Create a 4x4 identity matrix
    Matrix* identityMatrix = matrix_create_identity(4);

    double det = matrix_determinant(identityMatrix);
    fmt_printf("Determinant of the 4x4 identity matrix is: %lf\n", det);

    matrix_deallocate(identityMatrix);
    return 0;
}
```

## Example 20 : sum of diagonal elements of matrix 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(3, 3);
    
    if (!matrix) {
        fmt_fprintf(stderr, "Cannot create matrix object\n");
        exit(-1);
    }

    matrix_set(matrix, 0, 0, 1.0); 
    matrix_set(matrix, 0, 1, 2.0);
    matrix_set(matrix, 0, 2, 3.0);
    matrix_set(matrix, 1, 0, 4.0);
    matrix_set(matrix, 1, 1, 5.0); 
    matrix_set(matrix, 1, 2, 6.0);
    matrix_set(matrix, 2, 0, 7.0);
    matrix_set(matrix, 2, 1, 8.0);
    matrix_set(matrix, 2, 2, 9.0); 

    fmt_printf("Matrix:\n");
    matrix_print(matrix);

    double trace = matrix_trace(matrix);
    fmt_printf("Trace of the matrix is: %lf\n", trace);

    matrix_deallocate(matrix);
    return 0;
}
```

## Example 21 : get inverse of matrix 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(2, 2);
    if (!matrix) {
        fmt_fprintf(stderr, "Failed to create matrix.\n");
        return -1;
    }

    // | 4 7 |
    // | 2 6 |
    matrix_set(matrix, 0, 0, 4);
    matrix_set(matrix, 0, 1, 7);
    matrix_set(matrix, 1, 0, 2);
    matrix_set(matrix, 1, 1, 6);


    fmt_printf("Original Matrix:\n");
    matrix_print(matrix);

    Matrix* inverseMatrix = matrix_inverse(matrix);
    if (!inverseMatrix) {
        fmt_fprintf(stderr, "Failed to calculate the inverse of the matrix.\n");
        matrix_deallocate(matrix);
        return -1;
    }

    fmt_printf("\nInverse Matrix:\n");
    matrix_print(inverseMatrix);

    matrix_deallocate(matrix);
    matrix_deallocate(inverseMatrix);

    return 0;
}
```

## Example 22: How to raise a square matrix to an integer power also how to copy 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(2, 2);
    if (!matrix) {
        fmt_fprintf(stderr, "Failed to create matrix.\n");
        return -1;
    }

    // | 1 2 |
    // | 3 4 |
    matrix_set(matrix, 0, 0, 1);
    matrix_set(matrix, 0, 1, 2);
    matrix_set(matrix, 1, 0, 3);
    matrix_set(matrix, 1, 1, 4);

    Matrix* matrixCopy = matrix_copy(matrix);
    if (!matrixCopy) {
        fmt_fprintf(stderr, "Failed to copy matrix.\n");
        matrix_deallocate(matrix);
        
        return -1;
    }

    int power = 2;
    Matrix* matrixPowered = matrix_power(matrix, power);
    if (!matrixPowered) {
        fmt_fprintf(stderr, "Failed to raise matrix to power %d.\n", power);
        matrix_deallocate(matrix);
        matrix_deallocate(matrixCopy);

        return -1;
    }

    fmt_printf("Original Matrix:\n");
    matrix_print(matrix);

    fmt_printf("\nCopied Matrix (should be identical to original):\n");
    matrix_print(matrixCopy);

    fmt_printf("\nMatrix Raised to Power %d:\n", power);
    matrix_print(matrixPowered);

    matrix_deallocate(matrix);
    matrix_deallocate(matrixCopy);
    matrix_deallocate(matrixPowered);

    return 0;
}
```

## Example 23 : get rank of matrix 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(3, 3);
    if (!matrix) {
        fmt_fprintf(stderr, "Failed to create matrix.\n");
        return -1;
    }

    // | 1 2 3 |
    // | 4 5 6 |
    // | 7 8 9 |
    matrix_set(matrix, 0, 0, 1);
    matrix_set(matrix, 0, 1, 2);
    matrix_set(matrix, 0, 2, 3);
    matrix_set(matrix, 1, 0, 4);
    matrix_set(matrix, 1, 1, 5);
    matrix_set(matrix, 1, 2, 6);
    matrix_set(matrix, 2, 0, 7);
    matrix_set(matrix, 2, 1, 8);
    matrix_set(matrix, 2, 2, 9);

    int rank = matrix_rank(matrix);

    fmt_printf("Matrix:\n");
    matrix_print(matrix);

    fmt_printf("\nRank of the matrix is: %d\n", rank);

    matrix_deallocate(matrix);
    return 0;
}
```

## Example 24 : check Matrix is diagonal or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    Matrix* matrix = matrix_create(3, 3);
    if (!matrix) {
        fmt_fprintf(stderr, "Failed to create matrix.\n");
        return EXIT_FAILURE;
    }

    matrix_set(matrix, 0, 0, 1.0);
    matrix_set(matrix, 1, 1, 5.0);
    matrix_set(matrix, 2, 2, 9.0);

    fmt_printf("Initial matrix:\n");
    matrix_print(matrix);

    // Check if the matrix is diagonal
    if (matrix_is_diagonal(matrix)) {
        fmt_printf("The matrix is diagonal.\n");
    } 
    else {
        fmt_printf("The matrix is not diagonal.\n");
    }

    // Modify the matrix to make it non-diagonal
    matrix_set(matrix, 0, 1, 2.0);

    fmt_printf("\nModified matrix:\n");
    matrix_print(matrix);

    if (matrix_is_diagonal(matrix)) {
        fmt_printf("The matrix is diagonal.\n");
    } 
    else {
        fmt_printf("The matrix is not diagonal.\n");
    }

    matrix_deallocate(matrix);
    return 0;
}
```

## Example 25 : Matrix is orthogonal or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    // Orthogonal matrix example: Q = [0 -1; 1 0], Q * Q^T = I
    Matrix* matrix = matrix_create(2, 2);
    if (!matrix) {
        fmt_fprintf(stderr, "Failed to create matrix.\n");
        return EXIT_FAILURE;
    }

    matrix_set(matrix, 0, 0, 0);
    matrix_set(matrix, 0, 1, -1);
    matrix_set(matrix, 1, 0, 1);
    matrix_set(matrix, 1, 1, 0);

    fmt_printf("Original matrix:\n");
    matrix_print(matrix);

    if (matrix_is_orthogonal(matrix)) {
        fmt_printf("The matrix is orthogonal.\n");
    } 
    else {
        fmt_printf("The matrix is not orthogonal.\n");
    }

    // Modify the matrix to make it non-orthogonal
    matrix_set(matrix, 0, 0, 1); 

    fmt_printf("\nModified matrix:\n");
    matrix_print(matrix);

    if (matrix_is_orthogonal(matrix)) {
        fmt_printf("The modified matrix is orthogonal.\n");
    } 
    else {
        fmt_printf("The modified matrix is not orthogonal.\n");
    }

    matrix_deallocate(matrix);
    return 0;
}
```

## Example 26 : product matrix Kronecker 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    // Define matrix A (2x2)
    Matrix* A = matrix_create(2, 2);
    matrix_set(A, 0, 0, 1); 
    matrix_set(A, 0, 1, 2); 
    matrix_set(A, 1, 0, 3); 
    matrix_set(A, 1, 1, 4); 

    // Define matrix B (2x2)
    Matrix* B = matrix_create(2, 2);
    matrix_set(B, 0, 0, 0); 
    matrix_set(B, 0, 1, 5); 
    matrix_set(B, 1, 0, 6); 
    matrix_set(B, 1, 1, 7); 

    Matrix* C = matrix_kronecker_product(A, B);
    if (!C) {
        fmt_fprintf(stderr, "Failed to compute the Kronecker product.\n");
        matrix_deallocate(A);
        matrix_deallocate(B);
        
        return -1;
    }

    fmt_printf("Matrix A:\n");
    matrix_print(A);

    fmt_printf("\nMatrix B:\n");
    matrix_print(B);

    fmt_printf("\nKronecker product of A and B:\n");
    matrix_print(C);

    matrix_deallocate(A);
    matrix_deallocate(B);
    matrix_deallocate(C);

    return 0;
}
```

## Example 27 : create hankel Matrix from first row and last col 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    double firstRowData[] = {1, 2, 3, 4};
    Matrix* firstRow = matrix_create(1, 4);
    for (size_t i = 0; i < 4; i++) {
        matrix_set(firstRow, 0, i, firstRowData[i]);
    }

    double lastColData[] = {4, 5, 6, 7};
    Matrix* lastCol = matrix_create(4, 1);
    for (size_t i = 0; i < 4; i++) {
        matrix_set(lastCol, i, 0, lastColData[i]);
    }

    // Generate the Hankel matrix
    Matrix* hankelMatrix = matrix_hankel(firstRow, lastCol);
    if (hankelMatrix) {
        fmt_printf("Hankel Matrix:\n");
        matrix_print(hankelMatrix);
    } 
    else {
        fmt_fprintf(stderr, "Failed to generate Hankel matrix.\n");
    }

    matrix_deallocate(firstRow);
    matrix_deallocate(lastCol);
    matrix_deallocate(hankelMatrix);

    return EXIT_SUCCESS;
}
```

## Example 28 : check matrix is hankle or not 

```c
#include "matrix/matrix.h"
#include "fmt/fmt.h"

int main() {
    size_t n = 4; 
    Matrix* matrix = matrix_create(n, n);
    
    if (!matrix) {
        fmt_fprintf(stderr, "Failed to create matrix.\n");
        return EXIT_FAILURE;
    }

    double values[] = {1, 2, 3, 4, 3, 4, 5, 4, 5, 6, 5, 6, 7};
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i + j < n) {
                matrix_set(matrix, i, j, values[i + j]);
            } 
            else {
                matrix_set(matrix, i, j, values[n - 1 + (i + j - n + 1)]);
            }
        }
    }

    fmt_printf("Matrix:\n");
    matrix_print(matrix);

    if (matrix_is_hankel(matrix)) {
        fmt_printf("The matrix is Hankel.\n");
    } 
    else {
        fmt_printf("The matrix is not Hankel.\n");
    }

    matrix_deallocate(matrix);
    return 0;
}
```