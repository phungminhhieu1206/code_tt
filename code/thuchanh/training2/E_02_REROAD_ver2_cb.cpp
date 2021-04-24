#include <bits/stdc++.h>
using namespace std;
int N, Q;
const int M = 1e5+1; // đủ kích thước bộ dữ liệu yêu cầu
int t[M+1];

int start(int u) {
    if (u == 1) return 1;
    return t[u] != t[u-1];
}

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> t[i];
    }

    int cnt = 1;
    for (int i=2; i<=N; i++) {
        if (t[i] != t[i-1]) {
            cnt+=1;
        }
    }

    cin >> Q;
    for (int i=1; i<=Q; i++) {
        int p,c;
        cin >> p >> c;
        cnt -= start(p);
        if (p<N) cnt -= start(p+1);
        t[p] = c;
        cnt += start(p);
        if (p<N) cnt += start(p+1);
        cout << cnt << endl;
    }

    return 0;
}
