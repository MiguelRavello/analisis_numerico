#include"matrix.h"
#include"matrix.cpp"
int main(){
    vector<double> xs={34,0,16};
    vector<vector<double> > matriz = {{ 1.06, 0, 2},
                                      {0.27,-2.6512, 1},
                                      {1, 1, 0}};
    /*vector<vector<double> > matriz = {{ 2, 3, -1, 4},
                                      {1, -1, 1, 1},
                                      {3, -2, 1, 2},
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
    /* rango */
    /*Matrix<double> A(3,3);
    A.setMatrix(matriz);
    cout<<A.rangoAumentadoComparado(xs);*/
    /*matrix escalonada reducida*/
    Matrix<double> A(3,3);
    A.setMatrix(matriz);
    A.insertCol(xs);
    cout<<A<<endl;
    A.escalonadoReducido();
    cout<<A<<endl;
    return 0;
}
