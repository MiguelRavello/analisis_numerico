#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

typedef double nat_t;


nat_t rfalsa(nat_t &a,nat_t &b,nat_t (*f)(nat_t),int n){
	ofstream excel;
	excel.open("rfalsa.csv",ios::trunc | ios::out);
	nat_t m=(f(b)*a-f(a)*b)/(f(b)-f(a));
	excel<<"i"<<","<<"a"<<","<<"b"<<","<<"m"<<","<<"f(m)"<<endl;
	excel<<0<<","<<a<<","<<b<<","<<m<<","<<f(m)<<endl;
	for(int i=1;i<=n;i++){
		if(f(a)*f(m)<0)
			b=m;
		else
			a=m;
		m=(f(b)*a-f(a)*b)/(f(b)-f(a));
		cout<<i<<" "<<a<<" "<<b<<" "<<m<<" "<<f(m)<<endl;
		excel<<i<<","<<a<<","<<b<<","<<m<<","<<f(m)<<endl;
	}
	return m;
}

nat_t rfalsa2(nat_t &a,nat_t &b,nat_t (*f)(nat_t),nat_t tol){
	ofstream excel2;
	excel2.open("rfalsa2.csv",ios::trunc | ios::out);
	nat_t m=(f(b)*a-f(a)*b)/(f(b)-f(a));
	int i=1;
	excel2<<"i"<<","<<"a"<<","<<"b"<<","<<"m"<<","<<"|f(m)|"<<endl;
	excel2<<0<<","<<a<<","<<b<<","<<m<<","<<abs(f(m))<<endl;
	while(abs(f(m))>tol){
		if(f(a)*f(m)<0)
			b=m;
		else
			a=m;
		m=(f(b)*a-f(a)*b)/(f(b)-f(a));
		cout<<i<<" "<<a<<" "<<b<<" "<<m<<" "<<abs(f(m))<<endl;
		excel2<<i<<","<<a<<","<<b<<","<<m<<","<<abs(f(m))<<endl;
		i++;
	}
	return m;
}

nat_t rfalsa3(nat_t &a,nat_t &b,nat_t (*f)(nat_t),nat_t tol){
	ofstream excel3;
	excel3.open("rfalsa3.csv",ios::trunc | ios::out);
	nat_t m=(f(b)*a-f(a)*b)/(f(b)-f(a));
	int i=1;
	excel3<<"i"<<","<<"a"<<","<<"b"<<","<<"m"<<","<<"|a-b|"<<","<<"f(m)"<<endl;
	excel3<<0<<","<<a<<","<<b<<","<<m<<","<<abs(a-b)<<","<<f(m)<<endl;
	while(abs(a-b)>tol){
		if(f(a)*f(m)<0)
			b=m;
		else
			a=m;
		m=(f(b)*a-f(a)*b)/(f(b)-f(a));
		cout<<i<<" "<<a<<" "<<b<<" "<<m<<" "<<abs(a-b)<<" "<<f(m)<<endl;
		excel3<<i<<","<<a<<","<<b<<","<<m<<","<<abs(a-b)<<","<<f(m)<<endl;
		i++;
	}
	return m;
}

nat_t fun1(nat_t x){
	return pow(x,3)*exp(-x+1)-5*pow(x,2)*cos(2*x+1)-7; 
}
/*intervalo considerado de 0.1 a 1.1*/


nat_t fun2(nat_t x){
	return 4*x*atan(2*x-3)+x*sin(x)+sqrt(pow(x,2)-1)-20;
}
/*intervalo de 2 a 5 */
int main(int argc, char *argv[]) {
	nat_t a=3;
	nat_t b=4;
	nat_t tolerancia=0.001;
	rfalsa(a,b,fun2,20);
	rfalsa2(a,b,fun2,tolerancia);
	rfalsa3(a,b,fun2,tolerancia);
	//system("pause");
	return 0;
}

