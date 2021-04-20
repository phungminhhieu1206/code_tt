/*
    - Bài toán người du lịch
    - Phiên bản 1: Không áp dụng nhánh cận, đánh giá kỷ lục ở nút lá của 1 quá trình
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n; // số điểm giao hàng
int c[N][N]; // ma trận chi phí c[i][j] = chi phí đi từ i -> j
int x[N]; // lộ trình
int f; // ghi nhận độ dài tại nút lá
int f_min; // kỷ lục cập nhật trước đó
bool visited[N]; // bài toán liệt kê hoán vị, cần mảng đánh dấu để tránh trùng điểm đã qua
void input() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c[i][j];
        }
    }
}

bool check(int v, int k) {
    return !visited[v];
}

void updateBest() {
    if (f + c[x[n]][x[1]] < f_min) { // x[n] là điểm cuối cùng mà lộ trình đi qua, x[n] nhận giá trị thuộc 1->n
        f_min = f + c[x[n]][x[1]];
        cout << "update best: " << f_min << endl;
    }
}

void Try(int k) { // thử giá trị cho x[k] khi đã biết x[1], x[2], ..., x[k-1]
    for(int v=1; v<=n; v++) {
        if(check(v,k)) {
            x[k] = v; // tức đi thêm 1 chặng từ x[k-1] -> x[k]
            f += c[x[k-1]][x[k]];
            visited[v] = true;
            if (k==n) updateBest(); // cập nhật kỷ lục ở cuối mỗi nhánh duyệt
            else Try(k+1);
            f -= c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
}

int main() {
    input();
    for (int v=1; v<=n; v++) visited[v] = false;
    x[1] = 1;
    visited[1] = true;
    f = 0;
    f_min = 1e9;
    Try(2);
    cout << f_min << endl;
}
