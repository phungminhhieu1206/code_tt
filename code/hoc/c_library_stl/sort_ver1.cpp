#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;

int main() {
    n = 6;
    for(int i=1; i<=n; i++) {
        a[i] = 10-i;
    }
    cout << "before sort: ";
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }

    // tang dan
    sort(a+1, a+n+1);

    cout << endl << "after sort: ";
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // giam dan
    sort(a+1, a+n+1, greater<int>());

    cout << endl << "after sort: ";
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
