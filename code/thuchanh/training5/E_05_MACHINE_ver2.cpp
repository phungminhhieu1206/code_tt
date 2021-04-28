#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2*1e6 + 1;
int s[N], t[N], c[N];
int maxAmount[N]; // độ dài đoạn lớn nhất có t kết thúc <= index
int amount[N]; // độ dài đoạn lớn nhất có t kết thúc tại index
int Tmaxx;


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
        Tmaxx = max(Tmaxx, t[i]);
        amount[t[i]] = max(amount[t[i]], t[i]-s[i]);
    }
}
// xong input

int main() {
    input();

//    // ver_1
//    int maxx = 0;
//
//    for (int i=0; i<n; i++) {
//        for (int j=i+1; j<n; j++) {
//            if(check(s[i], t[i], s[j], t[j])) {
//                int tmp = c[i] + c[j];
//                if (maxx < tmp)
//                    maxx = tmp;
//            }
//        }
//    }
//
//    cout << maxx << endl;


    // ver_2
//    cout << "Tmaxx" << Tmaxx << endl;
//    for(int i=0; i<=Tmaxx; i++)
//        cout << "So " << i << " - amount: " << amount[i] << endl;

    for (int i=0; i<=Tmaxx; i++) {
        maxAmount[i] = max(maxAmount[i-1], amount[i]);
    }

//    for(int i=0; i<=Tmaxx; i++)
//        cout << "So " << i << " - maxxAmount: " << maxAmount[i] << endl;

    int maxx = 0;
    for (int i=0; i<n; i++) {
        maxx = max(maxx, t[i]-s[i] + maxAmount[s[i]-1]);
    }

    cout << maxx << endl;

    return 0;
}
