#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int x[N];
int c[N][N];
int n;
int crr;
int f;
int f_min;
bool visited[N];

void input() {
    cin >> n;
    crr = 1e9;
    for (int i=0; i<=2*n; i++) {
        for (int j=0; j<=2*n; j++) {
            cin >> c[i][j];
            if (i != j && c[i][j] < crr) {
                crr = c[i][j];
            }
        }
    }
}

bool check(int v, int k) {
    return !visited[v];
}

void updateBest() {
//    for (int i=1; i<=n; i++) {
//        cout << x[i] << "->";
//    }
    if (f + c[x[n] + n][0] < f_min) {
        f_min = f + c[x[n] + n][0];
    }
//    cout << ": f_min = " << f_min << endl;
}

void Try(int k) {
    for (int v=1; v<=n; v++) {
        if (check(v, k)) {
            x[k] = v;
            f = f + c[x[k-1] + n][x[k]] + c[x[k]][x[k] + n];
            visited[v] = true;
            if (k == n) {
                updateBest();
            } else {
                int g = f + crr * (2*n - 2*k + 1);
                if (g < f_min) {
                    Try(k+1);
                }
            }

            f = f - c[x[k-1] + n][x[k]] - c[x[k]][x[k] + n];
            visited[v] = false;

        }

    }

}

int main() {
    input();
    for (int v=1; v<=n; v++) visited[v] = false;
    f = 0;
    f_min = 1e9;
    x[0] = -n;

    Try(1);
    cout << f_min << endl;

    return 0;
}
