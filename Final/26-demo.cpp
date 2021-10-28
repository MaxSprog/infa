#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int S, N;
    ifstream fin("26.txt");
    fin >> S >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        fin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int p = arr[0], i = 1, counter = 1;
    for(; i < N; i++){
        if(p + arr[i] > S){
            if(p-arr[i-1]+arr[i] > S){
                cout << counter << " " << arr[i-1] << endl;
                return 0;
            }
            else{
                p -= arr[i-1];
                counter--;
            }
        }
        p += arr[i];
        counter++;
    }
    cout << counter << " " << arr[N-1];
}