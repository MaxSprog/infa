#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream fin("input.txt");
    string s;
    int c;
    for(c=0; getline(fin, s); c++){}
    fin.close();
    ofstream fout("output.txt");
    fout << c;
    fout.close();
}