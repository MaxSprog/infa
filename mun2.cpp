#include <iostream>

using namespace std;

int MaxICol(int m, int** arr, int i){
    int M = arr[0][i], k = 0;
    for(int j = 1; j < m; j++){
        if(M < arr[j][i]){
            M = arr[j][i];
            k = j;
        }
    }
    return M != 0 ? k : -1;
}

int Sum(int m, int* arr){
    int S = 0;
    for(int j = 0; j < m; j++){
        S += arr[j];
    }
    return S;
}

int main(){
    int N, M;
    cin >> N >> M;
    int** act = new int*[N];
    int** aut = new int*[N];
    int* kd = new int[N];

    for(int i = 0; i < N; i++){
        kd[i] = 0;
        act[i] = new int[M];
        for(int j = 0; j < M; j++){
            cin >> act[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        aut[i] = new int[M];
        for(int j = 0; j < M; j++){
            cin >> aut[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        int a = MaxICol(M, act, i), b = MaxICol(M, aut, i);
        if(a == b && a != -1){
            kd[a]++;
        }
    }
    for(int i = 0; i < N; i++){
        if((double)kd[i] / (double)M >= 0.3){
            cout << "YES\n" << i + 1;
            return 0;
        }
    }

    int max = Sum(M, act[0]), k = 0;
    for(int i = 1; i < N; i++){
        int a = Sum(M, act[i]);
        if(max < a){
            max = a;
            k = i;
        }
    }
    cout << "NO\n" << k+1;
}