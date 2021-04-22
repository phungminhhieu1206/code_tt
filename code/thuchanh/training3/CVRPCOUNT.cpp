/*
    - Bài toán vận chuyển liệt kê mức 1.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n; // số điểm giao
int K; // số xe có
int y[N]; // index nhận giá trị 1->K, y[index] nhận giá trị 1->n
bool visited[N];
int x[N]; // xuất phát từ x[y[1]]

bool checkY(int v, int k) {
    if (visited[v]) return false;
    if (y[k-1] >= v) return false;
    return true;
}

void solutionY() {
    for (int i=1; i<=K; i++) {
        cout << y[i] << " ";
    }
    cout << endl;
}

bool checkX(int v, int k) {
    if (v==0) return true;
    return !visited[v];
}

void TryX(int k) {
    for (int v=0; v<=n; v++) {
        if (checkX(v, k)) {
            x[k] = v;
            visited[v] = true;
            if (k == N-K)
        }
    }
}

void TryY(int k) { // k thuộc 1->K // duyệt chỉ số
    for(int v=1; v<=n; v++) { // duyệt giá trị v có thể gán cho y[k]
        if(checkY(v, k)) {
            y[k] = v;
            visited[v] = true;
            TryX(y[k]);
            if (k == K) {
                solutionY();
            }
            else {
                TryY(k+1);
            }
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n >> K;
    for (int v=1; v<=n; v++) {
        visited[v]=false;
    }
    TryY(1);
}
