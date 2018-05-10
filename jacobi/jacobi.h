#ifndef JACOBI_H
#define JACOBI_H

#include"matrix.h"
#include<cmath>

template<class T>
T sumArr(vector<T>);

template<class T>
T sumArr(vector<T> xs){
    T ans=0;
    for(vector<T>::iterator it=xs.begin();it!=xs.end();it++){
        ans+=abs(*(it));
    }
    return ans;
}

template<class T>
class Jacobi{
public:
    Matrix<T> m_A;
    Matrix<T> m_X;
    Matrix<T> m_b;

public:
    Jacobi(const vector<vector<T> > A, const vector<T> b){
        Matrix<T> c_A(A);
        this->m_A=c_A;
        Matrix<T> c_b(b);
        this->m_b=c_b;
    }

    void MetJacobi(const vector<T> &Xo,int n){
        for(int k=0;k<n;k++){
            for(int i=0;i<this->m_A.m_row;i++){
                T s=0;
                for(int j=0;j<this->m_A.m_col;j++){
                    if(j==i)
                        continue;
                    s+=this->m_A.m_matrix[i][j]*Xo[j];
                }
                Xo[j]=(b[j]-s)/this->m_A.m_matrix[i][i];
            }
        }
        Matrix<T> c_X(Xo);
        this->m_X=c_X;
    }

    void MetJacobi2(const vector<T> &Xo,T tol){
        vector<T> X(Xo.size(),1);
        T rpta=abs(sumArr(X)-sumArr(Xo));
        while(rpta>tol){
            vector<T> copia(Xo);
            for(int i=0;i<this->m_A.m_row;i++){
                T s=0;
                for(int j=0;j<this->m_A.m_col;j++){
                    if(j==i)
                        continue;
                    s+=this->m_A.m_matrix[i][j]*Xo[j];
                }
                Xo[j]=(b[j]-s)/this->m_A.m_matrix[i][i];
            }
            rpta=abs(sumArr(copia)-sumArr(Xo));
        }
        this->m_X(Xo.size(),0);
        this->m_X.insertCol(Xo);
    }

};


#endif
