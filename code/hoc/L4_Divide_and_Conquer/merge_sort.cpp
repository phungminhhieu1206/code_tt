#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int t = 0;

void mergeTwoArr(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r) {
    if (l>=r) {
        return;
    } else {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        mergeTwoArr(arr, l, m, r);
    }
}

void mergeTwoArr(int arr[], int l, int m, int r) {
    int n1 = m-l+1; // số phần tử mảng 1 bắt đầu từ l kết thúc tại m
    int n2 = r-m; // số phần tử mảng 2 bắt đầu từ m+1 kết thúc tại r

    int L[n1], R[n2];

    // copy data
    for (int i = 0; i < n1; i++)
        L[i] = arr[l+i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m+1+j];

    int i=0,j=0,k=l;

    while(i < n1 && j < n2) { // vì tính từ 0
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before: ";
    for (int i=0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr_size-1);

    cout << "Array after: ";
    for (int i=0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}















