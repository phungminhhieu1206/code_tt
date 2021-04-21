/*
    - Tự code:
        + Bài toán hoán vị 1-> n
        + Cố định xuất phát từ 1, tìm hoán vị 2->n
        + Cộng dồn chi phí cho mỗi chặng qua, cập nhật chi phí ở cuối lộ trình
    - Bài toán người du lịch
    - Phiên bản 2: Áp dụng nhánh cận để cắt nhánh nhanh
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

// ver_3
int cm; // khoang cach nho nhat trong ma tran chi phi

void input() {
    cin >> n;
    cm = 1e9;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> c[i][j]; // chi phi tu i->j

            // ver_3
            if (i != j && c[i][j] < cm) {
                cm = c[i][j];
            }
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
            } else {
                // ver_3
                int g = f + cm * (n-k+1);
                if (g < f_min) {
                    Try(k+1);
                } else {
                    // g >= f_min
                    // Cat nhanh
                }
            }

            visited[v] = false;
            f -= c[x[k-1]][x[k]];
        }

    }
}


int main() {
    input();
    for (int v=0; v<=n; v++) visited[v] = false;
    x[1] = 1;
    visited[1] = true;
    f = 0;
    f_min = 1e9;

    Try(2);
    cout << f_min;
}


/*
14
0 68 35 1 70 25 79 59 63 65 6 46 82 28
62 0 96 43 28 37 92 5 3 54 93 83 22 17
19 96 0 27 72 39 70 13 68 100 36 95 4 12
23 34 74 0 42 12 54 69 48 45 63 58 38 60
24 42 30 79 0 36 91 43 89 7 41 43 65 49
47 6 91 30 71 0 7 2 94 49 30 24 85 55
57 41 67 77 32 9 0 40 27 24 38 39 19 83
30 42 34 16 40 59 5 0 78 7 74 87 22 46
25 73 71 30 78 74 98 13 0 91 62 37 56 68
56 75 32 53 51 51 42 25 67 0 8 92 8 38
58 88 54 84 46 10 10 59 22 89 0 47 7 31
14 69 1 92 63 56 11 60 25 38 49 0 96 42
3 51 92 37 75 21 97 22 49 100 69 85 0 35
54 100 19 39 1 89 28 68 29 94 49 84 8 0

*/
