#include"jacobi.h"

int main(){
    vector<vector<double> > A = {{ 4,  1, -1},
                                 { 1, -3,  1},
                                 { 1,  1, -4}};
    vector<double> b = {4,-1,-2};
    vector<double> seed = {0,0,0};
    Jacobi<double> J(A,b);
    J.MetJacobi2(seed,0.00001);
    cout<<J.m_X<<endl;
    return 0;
}
