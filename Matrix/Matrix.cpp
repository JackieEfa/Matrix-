//**************************************************************
// CPSC2620 Spring 2021
// File: Matrix.cc //
// Purpose:  To implement the class Matrix as defined, implement the file
//input/output functions specified in sections 1, 2, and 3, and write a test program to thoroughly
//test each function you have implemented. The file input/output functions can be included in
//the test program.
// Written by: Jacqueline Eshriew
// Date: 2021-03-23
//**************************************************************

#include "Matrix.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cassert>

Matrix::Matrix(int r, int c, double d )
//accepts three arguments: r being the number of rows, c being the number of columns,
//and an initialization value d = 0.0 for the contents. If none of the arguments is
//supplied, the above constructor acts as a default constructor with the value of r and
//c set to 0
{
    if (r == 0 || c == 0)
    {
        rows = 0;
        cols = 0;
        element = nullptr;
    }
    else
    {
        rows = r;
        cols = c;
        element = new double [rows * cols];
    }

    for (int i = 0; i < rows * cols; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            element[i * cols + j] = d;
        }

    }

}


Matrix::Matrix(const Matrix& m)
//The copy constructor creates a new matrix object which is an
//identical copy of the object passed via parameter.
{
     cols = m.ncols();
     rows = m.nrows();
     element = new double [rows * cols];

     for (int i = 0; i < rows; i++)
     {
         for (int j = 0; j < cols; j++)
         {
            element[cols * i +j] = m(i,j);
         }
     }

}


Matrix::Matrix(int r, int c, vector<double> v )
//accepts three arguments: r being the number of rows, c being the number of columns,
//and a vector of doubles v containing r*c double values. It creates a matrix with the
//specified rows and columns and the values provided in the parameter v.

{
    assert(v.size() == r * c);

     cols = c;
     rows = r;
     element = new double[rows * cols];

     for(int i = 0; i < rows; i++)
     {
         for(int j = 0; j < cols; j++)
         {
             element[cols * i + j] = v[cols * i + j];
         }
     }

}

Matrix::~Matrix()
{
    delete [] element;
    element = nullptr;
}


const double& Matrix::operator()(int i, int j) const // same as non const doublle
{
    assert(i < rows && j < cols);
    return element[i*cols+j];
}

double& Matrix::operator()(int i, int j)
//The indexed access operator. The indexed access operator is (). For a Matrix
//object m1, the element in row i and column j, m1(i,j), is returned in
//order to access constant Matrix objects we need another index operator which
//returns objects by const reference.

{
    assert(i < rows && j < cols);
    return element[i*cols+j]; // can be written as i*this->cols+j
}

Matrix& Matrix::operator=(const Matrix& m)
//Overloaded assignment operator. The assignment operator perfroms deep copy
{
    if(this != &m)
    {
        delete [] element;
        element = nullptr;
        rows =  m.nrows();
        cols = m.ncols();
        element = new double [rows * cols];
     for (int i = 0; i < rows; i++)
     {
         for (int j = 0; j < cols; j++)
         {
            element[i * cols + j] = m(i, j);
        }
    }
    return *this;
    }
}

Matrix& Matrix::operator+=(const Matrix& x)
{
//    if(rows != m.rows || cols != m.cols)
//    {
//        cout << "Error" << endl;
//
//        else
//        {
//            for(int i = 0; i < rows*cols; i++)
//            {
//                data[i] += m.data[i];
//            }
//        }
//    }
//
//    return *this;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
           element[i * cols + j] += x(i, j);
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& x)
{

//        if(rows != m.rows || cols != m.cols)
//    {
//        cout << "Error" << endl;
//
//        else
//        {
//            for(int i = 0; i < rows*cols; i++)
//            {
//                data[i] -= m.data[i];
//            }
//        }
//    }
//
//    return *this;

    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
           element[i * cols + j] -= x(i, j);
        }
    }
    return *this;
}


Matrix& Matrix::operator*=(const Matrix& m)
{

    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
           element[i * cols + j] *= m(i, j);
        }
    }
    return *this;
//    for (int l = 0; l < rows * cols; l++)
//    assert(cols == m.nrows());
//    Matrix temp(rows, m.ncols(), 0.0);
//
//    for(int i = 0; i < rows; i++)
//    {
//        for(int j = 0; j < m.ncols(); j++)
//        {
//            for (int k = 0; k < cols; k++)
//            {
//                (temp)(i,j) += (*this)(i,k) * (k,j);
//            }
//        }
//    }
//    return *this;


}

Matrix& Matrix::operator*=(double d) // scalar multiplication
{

//    for(int i = 0; i < rows * cols; i++)
//    {
//        element[i] *= d;
//    }
//    return *this;

    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
                element[i] *= d;
        }

    }
    return *this;

//    assert(cols == m.nrows());
//    Matrix Temp(rows, m.ncols(), 0.0);
//
//    for (int i = 0; i < rows; i++)
//    {
//        for(int j = 0; j < m.ncols(); j++)
//        {
//            for(int k = 0; k < cols; k++)
//            {
//                (Temp)(i,j) += (*this)(i,k) * m(k,j);
//
//            }
//
//        }
//    }
//        *this = Temp;
//    return *this;

}

void Matrix::print(ostream& sout) const // insert function
//Insert Function - Member function print outputs the matrix object to the output stream sout neatly
//formatted. Minimum requirement is that the matrix is displayed as a rectangular
//array. The stream insertion operator is overloaded by making a call to print member
//function.
{
    sout << setprecision(3);

    for (int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            sout << setw(5) << (*this)(i,j);
        }
    sout << endl;
    }
}

Matrix operator+(const Matrix& l, const Matrix&r)
// Arithmetic Operator Addition: As given in the class definition with thier usual meaning.
{
    Matrix temp = l;
    temp += r;
    return temp;
    // return l + r;
}

Matrix operator-(const Matrix& l, const Matrix&r)
{
// Arithmetic Operator Subtraction: As given in the class definition with thier usual meaning.
    Matrix temp = l;
    temp -= r;
    return temp;
    // return l - r;
}

Matrix operator*(const Matrix& l, const Matrix&r)
{
// Arithmetic Operator Multiplication: As given in the class definition with thier usual meaning.
    Matrix temp = l;
    temp *= r;
    return temp;
    // return l * r;
}

Matrix operator*(double d, const Matrix& r)
{
// Arithmetic Operator Multiplication: As given in the class definition with thier usual meaning.

    Matrix temp = d;
    temp *= r;
    return temp;
//    return d * r;

}

Matrix operator*(const Matrix& m, double d)
{
// Arithmetic Operator Multiplication: As given in the class definition with thier usual meaning.
    Matrix temp = m;
    temp *= d;
    return temp;
}

ostream& operator<<(ostream& out, const Matrix& x)
//Overload << as nonmember
{
    for ( int i = 0; i < x.nrows(); i++)
    {
        out << "|";
        for (int j = 0; j < x.ncols(); i++)
        {
            out << setw(3) << x(i,j);
            out << setw(3) << "|" << endl;
        }
    }
    return out;
}

int Matrix::ncols() const
{
// return cols as ncols
    return cols;
}

int Matrix::nrows() const
{
// returns rows as nrows
    return rows;
}



