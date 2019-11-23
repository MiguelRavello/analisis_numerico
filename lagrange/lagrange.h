#ifndef LAGRANGE_H
#define LAGRANGE_H

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Punto{
public:
    T m_x;
    T m_y;
public:
    Punto(T a=0,T b=0):m_x(a),m_y(b){}
    Punto(Punto &o):m_x(o.m_x),m_y(o.m_y){}
};
/* profe q libro usa actualmente */
template<class T>
class Lagrange{
public:
    vector<T> m_A;
    vector<T> m_B;
    vector<T> m_rpta;
public:
    Lagrange(){}
    Lagrange(const vector<T> A,const vector<T> B);
    void solucion();

    friend vector<T> convolucion(vector<T> A, vector<T> B);
    friend vector<T> sumaVec(vector<T> A,vector<T> B);
};
template<class T>
Lagrange<T>::Lagrange(const vector<T> A,const vector<T> B):m_A(A),m_B(B){}

template<class T>
void Lagrange<T>::solucion(){
        
}

template<class T>
vector<T> sumaVec(vector<T> A, vector<T> B){
    int minimo;
    if(A.size()>B.size())
        minimo=B.size();
    else
        minimo=A.size();
    vector<T> r;
    for(int i=0;i<minimo;i++)
        r.push_back(A[i]+B[i]);
    return r;
}
template<class T>
vector<T> convolucion(vector<T> A,vector<T> B){
    if(A.empty())
        return B;
    else if(B.empty())
        return A;
    else{
        int tam=A.size()+B.size() - 1;
        vector<T> r(tam,0);
        for(int i=0;i<B.size();i++){
            for(int j=0;j<A.size();j++){
                r[j+i]+=B[i]*A[j];
            }
        }
        return r;
    }
}



#endif
