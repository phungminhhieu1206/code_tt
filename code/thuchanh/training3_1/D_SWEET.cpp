/*
    - Một cách hỏi khác của bài giải phương trình nguyên dương
*/
#include <bits/stdc++.h>
using namespace std;\
const int N = 100;
int x[N];
int cnt;
int n, m;
int T;
int mod = 1e9+7;

bool check(int v, int k) {
    if (k < m) return true;
    if (k == m && v == n - T) return true;
    return false;
}

void solution() {
    for (int i=1; i<=m; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

Try(int k) {
    for (int v=0; v<=n-T; v++){
        if (check(v, k)) {
            x[k] = v;
            T+=v;
            if (k==m){
                solution();
                cnt++;
            }
            else Try(k+1);
            T-=v;
        }
    }
}

int main() {
    cnt = 0;
    T=0;
    cin >> n >> m;
    Try(1);
    cout << cnt % mod;

}
