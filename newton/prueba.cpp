#include"matrix.h"
#include<cmath>



int main(){
    vector<int> a;
    vector<int> b={1,2,3,4};
    Matrix<int> A(b.size(),0);
    A.insertCol(b);
    a.push_back(1);
    a.push_back(2);
    cout<<a[0]<<" "<<a[1]<<endl;

    return 0;
}
