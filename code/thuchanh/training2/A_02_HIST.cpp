#include <bits/stdc++.h>
using namespace std;

int main() {
//    while (true) {
//        int n;
//        cin >> n;
//        if (n == 0) break;
//        int a[n];
//        for (int i=0; i<n; i++)
//            cin >> a[i];
//    }

    /* Làm một bài toán con */
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];

    int result = -1;

    /* Tính diện tích max ở đây */
    int c[n][n]; // ma trận chiều cao min
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c[i][j] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        c[i][i] = a[i];
        for (int j=i+1; j<n; j++) {
            c[i][j] = min(c[i][j-1], a[j]);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int tmp = (j-i+1) * c[i][j];
            if (result < tmp) {
                result = tmp;
            }
        }
    }


    cout << result << endl;
    return 0;
}
