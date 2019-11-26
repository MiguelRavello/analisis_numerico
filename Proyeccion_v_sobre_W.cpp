#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

template<class T>
T productoInterno(const vector<T> xs,const vector<T> ys){
    int x=xs.size();
    int y=ys.size();
    T rpta=0;
    if(x==y){
        for(int i=0;i<x;i++){
            rpta+=xs[i]*ys[i];
        }
    }
    return rpta;
}
template<class T>
vector<T> sumaVectores(const vector<T> xs,const vector<T> ys){
    vector<T> r;
    if(xs.size()==ys.size()){
        for(int i=0;i<xs.size();i++){
            r.push_back(xs[i]+ys[i]);
        }
    }
    return r;
}

template<class T>
vector<T> productoPorEscalar(T k,const vector<T> xs){
    vector<T> r;
    for(int i=0;i<xs.size();i++){
        T a=k*xs[i];
        r.push_back(a);
    }
    return r;
}

template<class T>
vector<vector<T> > gramSchmith(const vector<vector<T> > Base){
    vector<vector<T> > xs;
    for(int i=0;i<Base.size();i++){
        vector<T> sumaProyecciones(Base[0].size(),0);
        vector<T> v=Base[i];
        for(int j=0;j<i;j++){
            vector<T> u=xs[j];
            T k=productoInterno<T>(v,u);
            vector<T> proy=productoPorEscalar<T>(k,u);
            sumaProyecciones=sumaVectores<T>(sumaProyecciones,proy);
        }
        sumaProyecciones=productoPorEscalar<T>(-1,sumaProyecciones);
        vector<T> w=sumaVectores<T>(v,sumaProyecciones);
        T modulo=1.0/sqrt(productoInterno<T>(w,w));
        w=productoPorEscalar<T>(modulo,w);
        xs.push_back(w);
    }
    return xs;
}

template<class T>
vector<T> proyeccionVW(const vector<T> v,const vector<vector<T> > W){
    vector<vector<T> > base=gramSchmith(W);
    vector<T> sumaProyecciones(base[0].size(),0);
    for(int i=0;i<base.size();i++){
        vector<T> u=base[i];
        T k=productoInterno<T>(u,v);
        vector<T> proyeccion=productoPorEscalar<T>(k,u);
        sumaProyecciones=sumaVectores<T>(sumaProyecciones,proyeccion);
    }
    return sumaProyecciones;
}

int main(){
    /*vector<vector<float> > B={{1,1,1},
                          {1,1,0},
                          {1,0,0}};
    vector<vector<float> > r=gramSchmith(B);
    for(int i=0;i<r.size();i++){
        for(int j=0;j<r[0].size();j++){
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector<float> v={1,-1,0};
    vector<vector<float> > W={{1,-1,0},{0,1,-1}};
    vector<float> p=proyeccionVW(v,W);
    for(int i=0;i<p.size();i++){
            cout<<p[i]<<" ";
    }
    cout<<endl;

    return 0;
}
