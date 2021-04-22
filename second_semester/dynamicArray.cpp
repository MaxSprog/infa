#include <iostream>
#include "dynamicArray.h"

using namespace std;

A::A(int sz_){
    sz = sz_;
    p = new double[sz];
}
A::~A(){delete[] p;}
int A::size(){return sz;}
double& A::operator[](int i){return p[i];}
void A::resize(int sz_){
    double *tmp = new double[sz_];
    for(int i = 0; i < sz_; i++){
        tmp[i] = sz > i ? p[i] : 0;
    }
    delete[] p;
    p = tmp;
    sz = sz_;
}
void A::put(double v){
    resize(sz+1);
    p[sz - 1] = v;
}

int main(){
    A a(15);
    for(int i = 0; i < a.size(); i++){
        cin >> a[i];
    }
    a.put(33);
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
}