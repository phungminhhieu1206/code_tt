#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n;
int x[N];
int visited[N];
int M;
int cnt;

void input() {
    cin >> M;
}

bool check(int v, int k) {
    if (v == 0 && (k == 1 || k == 2)) return false;
    if (visited[v]) return false;
    return true;
}

void updateCount() {

    int tmp = x[1]*1e5 + x[2]*11101 + x[3]*1001 + x[4]*100 + (x[5] + x[6])*10;
    if (tmp == M) cnt++;

}

void Try(int k) {
    for (int v=0; v<=9; v++) {
        if(check(v, k)) {
            x[k] = v;
            visited[v] = true;
            if (k == 6) updateCount();
            else Try(k+1);
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
    for (int v=0; v<=9; v++) visited[v] = false;
    cnt = 0;

    Try(1);
    cout << cnt << endl;

    return 0;
}
