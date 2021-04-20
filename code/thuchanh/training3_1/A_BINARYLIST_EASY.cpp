/*
    - liệt kê xâu nhị phân độ dài n theo thứ tự từ điển
    - Tối ưu về tốc độ: Đặt N vừa đủ, không đặt N quá cao
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int n;
int x[N];

void solution() {
    for (int i=1; i<=n; i++) {
        printf("%d",x[i]);
    }
    printf("\n");
}

void Try(int k) {
    for(int v=0; v<=1; v++) {
            x[k] = v;
            if(k==n) solution();
            else Try(k+1);
    }
}

int main() {
    scanf("%d", &n);
    Try(1);
}
