#include <iostream>
#include "QueueClass.cpp"

using namespace std;

int main(){
    Queue<int> q;
    q.push(1);
    q.push(4);
    q.push(3);
    cout << q.front() << " " << q.last() << endl;
    while(!q.empty()) cout << q.pop() << " ";
}