#include"plu.h"
//#include"matrix.h"

int main(){
    vector<vector<double> > matriz = {{ -1, 2, -1, 0},
                                      {2, -1, 1, 1},
                                      {4, 1, -2, 1},
                                      {3, 2, -3,4}};
    vector<double> b= {5, 7, 1, 10};
    PLU<double> px(4,4);
    vector<double> rpta=px.solucion(matriz,b);
    px.proof();
    cout<<"..............................."<<endl;
    cout<<"vector solucion"<<endl;
    for(vector<double>::iterator it=rpta.begin();it!=rpta.end();it++)
        cout<<*it<<" "<<endl;
    return 0;
}


