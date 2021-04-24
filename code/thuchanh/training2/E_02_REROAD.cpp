#include <bits/stdc++.h>
using namespace std;
int N, Q;

int main() {
    cin >> N;
    vector<int> t;
    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }

    cin >> Q;
    for (int i=1; i<=Q; i++) {
        int p, c;
        cin >> p >> c;
        t[p-1] = c;
        int cnt = 1;
        for (int j=1; j<N; j++) {
            if(t[j] != t[j-1]) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
