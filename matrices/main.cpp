#include"matrix.h"
#include"matrix.cpp"
int main(){
    /*vector<vector<double> > matriz = {{ 0, -2, 1},
                                      {20, -7, 12},
                                      {-8, 13, 17}};*/
    vector<vector<double> > matriz = {{ 1, 2, -1, 2},
                                      {2, 2, -1, 1},
                                      {-1, -1, 1, -1},
                                      {1, 2, 3, 4}};
    Matrix<double> A(4,4), B(4,4);
    A.setMatrix(matriz);
    cout<<A<<endl;
    Matrix<double> C;
    C=A.inversa();
    cout<<A<<endl;
    cout<<"............"<<endl;
    cout<<C<<endl;
    cout<<"............"<<endl;
    Matrix<double> T=A.transpuesta();
    cout<<T<<endl;
    return 0;
}
