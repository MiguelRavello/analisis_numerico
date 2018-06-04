#include"newton.h"

int main(){
    Newton<double> N(2); // 2 variables
    vector<double> seed={2,2};
    N.converger(seed,0.001);
    Matrix<double> r(N.m_tamano,0);
    r.insertCol(N.v_X);
    cout<<r;
    return 0;
}
