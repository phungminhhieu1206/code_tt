#include <bits/stdc++.h>

using namespace std;

const int MAX=50;
int n, K, Q;
int d[MAX];
int C[MAX][MAX];

int min_cost = INT_MAX;
int best  = INT_MAX;
int curr_value;

int n_clients[MAX] = {0};
int weights[MAX] = {0};


void input() {
    cin >> n >> K >> Q;
    for (int i=1; i<=n; i++) {
        cin >> d[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=1; j++) {
            cin >> C[i][j];
            if (i!=j) {
                min_cost = min(min_cost, C[i][j]);
            }
        }
    }

}

void TRY(int u) {
    if (u>n) {
        curr_value = 0;
        for (int i=1; i<=K; i++) {
            if (n_clients[i] == 0) {
                min_cost = INT_MAX;
                return;
            }

            int cost;
            // cost = TSP();
            curr_value += cost;
        }
        min_cost = min(curr_value, min_cost);

        return;
    }
    for (int i=1; i<=K; i++) {
        n_clients[i] += 1;
        weights[i] += d[u];
        if (weights[i] <= Q) {
            TRY(u+1);
        }
        n_clients[i] -= 1;
        weights[i] -= d[u];


    }

}

int main() {
    input();
    TRY(1);
    cout << min_cost << endl;
}
