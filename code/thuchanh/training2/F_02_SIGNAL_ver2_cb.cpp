#include <bits/stdc++.h>
using namespace std;
int n, b;

/*
    - Chuẩn bị trước mảng lưu các giá trị max;
*/

int main() {

    cin >> n >> b;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    /* Chuẩn bị trước các mảng tại đây */
    int maxPrefix[n];
    int maxSuffix[n];

    maxPrefix[0] = a[0];
    for (int i=1; i<n; i++) {
        maxPrefix[i] = max(a[i], maxPrefix[i-1]);
    }

    maxSuffix[n-1] = a[n-1];
    for (int i=n-2; i>=0; i--) {
        maxSuffix[i] = max(a[i], maxSuffix[i+1]);
    }

    int result = -1;
    for (int i=1; i<=n-2; i++) {
        if (maxPrefix[i-1] - a[i] >= b && maxSuffix[i+1] - a[i] >= b) {
            if (maxPrefix[i-1] + maxSuffix[i+1] - 2*a[i] > result) {
                result = maxPrefix[i-1] + maxSuffix[i+1] - 2*a[i];
            }
        }
//        cout << "time " << i << "," << a[i] << " maxpre = " << maxPrefix[i-1] << ", maxsuf = " << maxSuffix[i+1] << ": result = " << result << endl;
    }

    cout << result << endl;
    return 0;
}
