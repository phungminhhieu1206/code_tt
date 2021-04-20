/*
    - Liệt kê hoán vị cách 2
    - Sử dụng mảng đánh dấu
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
bool visited[N];
int n;
int x[N];

void solution() {
    for (int i=1; i<=n; i++) {
        cout << x[i];
    }
    cout << endl;
}

bool check(int v, int k) {
    return !visited[v];
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
    n = 6;
    Try(1);
}
