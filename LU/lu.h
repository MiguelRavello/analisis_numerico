#ifndef LU_H
#define LU_H

#include"matrix.h"

template<class T>
class LU{
public:
    int m_fila;
    int m_columna;
    Matrix<T> m_A;
    Matrix<T> m_L;
    Matrix<T> m_U;
public:
    LU(int,int);
    void desLU(const vector<vector<T> > xs); //setear A
    void proof();
    vector<T> solucion(const vector<vector<T> > xs,const vector<T> bs);
};

template<class T>
LU<T>::LU(int fila,int col):m_fila(fila),m_columna(col){
    Matrix<T> A(m_fila,m_columna);
    m_A = A;
    Matrix<T> L(m_fila,m_fila);
    m_L = L;
    Matrix<T> U(m_fila,m_columna);
    m_U = U;
}

template<class T>
void LU<T>::desLU(const vector<vector<T> > xs){
    this->m_A.setMatrix(xs);
    this->m_L.zerox();
    this->m_U=this->m_A;

    for(int j=0;j<this->m_U.m_row - 1;j++){
        for(int i=j+1;i<this->m_U.m_row;i++){
            T m=this->m_U.m_matrix[i][j]/this->m_U.m_matrix[j][j];
            this->m_L.m_matrix[i][j]=m;
            for(int k=0;k<this->m_U.m_col;k++){
                this->m_U.m_matrix[i][k]-=m * this->m_U.m_matrix[j][k];
            }
        }
    }
    Matrix<T> I(m_fila,m_fila);
    I.identidad();
    this->m_L = this->m_L + I;
}

template<class T>
void LU<T>::proof(){
    Matrix<T> t2;
    cout<<"..................."<<endl;
    cout<<"Matrix L"<<endl;
    cout<<this->m_L<<endl;
    cout<<"..................."<<endl;
    cout<<"Matrix U"<<endl;
    cout<<this->m_U<<endl;
    cout<<"..................."<<endl;
    cout<<"Matrix LU"<<endl;
    t2=m_L*m_U;
    cout<<t2<<endl;
}

template<class T>
vector<T> LU<T>::solucion(const vector<vector<T> > xs, const vector<T> bs){
    this->desLU(xs);
    vector<T> ys(m_fila,0);
    Matrix<T> B(m_fila,0);
    B.insertCol(bs);
 //   cout<<PB<<endl;
    vector<T> y_temp=B.getCol(B.m_col-1);
    vector<T> y;
    y=this->m_L.sust_progresiva(y_temp);
 //   for(int i=0;i<m_fila;i++)
 //       cout<<y_temp[i]<<" "<<y[i]<<endl;
    vector<T> x;
    x=this->m_U.sust_regresiva(y);
    return x;
}

#endif
