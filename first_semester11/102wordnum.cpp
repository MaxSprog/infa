#include <fstream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru_RU");
    ifstream fin("input.txt");
    map<int, int> len;
    string word;
    while(fin >> word){
        len[strlen(word.c_str())]++;
    }
    fin.close();
    ofstream fout("output.txt");
    for(auto e : len){
        if(e.first)
            fout << e.first << " - " << e.second << "\n";
    }
    fout.close();
}