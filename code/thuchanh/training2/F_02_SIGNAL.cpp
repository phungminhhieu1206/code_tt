#include <bits/stdc++.h>
using namespace std;
int n, b;

int main() {

    cin >> n >> b;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int result = -1;
    for (int i=1; i<n-1; i++) {
        vector<int> trai;
        vector<int> phai;
        int maxtrai = a[0];
        int maxphai = a[i+1];

        for (int t=0; t<=i-1; t++) {
            trai.push_back(a[t]);
            if (a[t] > maxtrai) maxtrai = a[t];
        }

        for (int p=i+1; p<n; p++) {
            phai.push_back(a[p]);
            if (a[p] > maxphai) maxphai = a[p];
        }


        if (maxtrai - a[i] >= b && maxphai - a[i] >= b) {
            if (maxtrai + maxphai - 2*a[i] > result) {
                result = maxtrai + maxphai - 2*a[i];
            }
        }

    }

    cout << result << endl;
    return 0;
}
