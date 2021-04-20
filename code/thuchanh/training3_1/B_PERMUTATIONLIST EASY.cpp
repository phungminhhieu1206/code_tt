/*
    - Liệt kê hoán vị cách 2
    - Sử dụng mảng đánh dấu
    - Vẫn là lưu ý: Số N vừa đủ cho bộ dữ liệu
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 11;
bool visited[N];
int n;
int x[N];

void solution() {
    for (int i=1; i<=n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
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
    scanf("%d", &n);
    Try(1);
}
