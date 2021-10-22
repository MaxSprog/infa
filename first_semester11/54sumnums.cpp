#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int prev = -1;
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            // cout << s[i];
            if(prev != -1){
                prev *= 10;
                prev += s[i] - '0';
            }
            else{
                prev = s[i] - '0';
            }
        }
        else if(prev != -1){
            // cout << " ";
            sum += prev;
            prev = -1;
        }
    }
    cout << sum;
}