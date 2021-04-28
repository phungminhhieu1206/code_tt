#include <bits/stdc++.h>

using namespace std;

long long n,m;
const long long MAX = 1e6+1;
long long highs[MAX] = {0};

long long min_high = INT_MAX;
long long max_high = 0;
void input() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (long long i=1; i<=n; i++) {
        long long temp;
        cin >> temp;
        highs[i] = temp;
        min_high = min(min_high, temp);
        max_high = max(max_high, temp);
    }
}

long long sum_wood(long long threshold) {
    long long res = 0;
    for (long long i = 1; i<=n; i++) {
        res += max((long long)0, highs[i] - threshold);
    }

    return res;
}

int main() {
    input();
    long long low = min_high, high = max_high + 10;
    while(high - low > 1) {
        long long mid = (high + low) /2;
        if (sum_wood(mid) < m) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << low << endl;

    return 0;
}
