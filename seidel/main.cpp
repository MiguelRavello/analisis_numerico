#include"seidel.h"

int main(){
    vector<vector<double> > A = {{ 3, -1, 1},
                                 { 1,  -4,1},
                                 { -1, 1,  -4}};
    vector<double> b = {5,-5,2};
    vector<double> seed = {1,1,1};
    Seidel<double> S(A,b);
    S.MetSeidel_P(seed,3,0.001);
    cout<<S.m_X<<endl;
    return 0;
}
