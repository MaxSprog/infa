#pragma once
class A{
    private:
        int sz;
        double *p;
    public:
        A(int sz_);
        ~A();
        int size();
        double& operator[](int i);
        void resize(int sz_);
        void put(double v);
};