/*
    - in hoán vị của bộ bất kỳ
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int index[N];
int n;
int y[N];
bool visited[N];
int temp[N];

void input() {
    for(int i=1; i<=n; i++) {
        cin >> y[i];
    }
}

void solution() {
    for(int i=1; i<=n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k) {
    return !visited[v];
}

void Try(int k) {
    for (int v=1; v<=n; v++) {
        if(check(v, k)) {
            index[k] = v;
            visited[v] = true;
            temp[k] = y[index[k]];
            if (k==n) solution();
            else Try(k+1);
            visited[v] = false;
            temp[k] = 0;
        }

    }

}

int main() {
    n = 5;
    input();
    Try(1);
}
