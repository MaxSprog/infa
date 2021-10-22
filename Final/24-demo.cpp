#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("24.txt");
    char c, clast;
    int i = 0, M = 0;
    while(fin >> c){
        if(c != 'P' || clast != 'P'){
            i++;
        }
        else{
            M = i > M ? i : M;
            i = 1;
        }
        clast = c;
    }
    cout << (M > i ? M : i);
}