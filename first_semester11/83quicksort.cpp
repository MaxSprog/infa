#include <iostream>
#include <cmath>

using namespace std;

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int pivot(int *arr, int l, int h)
{
    int p = arr[(l + h)/2];
    int lb = l-1;
    int hb = h+1;
    while(true){
        do{
            lb++;
        } while(arr[lb] < p);
        do{
            hb--;
        } while(arr[hb] > p);
        if(lb >= hb)
            return hb;
        swap(&arr[lb], &arr[hb]);
    }
}

void quick(int* arr, int l, int h){
    if(l >= h){
        return;
    }
    int hb = pivot(arr, l, h);
    quick(arr, l, hb);
    quick(arr, hb + 1, h);
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int j = 0; j < n; j++){
        cin >> arr[j];
    }
    quick(arr, 0, n - 1);
    for(int j = 0; j < n; j++){
        cout << arr[j] << " ";
    }
}