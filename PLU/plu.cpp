#include"plu.h"
//#include"matrix.h"

int main(){
    vector<vector<double> > matriz = {{ 2,  2, 4, 5},
                                      {-1, -1, 0, 1},
                                      { 3,  1, 3, 1},
                                      { 4,  0, 1, 4}};
    vector<double> b= {1, 2, 3, 4};
    PLU<double> px(4,4);
    vector<double> rpta=px.solucion(matriz,b);
    px.proof();
    cout<<"..............................."<<endl;
    cout<<"vector solucion"<<endl;
    for(vector<double>::iterator it=rpta.begin();it!=rpta.end();it++)
        cout<<*it<<" "<<endl;
    return 0;
}
