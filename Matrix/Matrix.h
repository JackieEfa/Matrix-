//**************************************************************
// CPSC2620 Spring 2021
// File: Matrix.h //
// Purpose:  To implement the class Matrix as defined, implement the file
//input/output functions specified in sections 1, 2, and 3, and write a test program to thoroughly
//test each function you have implemented. The file input/output functions can be included in
//the test program.
// Written by: Jacqueline Eshriew
// Date: 2021-03-23
//**************************************************************

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Matrix
{

public:
    // Construction
    Matrix(int r = 0, int c = 0, double d = 0.0);

    // Copy construction
    Matrix(const Matrix& m);

    //Type conversion constructon
    Matrix(int r, int n, vector<double> v);

    // Destructor
    ~Matrix();

    // Index operators
    const double& operator()(int i, int j) const; //to work on const objects
    double& operator()(int i, int j);

    // Copy assignment operator
    Matrix& operator=(const Matrix& m);

    // Compound arithmetic operators
    Matrix& operator+=(const Matrix& x);
    Matrix& operator-=(const Matrix& x);
    Matrix& operator*=(const Matrix& m);
    Matrix& operator*=(double d); // scalar multiplication
    // Output

    void print(ostream& sout) const; //display the matrix onto output stream
    // sout neatly

    int ncols() const; //return the number of columns
    int nrows() const; // return the number of rows


private:

    int rows; // number of rows
    int cols; // number of columns
    double *element; //dynamic array to hold data
};
    // Arithmetic operators are not members
    Matrix operator+(const Matrix& l, const Matrix&r); // return l+r
    Matrix operator-(const Matrix& l, const Matrix&r); // return l-r // remove const?
    Matrix operator*(const Matrix& l, const Matrix&r); // return l*r
    Matrix operator*(double d, const Matrix& r); // return d*l
    Matrix operator*(const Matrix& m, double d); // return l*d

    // Overloaded stream insertion operator
    ostream& operator<<(ostream& out, const Matrix& x);

#endif
