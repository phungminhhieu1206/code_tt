/*
    - Yc: In ra nghiệm nguyên dương của phương trình: x1+x2+...+xk+...+xn = M. Biết n, M
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int x[N];
int T = 0;
int n;
int M; // tong
int dem=0;

void solution() {
    cout << "Value " << ++dem << ": ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k) {
    if (k < n) return true;

    if (v == M-T) return true;
    return false;
}

void Try(int k) {
    for (int v = 1; v <= M-T-n+k; v++) {
        if (check(v, k)){
            x[k] = v;
            T += v;
            if (k == n) solution();
            else Try(k+1);
            T -= v;
        }
    }
}

int main() {
    n = 3;
    M = 5;
    Try(1);
}
