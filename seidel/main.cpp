#include"seidel.h"

int main(){
    vector<vector<double> > A = {{ 4,  1, -1},
                                 { 1, -3,  1},
                                 { 1,  1, -4}};
    vector<double> b = {4,-1,-2};
    vector<double> seed = {0,0,0};
    Seidel<double> S(A,b);
    S.MetJacobi2(seed,0.00001);
    cout<<S.m_X<<endl;
    return 0;
}
