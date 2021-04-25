/*
    - Bài toán cái túi
*/
#include <bits/stdc++.h>

using namespace std;

long long A[40];
long long C[40];

int n;
long long b;
long long best_value = 0;
long long weight;
long long value;
long long max_value = 0;

void input() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> C[i];
        max_value = max(max_value, C[i]);
    }
}

void TRY(int k) {
    if (k > n) {
        best_value = max(best_value, value);
        return;
    }
    for (int i = 0; i <= 1; i++) {

        weight += (i * A[k]);
        value += (i * C[k]);
        long long bound;
        bound = (n-k) * max_value + value;
        if (weight <= b && bound > best_value) {
            TRY(k + 1);
        }
        weight -= (i * A[k]);
        value -= (i * C[k]);
    }
}

int main() {
    value = 0;
    weight = 0;
    input();
    TRY(1);
    cout << best_value;

    return 0;
}
