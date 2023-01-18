//**************************************************************
// CPSC2620 Spring 2021
// File: Matrix_test.cc //
// Purpose: To implement the class Matrix as defined, implement the file
//input/output functions specified in sections 1, 2, and 3, and write a test program to thoroughly
//test each function you have implemented. The file input/output functions can be included in
//the test program.
// Written by: Jacqueline Eshriew
// Date: 2021-03-23
//**************************************************************

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Matrix.h"
#include <cassert>

using namespace std;

template <class T>
void ReadFile(vector<T> & a, int nrow, int ncol, const string data);

template <class T>
void writeToFile(vector<T> & a, int len, int nrow, int ncol, const string data);

int main()
{
    cout << "Matrix m3 with number 2 filled: " << endl;
    Matrix m3(3,2,2);
    m3.print(cout);
    cout << endl;

    cout << "Calling Matrix m4 Copy Constructor: " << endl;
    Matrix m4(m3);
    m4.print(cout);
    cout << endl;

    cout << "Calling Matrix m4 Original Cell: " << endl;
    m4.print(cout);
    cout << endl;
    m4(0,1) = 30.3;
    cout << "Calling Matrix m4 Replacing Cell: " << endl;
    m4.print(cout);
    cout << endl;

    Matrix m5;

    m5 = m3;
    m5(0,0) = 2;
    m5(0,1) = 4;
    m5(1,0) = 6;
    m5(1,1) = 1;
    m5(2,0) = 2;
    m5(2,1) = 3;

    cout << "Matrix m5" << endl;
    m5.print(cout);

    vector<double> elem = {1, 2, 3, 4, 5, 6};

    Matrix m6(3, 2, elem);
    cout << endl;
    cout << "Matrix m6" << endl;
    m6.print(cout);
    cout << endl;

    cout << "ADDITION - m6 = m6 += m5 :" << endl;
    m6 += m5;
    m6.print(cout);
    cout << endl;

    cout << "CURRENT m6 Matrix: " << endl;
    m6.print(cout);
    cout << endl;

    cout << "SUBTRACTION - m6 = m6 -= m5 :" << endl;
    m6 -= m5;
    m6.print(cout);
    cout << endl;

    cout << "CURRENT m6 Matrix: " << endl;
    m6.print(cout);
    cout << endl;

    cout << "MULTIPLICATION - m6 = m6 *= m5 :" << endl;
//    m6 *= m5;
    m6 = m6 * m5;
    m6.print(cout);
    cout << endl;

    cout << "CURRENT m6 Matrix: " << endl;
    m6 = m6 * m5;
    m6.print(cout);
    cout << endl;

    cout << "MULTIPLICATION(SCALAR) - m6 = m6 *= 3 :" << endl;
    m6 *= 3;
    m6.print(cout);
    cout << endl;

//    cout << m4(2,2) << endl;
//    m4(2,1) = 30.3;
//    cout << m4(2,1) << endl;
//
//    m4.print(cout);
//     write print function firs and operator functions

    vector<double> MVector;

    int nrow= 0;
    int ncols= 0;

    string data;

    cout << "Enter File Name To Read: " << endl;
    cin >> data;
    cout << endl;

    ReadFile(MVector, nrow, ncols, data);
    Matrix MVector2(nrow, ncols, MVector);

    cout << "Displaying Vector: " << endl;
    cout << MVector2 << endl;

    cin.get();


    return 0;
}

template <class T>
void writeToFile(vector<T> & a, int len, int nrow, int ncol, const string data)
//Write to File. Precondition: vector a has len elements of type T
//Postcondition: The first line of the file contains three integers: nrow and ncol, len, in
//that order; len elements from vector a are written to the file named data starting from
//the second line, 10 elements per line.
{

    ofstream outFile;
    int counter = 0;

    outFile.open(data);
    outFile << setw(5) << len << setw(5) << nrow << setw(5) << ncol << endl;

    for(int i = 0; i < nrow * ncol; i++)
    {
        outFile << setw(5) << a.at(i);
        counter++;


        if(counter == 10)
        {
            outFile << endl;
            counter - 0;
        }
    }
    return;
}

template <class T>
void ReadFile(vector<T> & a, int nrow, int ncol, const string data)
//Read From File. Precondition The first line contains three integers. The remaining
//lines contain data; 10 elements per line, except possibly the last line which may contain
//fewer than 10 elements.
//Postcondition: The three integers in the first line are read into the parameters nrow, ncol,
//and len, in that order len elements are read from file data, into the vector parameter.
{

    ifstream inFile;

    inFile.open(data);

    nrow = 0;
    ncol = 0;
    int TA = 0;
    double temp = 0;

    inFile >> nrow >> ncol >> TA;
    inFile.ignore();

    while(!inFile.eof());
    {
        inFile >> temp;
        a.push_back(temp);
        inFile.ignore();
    }

    inFile.close();

    return;

}
