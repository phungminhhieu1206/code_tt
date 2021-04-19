/*
    - Yc: In ra cac bo nhi phan 3 bits (RB: khong co hai bit 1 canh nhau)
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

bool check(int v, int k) {
    if (X[k-1] == 1 && v == 1) return false;
    return true;
}

void Try(int k) {
    for (int v = 0; v <= 1; v++) {
        if(check(v, k)) {
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
