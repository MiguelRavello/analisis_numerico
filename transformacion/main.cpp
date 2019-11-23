#include"transformacion.cpp"

int main(){
    vector<float> v={1,2};
    vector<vector<float> > t1={{2,1},
                               {1,-1},
                               {1,1}};
    Transformacion<float> A(2,3,t1);
    vector<float> r=A.doTransformar(v);
    return 0;
}
