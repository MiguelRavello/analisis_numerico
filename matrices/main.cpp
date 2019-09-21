#include"matrix.h"
#include"matrix.cpp"
/* matrixcalc.org/es
 * solucion de sistemas lineales */
int main(){
    vector<float> xs={3,-1,2};
    vector<vector<float> > b1 = {{ 1, 0, 0},
                                  { 0, 1, 0},
                                  { 0, 0, 1}};
    vector<vector<float> > b2 = {{ 1, 1, 1},
                                  { 1,1, 0},
                                  { 1,0, 0}};
    /* ++++++++++++++ */
    vector<float> v={2,-1,3};
    vector<vector<float> > ba1 = {{ 1, 0, 0},
                                  { 0, 1, 0},
                                  { 0, 0, 1}};
    vector<vector<float> > ba2 = {{ 1, 1,0},
                                 { 0,1, 1},
                                 { 1, 0, 1}};
    Matrix<float> A(3,3), B(3,3);
    A.setMatrix(ba1);
    B.setMatrix(ba2);
    Matrix<float> R12=A.coordenadaB1_B2(ba2,v);
    cout<<".................."<<endl;
    Matrix<float> R21=B.coordenadaB1_B2(ba1,v);
    return 0;
}
