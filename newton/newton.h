#ifndef NEWTON_H
#define NEWTON_H

#include"plu.h"
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
vector<T> fun1(const vector<T> xs){
    vector<T> ys;
    T a=cos(xs[0]-xs[1])+exp(cos(xs[0])-xs[1])-1;
    T b=atan(xs[0]*xs[1])+log(pow(xs[0],2)+pow(xs[1],3))-2;
    ys.push_back(a);
    ys.push_back(b);
    return ys;
}

template<class T>
vector<vector<T> > jacobiano(const vector<T> xs){
    T a=(-1)*sin(xs[0]-xs[1])+exp(cos(xs[0])-xs[1])*((-1)*sin(xs[0])); //df1/dx
    T b=sin(xs[0]-xs[1])+exp(cos(xs[0]-xs[1]))*(-1);  // df1/dy
    T c=(xs[1]/(1+pow(xs[0],2)*pow(xs[1],2))) + ((2*xs[0])/(pow(xs[0],2)+pow(xs[1],3)));    // df2/dx
    T d=(xs[0]/(1+pow(xs[0],2)*pow(xs[1],2))) + (3*pow(xs[1],2)/(pow(xs[0],2)+pow(xs[1],3)));   // df2/dy
    vector<vector<T> > ys={{a,b},{c,d}};
    return ys;
}

template<class T>
class Newton{
public:
    int m_tamano;
    vector<T> v_X;
public:
    Newton(int);
    void converger(const vector<T> xs,const T tol);
};

template<class T>
Newton<T>::Newton(int tam):m_tamano(tam){}

template<class T>
void Newton<T>::converger(const vector<T> xs,const T tol){
    T error=1;
    vector<T> xo(xs);
    while(error>tol){
        vector<T> xf;
        vector<vector<T> > jacob;
        xf=fun1<T>(xo);
        jacob=jacobiano<T>(xo);
        PLU<T> abc(m_tamano,m_tamano);
        vector<T> rpta=abc.solucion(jacob,xf);
        Matrix<T> m_X(m_tamano,0);
        Matrix<T> m_V(m_tamano,0);
        m_X.insertCol(xo);
        m_V.insertCol(rpta);
        Matrix<T> R = m_X - m_V;
        error=abs(sumArr<T>(R.getCol(0))-sumArr<T>(xo));
        xo.clear();
        xo=R.getCol(0);
    }
    v_X=xo;
}

#endif
