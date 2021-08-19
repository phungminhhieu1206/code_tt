/*
    - Yc: In ra cac bo nhi phan 3 bits (RB: khong co hai bit 1 canh nhau)
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int X[N];
int n; // kich thuoc bo kqua
int countt = 0;
int visited[N];

void solution() {
    int temp = 0;
    for (int i = 1; i <= n; i++) {
        temp += X[i] * X[i];
    }
    if (temp == 362) {
        countt++;

        for (int i = 1; i <= n; i++) {
            visited[X[i]] = true;
            cout << X[i] << " ";
        }
        cout << endl;
    }
}

bool check(int v, int k) {
    return true;
}

void Try(int k) {
    for (int v = 0; v <= 19; v++) {
        if(check(v, k)) {
            X[k] = v;
            if (k == n) {
                solution();
            } else Try(k+1);
        }
    }
}

int main() {
    for (int i = 0; i <=19; i++) visited[i] = false;
    n = 3;
    Try(1);
    cout << "Count = " << countt;
}
