#ifndef PLU_H
#define PLU_H

#include"matrix.h"

template<class T>
class PLU{
public:
    int m_fila;
    int m_columna;
    Matrix<T> m_A;
    Matrix<T> m_P;
    Matrix<T> m_L;
    Matrix<T> m_U;
public:
    PLU(int,int);
    void desPLU(const vector<vector<T> > xs); //setear A
    void proof();
    vector<T> solucion(const vector<vector<T> > xs,const vector<T> bs);
};

template<class T>
PLU<T>::PLU(int fila,int col):m_fila(fila),m_columna(col){
    Matrix<T> A(m_fila,m_columna);
    m_A = A;
    Matrix<T> P(m_fila,m_fila);
    m_P = P;
    Matrix<T> L(m_fila,m_fila);
    m_L = L;
    Matrix<T> U(m_fila,m_columna);
    m_U = U;
}

template<class T>
void PLU<T>::desPLU(const vector<vector<T> > xs){
    this->m_A.setMatrix(xs);
    this->m_P.identidad();
    this->m_L.zerox();
    this->m_U=this->m_A;

    for(int j=0;j<this->m_U.m_row - 1;j++){
        T max_val=this->m_U.m_matrix[j][j];
        int max_file=j;
        for(int x=j+1;x<this->m_U.m_row;x++){
            if(max_val<this->m_U.m_matrix[x][j]){
                max_val=this->m_U.m_matrix[x][j];
                max_file=x;
            }
        }
        if(j!=max_file){
            this->m_U.swapRow(j,max_file);
            this->m_P.swapRow(j,max_file);
            this->m_L.swapRow(j,max_file);
        }
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
void PLU<T>::proof(){
    Matrix<T> t1;
    Matrix<T> t2;
    cout<<"..................."<<endl;
    cout<<"Matrix P"<<endl;
    cout<<this->m_P<<endl;
    cout<<"..................."<<endl;
    cout<<"Matrix L"<<endl;
    cout<<this->m_L<<endl;
    cout<<"..................."<<endl;
    cout<<"Matrix U"<<endl;
    cout<<this->m_U<<endl;
    cout<<"..................."<<endl;
    cout<<"Matrix PA"<<endl;
    t1=m_P*m_A;
    cout<<t1<<endl;
    cout<<"..................."<<endl;
    cout<<"Matrix LU"<<endl;
    t2=m_L*m_U;
    cout<<t2<<endl;
}

template<class T>
vector<T> PLU<T>::solucion(const vector<vector<T> > xs, const vector<T> bs){
    this->desPLU(xs);
    vector<T> ys(m_fila,0);
    Matrix<T> B(m_fila,0);
    B.insertCol(bs);

    Matrix<T> PB;
    PB=this->m_P * B;

    vector<T> y_temp=PB.getCol(PB.m_col-1);
    vector<T> y;
    y=this->m_L.sust_progresiva(y_temp);

    vector<T> x;
    x=this->m_U.sust_regresiva(y);
    //Matrix<T> rpta(x.size(),0);
    //rpta.insertCol(x);
    return x;
}

#endif
