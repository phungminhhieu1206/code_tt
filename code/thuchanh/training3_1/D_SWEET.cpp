/*
    - Một cách hỏi khác của bài giải phương trình nguyên dương
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+1;
int x[N];
unsigned long long cnt;
int n, m;
int T;
int mod = 1e9+7;

bool check(int v, int k) {
    if (k < m) return true;
    if (k == m && v == n - T) return true;
    return false;
}

Try(int k) {
    for (int v=0; v<=n-T; v++) {
        if (check(v, k)) {
            x[k] = v;
            T+=v;
            if (k==m)
                cnt++;
            else
                Try(k+1);
            T-=v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cnt = 0;
    T=0;
    cin >> n >> m;
    Try(1);
    cout << cnt % mod << endl;
    return 0;
}
