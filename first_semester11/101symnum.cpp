#include <fstream>
#include <map>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru_RU");
    char c;
    map<unsigned char, int> sym;
    ifstream fin("input.txt");
    while(!fin.eof()){
        fin.get(c);
        if((unsigned char)c > 12) sym[(unsigned char)c]++;
    }
    fin.close();
    ofstream fout("output.txt");
    for(auto e : sym){
        fout << (int)e.first << " : " << e.first << " - " << e.second << "\n";
    }
    fout.close();
}