#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n;
int s[N];
int a[N];

bool checkdau(int x, int y) {
    if (x > 0 && y < 0) return true;
    if (x < 0 && y > 0) return true;
    return false;
}


int lnAt(int i) {
    if (s[i] != -1) return s[i];
    int tmp = 1;
    for (int j=1; j <= i; j++) {
        if(checkdau(a[i], a[j]) && (abs(a[i]) > abs(a[j])))
            tmp = max(tmp, s[j] + 1);
    }
    s[i] = tmp;
    return tmp;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int maxx = -1e9;

    unsigned int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        s[i] = -1;
        cin >> a[i];
        maxx = max(maxx, lnAt(i));
    }
    cout << maxx << endl;
//    cout << tinhmaxx(a,n) << endl;
    return 0;
}
