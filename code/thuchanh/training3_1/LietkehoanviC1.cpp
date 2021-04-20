/*
    - Liệt kê hoán vị cách 1
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n;
int x[N];

void solution() {
    for (int i=1; i<=n; i++) {
        cout << x[i];
    }
    cout << endl;
}

bool check(int v, int k) {
    for (int i=0; i<=k-1; i++) {
        if(v == x[i]) return false;
    }
    return true;
}

void Try(int k) {
    for (int v=1; v<=n; v++) {
        if(check(v, k)) {
            x[k] = v;
            if(k==n) solution();
            else Try(k+1);
        }

    }

}

int main() {
    n = 6;
    Try(1);
}
