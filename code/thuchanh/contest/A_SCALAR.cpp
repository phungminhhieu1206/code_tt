/*
    - tính tích hai vector
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int T;
int n;
int x[N];
int y[N];

bool visited[N] = {false};
int f; // giá trị scalar hiện tại
int f_min;

void input() {
    cin >> n;
    for (int i=1; i<=n; i++)
        scanf("%d", &x[i]);
    for (int i=1; i<=n; i++)
        scanf("%d", &y[i]);
}

//int scalar(int a[], int b[]) {
//    int s = 0;
//    for (int i=1; i<=n; i++){
//        s += a[i]*b[i];
//    }
//    return s;
//}

bool check(int v, int k){
    return !visited[v];
}

void Try(int k) {
    for (int v=1; v<=n; v++) {
        if(check(v, k)){
            visited[v] = true;
            f += x[k] * y[v];
            if (k==n) {
                if(f < f_min) {
                    f_min = f;
                }
            } else {
                Try(k+1);
            }
            f -= x[k] * y[v];
            visited[v] = false;
        }
    }

}

int main() {
    cin >> T;
    f_min = 1e9;
    for (int i=1; i<=T; i++) {
        input();
        sort(x+1, x+n+1, greater<int>());
        sort(y+1, y+n+1);
        f=0;
        Try(1);
        cout << "Case #" << i << ": " << f_min << endl;
        f_min = 1e9;
    }
}
