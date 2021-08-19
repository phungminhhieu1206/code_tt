// Duyệt đồ thị theo BFS
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

void BFS(int u) {
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        cout << v << endl; // thăm đỉnh v (u)
        if (A[v].size() > 0) {
            for(int i = 0; i < A[v].size(); i++) {
                int x = A[v][i].node;
                if (!visited[x]) {
                    Q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
}

void BFS_Graph(int _n) {
    for(int u = 1; u <= _n; u++) visited[u] = false;

    for(int u = 1; u <= _n; u++) {
        if (!visited[u]) {
            BFS(u);
        }
    }
}

int main() {
    for(int i = 1; i <= n; i++) visited[i] = false;

    input();
//    BFS_Graph(n);
    BFS(5);

    return 0;
}
