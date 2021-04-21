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
        for(int i=1; i<=n; i++) {
            cout << x[i] << " ";
        }
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


/*
    10
    0 68 35 1 70 25 79 59 63 65
    6 0 82 28 62 92 96 43 28 37
    92 5 0 54 93 83 22 17 19 96
    48 27 72 0 70 13 68 100 36 95
    4 12 23 34 0 65 42 12 54 69
    48 45 63 58 38 0 24 42 30 79
    17 36 91 43 89 7 0 43 65 49
    47 6 91 30 71 51 7 0 94 49
    30 24 85 55 57 41 67 77 0 9
    45 40 27 24 38 39 19 83 30 0
*/
