#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n;
int k;
int f;
int f_min;
int c[N][N];
bool visited[N];

void input() {
    cin >> n >> k;
    for (int i=0; i<=2*n; i++) {
        for (int j=0; j<=2*n; j++) {
            cin >> c[i][j];
        }
    }
}

void Try(int k) {


}

/* In tổ hợp chập k của n */



int main() {
    input();
    for (int v=1; v<=n; v++) visited[v] = false;

}
