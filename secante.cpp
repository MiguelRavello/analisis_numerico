#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

typedef double nat_t;

nat_t secante(nat_t (*f)(nat_t),nat_t &ro,nat_t &r1, nat_t tol){
    ofstream excel;
    excel.open("secante.csv",ios::trunc | ios::out);
    nat_t r;
    r=r1-(1.0)*f(r1)*(r1-ro)/(f(r1)-f(ro));
    int i=0;
    excel<<"i"<<","<<"r"<<","<<"ro"<<","<<"r1"<<","<<"|r-r1|"<<endl;
    excel<<i<<","<<r<<","<<ro<<","<<r1<<","<<abs(r-r1)<<endl;
    i++;
    while(abs(r-r1)>tol){
        ro=r1;
        r1=r;
        r=r1-(1.0)*f(r1)*(r1-ro)/(f(r1)-f(ro));
        cout<<i<<","<<r<<","<<ro<<","<<r1<<","<<abs(r-r1)<<endl;
        excel<<i<<","<<r<<","<<ro<<","<<r1<<","<<abs(r-r1)<<endl;
        i++;
    }
    return r;
}

nat_t fun1(nat_t x){
    return (pow(x,2)-1)/3.0;
}

int main(){
    nat_t po=4;
    nat_t p1=3;
    nat_t tol=0.001;
    nat_t r;
    r=secante(fun1,po,p1,tol);
    cout<<r;
    return 0;
}


