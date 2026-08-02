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
#include <vector>
using namespace std;

// Function to read a matrix
vector<vector<int>> readMatrix(int rows, int columns)
{
    vector<vector<int>> matrix(rows, vector<int>(columns));

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter row " << i + 1 << ": ";

        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

// Function to display a matrix
void displayMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "\t";
        }

        cout << endl;
    }
}

// Part A: Transpose a matrix
void transposeMatrix()
{
    int rows, columns;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    vector<vector<int>> matrix = readMatrix(rows, columns);

    vector<vector<int>> transpose(
        columns,
        vector<int>(rows)
    );

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transpose);
}

// Part B: Add two matrices
void addMatrices()
{
    int rows, columns;

    cout << "\nEnter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    cout << "\nEnter Matrix 1" << endl;
    vector<vector<int>> matrix1 = readMatrix(rows, columns);

    cout << "\nEnter Matrix 2" << endl;
    vector<vector<int>> matrix2 = readMatrix(rows, columns);

    vector<vector<int>> result(
        rows,
        vector<int>(columns)
    );

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i][j] =
                matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "\nSum of the Matrices:" << endl;
    displayMatrix(result);
}

// Part C: Multiply two matrices
void multiplyMatrices()
{
    int rows1, columns1;
    int rows2, columns2;

    cout << "\nEnter rows of Matrix A: ";
    cin >> rows1;

    cout << "Enter columns of Matrix A: ";
    cin >> columns1;

    cout << "\nEnter Matrix A" << endl;
    vector<vector<int>> matrixA =
        readMatrix(rows1, columns1);

    cout << "\nEnter rows of Matrix B: ";
    cin >> rows2;

    cout << "Enter columns of Matrix B: ";
    cin >> columns2;

    if (columns1 != rows2)
    {
        cout << "Matrix multiplication is not possible."
             << endl;

        return;
    }

    cout << "\nEnter Matrix B" << endl;
    vector<vector<int>> matrixB =
        readMatrix(rows2, columns2);

    vector<vector<int>> result(
        rows1,
        vector<int>(columns2, 0)
    );

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            for (int k = 0; k < columns1; k++)
            {
                result[i][j] +=
                    matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nProduct of the Matrices:" << endl;
    displayMatrix(result);
}

int main()
{
    transposeMatrix();
    addMatrices();
    multiplyMatrices();

    return 0;
}
