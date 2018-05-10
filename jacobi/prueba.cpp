#include"matrix.h"

int main(){
    vector<vector<double> > matriz = {{ 4,  1, -1},
                                          { 1, -3,  1},
                                          {-8, 131, 17}};
    vector<double> arr={1,2,3};
    Matrix<double> A(matriz);
    Matrix<double> B(arr);
    cout<<A<<endl;
    cout<<B<<endl;
    return 0;
}
