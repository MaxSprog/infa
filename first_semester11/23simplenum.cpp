#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N = 0, flag = 0;
    cin >> N;
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                flag = 1;
                break;
            }
        }
        if(!flag)
            cout << i << " ";
        flag = 0;
    }
}