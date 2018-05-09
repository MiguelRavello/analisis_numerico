#include"lu.h"
//#include"matrix.h"
// 4
int main(){
    vector<vector<double> > matriz = {{ 0, -2, 1},
                                      {20, -7, 12},
                                      {-8, 13, 17}};
    vector<double> b= {11, 70, 17};
    LU<double> px(3,3);
    try {
        vector<double> rpta=px.solucion(matriz,b);
        px.proof();
        cout<<"..............................."<<endl;
        cout<<"vector solucion"<<endl;
        for(vector<double>::iterator it=rpta.begin();it!=rpta.end();it++)
            cout<<*it<<" "<<endl;
    } catch(const char* msg){
        cerr << msg << endl;
    }
    return 0;
}


