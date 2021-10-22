#include <iostream>
#include <string>

using namespace std;

int main(){
    int k, num;
    string s = "";
    cin >> k;
    num = k;
    for(int i = 1; i <= k; i++){
        num -= s.length();
        s = to_string(i);
        cout << s << " ";
        cout << num << "\n";
    }
    cout << s[num] << " " << s;
}