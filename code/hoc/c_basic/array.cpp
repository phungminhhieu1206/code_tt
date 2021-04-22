#include <bits/stdc++.h>
using namespace std;
const int N = 10;

int a[N];
int b[N]; // sao chep


int main() {
    char my_string[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    int size = sizeof(my_string)/sizeof(char); // 6
//    int size = sizeof(my_string)/sizeof(my_string[0]);
    cout << size << endl;

    for (int i=0; i<size-1; i++) {
        cout << my_string[i] << " ";
    }
    cout << endl;

    // sao chep mang
    for (int i=0; i<N; i++) {
        a[i] = rand();
        cout << "(" << i << ", " << a[i] << ")" << " ";
    }
    cout << endl;

    for (int i=0; i<N; i++) {
        b[i] = a[i];
        cout << "(" << i << ", " << b[i] << ")" << " ";
    }
    cout << endl;
}
