#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

typedef double nat_t;

nat_t puntofijo(nat_t (*g)(nat_t),nat_t &po,nat_t tol){
    ofstream excel;
    excel.open("pf.csv",ios::trunc | ios::out);
    nat_t p;
    p=g(po);
    int i=0;
    excel<<"i"<<","<<"p"<<","<<"po"<<","<<"|p-po|"<<endl;
    excel<<0<<","<<p<<","<<po<<","<<abs(p-po)<<endl;
    while(abs(p-po)>tol){
        po=p;
        p=g(po);
        cout<< i<<" "<<p<<" "<<po<<" "<<abs(p-po)<<endl;
        excel<<i<<","<<p<<","<<po<<","<<abs(p-po)<<endl;
        i++;
    }
    return p;
}

nat_t fun1(nat_t x){
    return (pow(x,2)-1)/3.0;
}

int main(){
    nat_t seed=3;
    nat_t tol=0.001;
    nat_t r;
    r=puntofijo(fun1,seed,tol);
    cout<<r;
    return 0;
}
