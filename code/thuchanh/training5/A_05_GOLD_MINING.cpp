#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e6 + 1;
int a[N];
int L1, L2;
vector<int> chosen;
int best_golds = 0;
int curr;

bool is_accept() {
    if (chosen.empty())
        return true;

    for (int i = 1; i < chosen.size(); i++) {
        int distance = abs(chosen[i] - chosen[i - 1]);
        if (distance < L1 || distance > L2) {
            return false;
        }
    }

    return true;
}

void TRY(int k) {
    if (k > n) {
        if (is_accept()) {
            best_golds = max(curr, best_golds);
        }
        return;
    }
    for (int i = 0; i <= 1; i++) {
        if (i) {
            curr += a[k];
            chosen.push_back(k);
            TRY(k + 1);
            curr -= a[k];
            chosen.pop_back();
        } else {
            TRY(k + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    best_golds = 0;
    curr = 0;
    TRY(1);
    cout << best_golds << endl;
    return 0;
}
