#include <iostream>
#include <fstream>
#include <climits>
#define min(a, b) a > b ? b : a

using namespace std;

int main(){
    ifstream fin("27_B.txt");
    int len = INT_MAX, Msum = 0, k = 43;
    long long* sum_ost = new long long[k], *ind = new long long[k];
    long long S = 0;
    sum_ost[0] = 0;
    ind[0] = -1;
    for(int i = 1; i < k; i++){
        sum_ost[i] = INT_MAX;
        ind[i] = 0;
    }
    int a;
    for(int i = 0; fin >> a; i++){
        int ost;
        S += a;
        ost = S % k;
        if(sum_ost[ost] == INT_MAX){
            sum_ost[ost] = S;
            ind[ost] = i;
        }
        if(S - sum_ost[ost] == Msum){
            len = min(len, i - ind[ost]);
        }
        if(S - sum_ost[ost] > Msum){
            Msum = S-sum_ost[ost];
            len = i - ind[ost];
        }
    }
    cout << len;
}