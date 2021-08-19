#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1; // số đỉnh tối đa

// Cấu trúc 1 cung
struct Arc {
    int node; // đỉnh
    int w; // trọng số
    Arc(int _node, int _w) {
        node = _node;
        w = _w;
    }
};

// Một mảng vector, mỗi vector lưu các cung từ đỉnh v đi ra.
vector<Arc> A[N]; // A[v] là một vector cung từ đỉnh v
int n; // number of nodes
int m; // số cung

void input() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v, w));
    }
}

int main() {
    input();
}

/*
- Đồ thị có hướng kèm trọng số:
6 8
6 1 2
3 1 7
2 4 9
5 2 6
2 6 4
4 3 7
3 6 5
5 4 2

*/














