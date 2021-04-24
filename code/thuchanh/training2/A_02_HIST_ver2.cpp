#include <bits/stdc++.h>
using namespace std;

/*
    - Ghép bài toán con vào bài toán lớn
    - Chú ý về tràn số, đặt kiểu dữ liệu phù hợp
*/

int main() {

    while (true) {
        long long n;
        cin >> n;
        if (n == 0) return 0;
        long long a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];

        long long result = 0;

        /* Tính diện tích max ở đây */
        long long c[n][n]; // ma trận chiều cao min
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
                long long tmp = (j-i+1) * c[i][j];
                if (result < tmp) {
                    result = tmp;
                }
            }
        }


        cout << result << endl;
    }

    return 0;
}
