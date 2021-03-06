/*
    - Liệt kê hoán vị cách 2
    - Sử dụng mảng đánh dấu
    - Vẫn là lưu ý: Số N vừa đủ cho bộ dữ liệu
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 20;
bool visited[N];
int n;
int m;
int x[N];

void solution() {
    for (int i=1; i<=m; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

bool check(int v, int k) {
    if (visited[v] || v < x[k-1]) return false;
    return true;
}

void Try(int k) {
    for (int v=1; v<=n; v++) {
        if(check(v, k)) {
            x[k] = v;
            visited[v] = true;
            if(k==m) {
                solution();
            }

            else Try(k+1);
            visited[v] = false;
        }

    }

}

int main() {
    scanf("%d %d", &n, &m);
    Try(1);
}
