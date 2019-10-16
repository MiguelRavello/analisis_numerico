#include"transformacion.h"

template<class T>
Transformacion<T>::Transformacion(int m,int n,const vector<vector<T> > xs):m_partida(m),m_llegada(n){
    Matrix<T> Temp(m_llegada,m_partida);
    m_T=Temp;
    m_T.setMatrix(xs);
}

template<class T>
vector<T> Transformacion<T>::doTransformar(const vector<T> xs){
    Matrix<T> v(m_partida,0);
    v.insertCol(xs);
    Matrix<T> R;
    R = m_T * v;
    cout<<"vector transformado"<<endl;
    cout<<R<<endl;
    vector<T> r=R.getCol(R.m_col-1);
    return r;
}
