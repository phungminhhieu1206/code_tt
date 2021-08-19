#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

struct Arc {
    int node;
    int w;
    Arc(int _node, int _w) {
        node = _node;
        w = _w;
    }
};

int n; // số node đọc vào
int m; // số cung đọc vào

vector<Arc> A[N]; // mảng vector lưu các cung của đỉnh v

void input() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
    }
}

int main() {
    input();

    return 0;
}
