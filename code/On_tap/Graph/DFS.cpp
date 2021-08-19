// Duyệt đồ thị theo DFS
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

struct Arc {
    int node;
    int w;
    Arc(int _node, int _w) {
        node = _node;
        w = _w;
    }
};

int n; // số đỉnh
int m; // số cung

vector<Arc> A[N]; // ma trận vector A[v] lưu các cung xuất phát từ đỉnh v

bool visited[N];

// 2. Các hàm:

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
    }
}

void DFS(int u) {
    cout << u << endl; // thăm đỉnh u
    visited[u] = true;

    // tìm các đỉnh kề với u, có đường đến
    if (A[u].size() > 0) {
        for (int i=0; i < A[u].size(); i++) {
            int v = A[u][i].node;
            if (!visited[v]) {
                DFS(v);
            }
        }
    }
}

void DFS_Graph(int _n) {
    for(int u = 1; u <= _n; u++) visited[u] = false;

    for(int u = 1; u <= _n; u++) {
        if (!visited[u]) {
            DFS(u);
        }
    }
}

int main() {
    for(int i = 1; i <= n; i++) visited[i] = false;

    input();
//    DFS_Graph(n);
    DFS(5);

    return 0;
}
