#include <bits/stdc++.h>
using namespace std;

int leftMax(int a[], int l, int r) {
    int maxx = a[r-1];
    int s = 0;
    for (int i=r; i>=l; i--) {
        s += a[i];
        maxx = max(s, maxx);
    }
    return maxx;
}

int rightMax(int a[], int l, int r) {
    int maxx = a[l];
    int s = 0;
    for (int i=l; i<=r; i++) {
        s += a[i];
        maxx = max(s, maxx);
    }
    return maxx;
}

int subMax(int a[], int l, int r) {
    if (l==r) return a[l];
    else {
        int m = l+(r-l)/2;
        int wL = subMax(a,l,m);
        int wR = subMax(a,m+1,r);
        int maxLM = leftMax(a,l,m);
        int maxRM = rightMax(a,m+1,r);
        int wM = maxLM + maxRM;
        return max(max(wL, wR), wM);
    }
}

int main() {
    int arr[] = {-16, 7, -3, 0, -1, 5, -4};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout << "Array: ";
    for (int i=0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int submaxx = subMax(arr, 0, arr_size-1);

    cout << "SubMax: " << submaxx << endl;

    return 0;


}
