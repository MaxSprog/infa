#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int n, a1=0, a2=0, b1=0, b2=0;
    ifstream fin("input.txt");
    fin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        fin >> temp;
        if(temp % 2 == 0){
            if(temp % 17 == 0){
                if(a2 < temp){
                    a1 = a1 < a2 ? a2 : a1;
                    a2 = temp;
                    continue;
                }
            }
            a1 = a1 < temp ? temp : a1;
        }
        else{
            if(temp % 17 == 0){
                if(b2 < temp){
                    b1 = b1 < b2 ? b2 : b1;
                    b2 = temp;
                    continue;
                }
            }
            b1 = b1 < temp ? temp : b1;
        }
    }
    if(a1+a2 > b1+b2){
        cout << a1 << " " << a2;
    }
    else{
        cout << b1 << " " << b2;
    }
}