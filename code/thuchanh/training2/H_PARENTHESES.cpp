#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
stack<char> s;

int main() {
    int n = 5;
    for (int i=0; i<n; i++) {
        char x;
        cin >> x;
        s.push(x);
    }
    cout << endl;

    for (int i=0; i<n; i++) {
        char v = s.top(); s.pop();
        cout << v;
    }

}
