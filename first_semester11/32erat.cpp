#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* a = new int[n+1];
    for (int i = 0; i <= n; i++)
        a[i] = 1;

    for (int i = 2; i * i <= n; i++){
        if(a[i]){
            int j = 0, k = 0;
            for (int j = i * i; j <= n; j += i)
                a[j] = 0;            
        }
    }
    for (int i = 2; i <= n; i++){
        if (a[i]){
            cout << i << " ";
        }
    }
}