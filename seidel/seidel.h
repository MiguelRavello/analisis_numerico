#ifndef SEIDEL_H
#define SEIDEL_H

#include"matrix.h"
#include<cmath>


template<class T>
T sumArr(vector<T> xs){
    T ans=0;
    for(int i=0;i<xs.size();i++){
        ans+=abs(xs[i]);
    }
    return ans;
}

template<class T>
T normaP(vector<T> xs,T p){
    T ans=0;
    for(int i=0;i.size();i++){
        ans+=pow(xs[i],p);
    }
    return pow(ans,1.0/p);
}

template<class T>
class Seidel {
public:
    Matrix<T> m_A;
    Matrix<T> m_X;
    Matrix<T> m_b;

public:
    Seidel(const vector<vector<T> > A, const vector<T> b){
        Matrix<T> c_A(A);
        this->m_A=c_A;
        Matrix<T> c_b(b);
        this->m_b=c_b;
    }

    void MetSeidel(vector<T> &Xo,int n){
        for(int k=0;k<n;k++){
            for(int i=0;i<this->m_A.m_row;i++){
                T s=0;
                for(int j=0;j<this->m_A.m_col;j++){
                    if(j==i)
                        continue;
                    s+=this->m_A.m_matrix[i][j]*Xo[j];
                }
                Xo[i]=(this->m_b.m_matrix[i][0]-s)/this->m_A.m_matrix[i][i];
            }
        }
        Matrix<T> c_X(Xo);
        this->m_X=c_X;
    }

    void MetSeidel2(vector<T> &Xo,T tol){
        T rpta=1;
        while(rpta>tol){
            vector<T> copia(Xo);
            for(int i=0;i<this->m_A.m_row;i++){
                T s=0;
                for(int j=0;j<this->m_A.m_col;j++){
                    if(j==i)
                        continue;
                    s+=this->m_A.m_matrix[i][j]*Xo[j];
                }
                Xo[i]=(this->m_b.m_matrix[i][0]-s)/this->m_A.m_matrix[i][i];
            }
            rpta=abs(sumArr<T>(copia)-sumArr<T>(Xo));
        }
        Matrix<T> c_X(Xo);
        this->m_X=c_X;
    }

};


#endif
