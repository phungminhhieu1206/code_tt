#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n;
int x[N]; // mang cac mon hoc theo thu tu
int d[N];
int cnt_min;
int cnt_crr;
bool visited[N];
int time_crr;
int crr;

void input() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> d[i];
        if(d[i] < crr) crr = d[i];
    }
}

bool check(int v, int k) {
    return !visited[v];
}

int tinh(int k) {
    int t = 0;
    int cnt = 1;
    for (int i=1; i<=k; i++) {
        t += d[x[i]];
        if (t > 6){
            cnt++;
            t = d[x[i]];
        }
    }
    return cnt;
}

void Try(int k) {
    for(int v=1; v<=n; v++) {
        if(check(v, k)) {
            x[k] = v;
            visited[v] = true;
            // TODO

            if (k==n) {
                cnt_crr = tinh(n);
                if (cnt_crr < cnt_min) {
                    cnt_min = cnt_crr;
                }
            } else {
                int tmp = tinh(k);
                if (tmp + (n - k) * crr / 6 < cnt_min )
                    Try(k+1);
            }
            visited[v] = false;

        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // TODO
    input();
    time_crr = 0;
    cnt_crr = 1;
    cnt_min = 1e9;
    crr=1e9;

    for (int v=1; v<=n; v++) visited[v]=false;

    Try(1);
    cout << cnt_min << endl;

    return 0;
}
