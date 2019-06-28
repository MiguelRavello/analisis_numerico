#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
#include"lu.h"
using namespace std;

template<class T>
class Matrix;

template<class T>
ostream& operator<< (ostream&, const Matrix<T>&);

template<class T>
class Matrix {
private:
	T **m_matrix;
	int m_row;
	int m_col;
    friend ostream& operator<< <>(ostream&, const Matrix&);
    template<class U> friend class LU;
public:
	Matrix():m_row(0),m_col(0){}
	Matrix(int,int);
    Matrix(const Matrix &m);
    ~Matrix();

    Matrix<T> operator+ (const Matrix &o);
    Matrix<T> operator* (const Matrix &o);
    void operator= (const Matrix &o);

    void resizeCol(int size);
    void insertCol(vector<T> xs);
    void inicializar();
    void setMatrix(const vector<vector<T> > xs);
    void zerox();
    void identidad();
    Matrix<T> inversa();
    Matrix<T> transpuesta();
    void imprimir();

    vector<T> getCol(const int pos);
    void escalonar();
    void swapRow(int fila_1,int fila_2);
    void escalonarPivote();
    vector<T> sust_regresiva(vector<T> xs);
    vector<T> sust_progresiva(vector<T> xs);
    vector<T> elim_gauss(vector<T> xs);
};

#endif
