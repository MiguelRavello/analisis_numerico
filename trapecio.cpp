#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;
#define PI 3.14159265

template<class T>
T trapecio(T a,T b,T (*f)(T),int n){
    T h=(b-a)/n;
    T sumatoria=0;
    for(int i=1;i<n;i++){
        sumatoria+=f(a+i*h);
    }
    sumatoria=(f(a)+2*sumatoria+f(b))*h/2.0;
    return sumatoria;
}

template<class T>
T productoInterno(T a,T b,T (*f)(T,T,T),T (*g)(T,T,T),int n,int m,T per,int iterar){
    T h=(b-a)/iterar;
    T sumatoria=0;
    for(int i=1;i<iterar;i++){
        sumatoria+=f(a+i*h,n,per)*g(a+i*h,m,per);
    }
    sumatoria=(f(a,n,per)+2*sumatoria+f(b,m,per))*h/2.0;
    return sumatoria;
}

template<class T>
T fun1(T x){
    return x*x;
}

template<class T>
T funS(T x,T n,T periodo){
    return sin(2*n*PI*x/periodo);
}

template<class T>
T funC(T x,T m,T periodo){
    return cos(2*m*PI*x/periodo);
}

int main(){
    float a=0;
    float b=1;
    /*                                        limites, funciones           ,n,m,T,iteraciones*/
    cout<<"Cosn Cosm: "<<productoInterno<float>(a,b,funC<float>,funC<float>,2,4,1,100)<<endl;
    cout<<"Cosm Cosm: "<<productoInterno<float>(a,b,funC<float>,funC<float>,2,2,1,100)<<endl;
    cout<<"Senn Senm: "<<productoInterno<float>(a,b,funS<float>,funS<float>,2,4,1,100)<<endl;
    cout<<"Senm Senm: "<<productoInterno<float>(a,b,funS<float>,funS<float>,2,2,1,100)<<endl;
    cout<<"Senm Cosn: "<<productoInterno<float>(a,b,funS<float>,funC<float>,2,4,1,100)<<endl;
    cout<<"Senm Cosm: "<<productoInterno<float>(a,b,funS<float>,funC<float>,2,2,1,100)<<endl;

}
