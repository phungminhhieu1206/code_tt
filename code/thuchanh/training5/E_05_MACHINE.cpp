#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2*1e6 + 1;
int s[N], t[N], c[N];

bool check(int s1, int t1, int s2, int t2) {
    if (t1 < s2 || t2 < s1)
        return true;
    return false;
}

void input() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> t[i];
        c[i] = t[i] - s[i];
    }
}

int main() {
    input();
    int maxx = 0;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if(check(s[i], t[i], s[j], t[j])) {
                int tmp = c[i] + c[j];
                if (maxx < tmp)
                    maxx = tmp;
            }
        }
    }

    cout << maxx << endl;

}
