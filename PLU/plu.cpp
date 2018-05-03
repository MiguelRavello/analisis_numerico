#include"plu.h"
//#include"matrix.h"

int main(){
    vector<vector<double> > matriz = {{0, 1, 2},
                                      {1, 1, -1},
                                      {2, 3, 1}};
    PLU<double> px(3,3);
    px.desPLU(matriz);
    px.print();
    return 0;
}
