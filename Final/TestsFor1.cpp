#include <fstream>

using namespace std;

int main(){
    ofstream fout("input.txt"); 
    fout << 4900 + 4900 << endl;
    for(int i = 100; i < 5001; i++){
        fout << i << endl;
    }
    for(int i = 5000; i >= 100; i--){
        fout << i << endl;
    }
}