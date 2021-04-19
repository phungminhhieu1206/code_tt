/*
    - Yc: In ra cac bo nhi phan 3 bits
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int X[N];
int n; // kich thuoc bo kqua

void solution() {
    for (int i = 1; i <= n; i++) {
        cout << X[i];
    }
    cout << endl;
}

void Try(int k) {
    for (int v = 0; v <= 1; v++) {
        if(true) {
            X[k] = v;
            if (k == n) solution();
            else Try(k+1);
        }
    }
}

int main() {
    n = 3;
    Try(1);
}
