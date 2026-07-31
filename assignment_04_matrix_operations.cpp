// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int transposed[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transposed, cols, rows);
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nSum Matrix:\n";
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    int result[MAX_SIZE][MAX_SIZE] = {0};

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nProduct Matrix:\n";
    displayMatrix(result, rowsA, colsB);
}

int main() {
    int rows, cols;
    int matrixA[MAX_SIZE][MAX_SIZE];

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    cout << "Enter the matrix elements:\n";
    readMatrix(matrixA, rows, cols);
    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrixA, rows, cols);
    transposeMatrix(matrixA, rows, cols);

    int rowsB, colsB;
    int matrixB[MAX_SIZE][MAX_SIZE];

    cout << "\nEnter number of rows for second matrix: ";
    cin >> rowsB;
    cout << "Enter number of columns for second matrix: ";
    cin >> colsB;

    if (rowsB <= 0 || colsB <= 0 || rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    if (rows != rowsB || cols != colsB) {
        cout << "Error: The two matrices must be the same size for addition." << endl;
    } else {
        cout << "Enter the second matrix elements:\n";
        readMatrix(matrixB, rowsB, colsB);
        addMatrices(matrixA, matrixB, rows, cols);
    }

    int rowsC, colsC;
    int matrixC[MAX_SIZE][MAX_SIZE];
    cout << "\nEnter number of rows for matrix A in multiplication: ";
    cin >> rowsC;
    cout << "Enter number of columns for matrix A in multiplication: ";
    cin >> colsC;

    if (rowsC <= 0 || colsC <= 0 || rowsC > MAX_SIZE || colsC > MAX_SIZE) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    int rowsD, colsD;
    int matrixD[MAX_SIZE][MAX_SIZE];
    cout << "Enter number of rows for matrix B in multiplication: ";
    cin >> rowsD;
    cout << "Enter number of columns for matrix B in multiplication: ";
    cin >> colsD;

    if (rowsD <= 0 || colsD <= 0 || rowsD > MAX_SIZE || colsD > MAX_SIZE) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    if (colsC != rowsD) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
    } else {
        cout << "Enter matrix A elements:\n";
        readMatrix(matrixC, rowsC, colsC);
        cout << "Enter matrix B elements:\n";
        readMatrix(matrixD, rowsD, colsD);
        multiplyMatrices(matrixC, matrixD, rowsC, colsC, rowsD, colsD);
    }

    return 0;
}

