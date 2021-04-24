#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n, M;
int w[N];
int v[N];
bool visited[N];
int x[N];
int w_crr;
int v_max;
int maxx;


void input() {
    for (int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
    }
}

vector<int> tinhAk() { // đưa ra các index của các túi có thể chọn tiếp
    vector<int> tmp;
    for (int i=1; i<=n; i++) {
        if (!visited[i] && w[i] + w_crr <= M) {
            tmp.push_back(i);
        }
    }
    sort(tmp.begin(), tmp.end());
    return tmp;
}

void Try(int k) {
    // Tìm A[k]
    vector<int> ak = tinhAk();
    if (ak.size() == 0) {
        if (maxx < v_max) {
            maxx = v_max;
        }
    } else {
        for (int i=0; i<ak.size(); i++) {
            x[k] = ak[i];
            visited[x[k]] = true;
            w_crr += w[x[k]];
            v_max += v[x[k]];

            if (w_crr == M) {
                if (maxx < v_max) {
                    maxx = v_max;
                }
            } else {
                Try(k+1);
            }
            visited[x[k]] = false;
            w_crr -= w[x[k]];
            v_max -= v[x[k]];
        }
    }

}


int main() {
    cin >> n >> M;
    input();
    w_crr = 0;

    v_max = 0;
    maxx = 0;
    for (int i=1; i<=n; i++) visited[i] = false;

    Try(1);
    cout << maxx << endl;
}
