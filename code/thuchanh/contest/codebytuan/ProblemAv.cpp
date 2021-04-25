
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long T, n, z;
    cin >> T;
    for(int t = 0;t < T;t++){
        cin >> n;
        vector<long long> x;
        vector<long long> y;
        long long result = 0;
        for(int i = 0;i < n;i++){
            cin >> z;
            x.push_back(z);
        }
        for(int i = 0;i < n;i++){
            cin >> z;
            y.push_back(z);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for(int i = 0;i < n;i++){
            result += x[i]*y[n-i-1];
        }
        x.clear();
        y.clear();
        cout << "Case #" << t + 1 << ": " << result << endl;
    }

    return 0;
}
