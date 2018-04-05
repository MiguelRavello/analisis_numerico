#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#define PI 3.14159265
typedef double nat_t;


nat_t biseccion(nat_t a,nat_t b,nat_t (*f)(nat_t),int n){
	ofstream excel;
	excel.open("biseccion.csv",ios::trunc | ios::out);
	nat_t m=(a+b)/2.0;
	excel<<"i"<<","<<"a"<<","<<"b"<<","<<"m"<<","<<"f(m)"<<endl;
	excel<<0<<","<<a<<","<<b<<","<<m<<","<<f(m)<<endl;
	for(int i=1;i<=n;i++){
		if(f(a)*f(m)<0)
			b=m;
		else
			a=m;
		m=(a+b)/2.0;
		cout<<i<<" "<<a<<" "<<b<<" "<<m<<" "<<f(m)<<endl;
		excel<<i<<","<<a<<","<<b<<","<<m<<","<<f(m)<<endl;
	}
	return m;
}

nat_t biseccion2(nat_t a,nat_t b,nat_t (*f)(nat_t),nat_t tol){
	ofstream excel2;
	excel2.open("biseccion2.csv",ios::trunc | ios::out);
	nat_t m=(a+b)/2.0;
	int i=1;
	excel2<<"i"<<","<<"a"<<","<<"b"<<","<<"m"<<","<<"|f(m)|"<<endl;
	excel2<<0<<","<<a<<","<<b<<","<<m<<","<<abs(f(m))<<endl;
	while(abs(f(m))>tol){
		if(f(a)*f(m)<0)
			b=m;
		else
			a=m;
		m=(a+b)/2.0;
		cout<<i<<" "<<a<<" "<<b<<" "<<m<<" "<<abs(f(m))<<endl;
		excel2<<i<<","<<a<<","<<b<<","<<m<<","<<abs(f(m))<<endl;
		i++;
	}
	return m;
}

nat_t biseccion3(nat_t a,nat_t b,nat_t (*f)(nat_t),nat_t tol){
	ofstream excel3;
	excel3.open("biseccion3.csv",ios::trunc | ios::out);
	nat_t m=(a+b)/2.0;
	int i=1;
	excel3<<"i"<<","<<"a"<<","<<"b"<<","<<"m"<<","<<"|a-b|"<<","<<"f(m)"<<endl;
	excel3<<0<<","<<a<<","<<b<<","<<m<<","<<abs(a-b)<<","<<f(m)<<endl;
	while(abs(a-b)>tol){
		if(f(a)*f(m)<0)
			b=m;
		else
			a=m;
		m=(a+b)/2.0;
		cout<<i<<" "<<a<<" "<<b<<" "<<m<<" "<<abs(a-b)<<" "<<f(m)<<endl;
		excel3<<i<<","<<a<<","<<b<<","<<m<<","<<abs(a-b)<<","<<f(m)<<endl;
		i++;
	}
	return m;
}

nat_t fun1(nat_t x){
	return 3*pow(x,5)+2*x*exp(-x)+5*cos(x)-4;
}

nat_t fun2(nat_t x){
	return atan(4*x-5)+exp(-2*x+1)*sin(x+PI)-pow(x,2);
}

int main(int argc, char *argv[]) {
	nat_t (*g)(nat_t)=NULL;
	g=fun1;
	nat_t a;
	nat_t b;
	while(true){
		cout<<"introdusca sus valores de a y b"<<endl;
		cout<<"a: ";
		cin>>a;
		cout<<"b: ";
		cin>>b;
		if(g(a)*g(b)<0)     
			break;
	}
	nat_t tolerancia=0.000001;
	biseccion(a,b,fun1,20);
	biseccion2(a,b,fun1,tolerancia);
	biseccion3(a,b,fun1,tolerancia);
	//system("pause");
	return 0;
}

