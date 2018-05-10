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
    Jacobi(){}

    void MetJacobi(const vector<vector<T> > A, const vector<T> b,const vector<T> &Xo,int n){
        this->m_A(A.size);// completar

        this->m_A.setMatrix(A)
        this->m_B(b.size(),0);
        this->m_B.insertCol(b);
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
        this->m_X(Xo.size(),0);
        this->m_X.insertCol(Xo);
    }

    void MetJacobi2(const vector<vector<T> > A, const vector<T> b,const vector<T> &Xo,T tol){
        this->m_A.setMatrix(A)
        this->m_B(b.size(),0);
        this->m_B.insertCol(b);
        vector<T> X(Xo.size(),1);
        T rpta=abs(sumArr(X)-sumArr(Xo));
        while(rpta>tol)
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
