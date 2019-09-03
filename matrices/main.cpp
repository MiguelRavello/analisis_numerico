#include"matrix.h"
#include"matrix.cpp"
int main(){
    vector<double> xs={1,2,3};
    vector<vector<double> > matriz = {{ 1, 2, 1},
                                      {-1, 1, 1},
                                      {1, -1, 2}};
    /*vector<vector<double> > matriz = {{ 1, 2, -1, 2},
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
    cout<<T<<endl;*/
    Matrix<double> A(3,3);
    A.setMatrix(matriz);
    cout<<A.rangoAumentadoComparado(xs);
    return 0;
}
