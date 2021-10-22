#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void lower(string& s){
    for(int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
}

void upper(string& s){
    for(int i = 0; i < s.length(); i++){
        s[i] = toupper(s[i]);
    }
}

void filter(string& s){
    for(int i = 0; i < s.length(); i++){
        if(!('a' <= s[i] && s[i] <= 'z')){
            s = s.substr(0, i);
            break;
        }
    }
}

vector<string> split(string S){
    vector<string> slt;
    int last = 0;
    for(int i = 0; i < S.length(); i++){
        if(S[i] == ' '){
            slt.push_back(S.substr(last, i - last));
            last = i + 1;
        }
    }
    return slt;
}

map<string, int>::iterator Max(map<string, int>& m){
    map<string, int>::iterator it = m.begin(), itM = m.begin(); it++;
    for(; it != m.end(); it++){
        if(itM->second < it->second)
            itM = it;
    }
    return itM;
}

int main(){
    string w, ignore;
    getline(cin, ignore);
    map<string, int> words;
    vector<string> ign = split(ignore);
    
    for(;cin >> w;){
        lower(w);
        filter(w);
        if(find(ign.begin(), ign.end(), w) == ign.end()){
            if(words.find(w) == words.end()){
                words[w] = 1;
            }
            else{
                words[w]++;
            }
        }
    }
    string b = Max(words)->first;
    upper(b);
    cout << b;
}