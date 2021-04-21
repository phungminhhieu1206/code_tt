/*
    - Tự code:
        + Bài toán hoán vị 1-> n
        + Cố định xuất phát từ 1, tìm hoán vị 2->n
        + Cộng dồn chi phí cho mỗi chặng qua, cập nhật chi phí ở cuối lộ trình
    - Bài toán người du lịch
    - Phiên bản 1: Không áp dụng nhánh cận, đánh giá kỷ lục ở nút lá của 1 quá trình
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n;
int x[N]; // lo trinh
int c[N][N]; // ma tran chi phi
bool visited[N];
int f_min;
int f;

void input() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> c[i][j]; // chi phi tu i->j
        }
    }
}

void updateBest() {
    if (f + c[x[n]][x[1]] < f_min) { // den diem cuoi quay lai
        f_min = f + c[x[n]][x[1]];
        for(int i=1; i<=n; i++) {
            cout << x[i] << " ";
        }
        cout << "f_min: " << f_min << endl;
    }
}

bool check(int v, int k) {
    return !visited[v];
}

void Try(int k) {
    for(int v=2; v<=n; v++) {
        if(check(v,k)) {
            x[k] = v;
            visited[v] = true;
            f += c[x[k-1]][x[k]];

            if(k==n) { // duyet xong 1 lo trinh
                updateBest();
            }
            else Try(k+1);

            visited[v] = false;
            f -= c[x[k-1]][x[k]];
        }

    }
}


int main() {
    input();
    for (int v=0; v<=n; v++) visited[v] = false;
    visited[1] = true;
    f = 0;
    f_min = 1e9;

    x[1] = 1;
    Try(2);
    cout << f_min;
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
