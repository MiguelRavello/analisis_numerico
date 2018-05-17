#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

typedef double nat_t;

nat_t derivada(nat_t (*f)(nat_t),nat_t,nat_t);

nat_t derivada(nat_t (*f)(nat_t),nat_t x,nat_t delta=0.001){
    nat_t r= (f(x+delta)-f(x))/delta;
    return r;
}

nat_t newton(nat_t (*f)(nat_t),nat_t &xo,nat_t tol){
    ofstream excel;
    excel.open("newton.csv",ios::trunc | ios::out);
    nat_t xn=xo-(1.0*f(xo)/derivada(f,xo));
    nat_t error=abs(f(xn));
    int i=0;
    excel<<"i"<<","<<"xn"<<","<<"xo"<<","<<"|f(xn)|"<<endl;
    excel<<i<<","<<xn<<","<<xo<<","<<error<<endl;
    i++;
    while(error>tol){
        xo=xn;
        xn=xo-(1.0*f(xo)/derivada(f,xo));
        error=abs(f(xn));
        cout<< i<<" "<<xn<<" "<<xo<<" "<<error<<endl;
        excel<<i<<","<<xn<<","<<xo<<","<<error<<endl;
        i++;
    }
    return xn;
}

nat_t fun1(nat_t x){
    return (pow(x,2)-1)/3.0;
}

int main(){
    nat_t seed=3;
    nat_t tol=0.001;
    nat_t r;
    r=newton(fun1,seed,tol);
    cout<<r;
    return 0;
}



