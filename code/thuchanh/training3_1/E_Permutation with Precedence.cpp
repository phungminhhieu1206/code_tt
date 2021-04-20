/*
    - Liệt kê hoán vị cách 2
    - Sử dụng mảng đánh dấu
    - Có điều kiện
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
bool visited[N] = {false};
int n;
int x[N];
int A[N][N];
int cnt;

void solution() {
    cnt++;
    for (int i=1; i<=n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void input() {
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) {
            A[i][j] = 0;
        }
    }
    int K;
    cin >> K;
    for (int k=1; k<=K; k++) {
        int i, j;
        cin >> i >> j;
        A[i][j] = 1;
    }
}

bool check(int v, int k) {
    if(visited[v]) return false;
    for (int i=1; i<=k-1; i++) {
        if(A[v][x[i]] == 1) return false;
    }
    return true;
}

void Try(int k) {
    for (int v=1; v<=n; v++) {
        if(check(v, k)) {
            x[k] = v;
            visited[v] = true;
            if(k==n) solution();
            else Try(k+1);
            visited[v] = false;
        }

    }

}

int main() {
    input();
    Try(1);
    cout << cnt;
}
