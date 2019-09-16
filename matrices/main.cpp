#include"matrix.h"
#include"matrix.cpp"
int main(){
    vector<double> xs={1,2,3};
    vector<vector<double> > b1 = {{ 1, 0, 0},
                                  { 1, 1, 0},
                                  { 1, 1, 1}};
    vector<vector<double> > b2 = {{ 1, 1, 0},
                                  { 1, 0, 1},
                                  { 0, 1, 1}};
  /*Matrix<double> A(4,4), B(4,4);
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
    /*matrix escalonada reducida
    Matrix<double> A(3,3);
    A.setMatrix(matriz);
    A.insertCol(xs);
    cout<<A<<endl;
    A.escalonadoReducido();
    cout<<A<<endl;*/
    Matrix<double> A(3,3);
    A.setMatrix(b1);
    /*Matrix<double> M12=A.cambioBase(b2);
    cout<<M12<<endl;*/
    Matrix<double> R=A.coordenadaB1_B2(b2,xs);
    cout<<"coordenadas en B2"<<endl;
    cout<<R<<endl;
    return 0;
}
