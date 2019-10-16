#ifndef TRANSFORMACION_H
#define TRANSFORMACION_H

#include"matrix.cpp"

template<class T>
class Transformacion{
public:
    int m_partida; //m
    int m_llegada; //n
    Matrix<T> m_T; //matriz de la transformacion
public:
    Transformacion(int,int,const vector<vector<T> >);
    vector<T> doTransformar(const vector<T>);
};




#endif
