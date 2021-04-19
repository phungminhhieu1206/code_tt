#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
string str;
int n;
int x[N];
bool test = false;


void solution() {
    for(int i = 0; i < n; i++) {
        cout << x[i];
    }
    cout << endl;
}

bool check(string tmp, int arr[]) {
    for (int i = 0; i < n; i++) {
        if (tmp[i] != arr[i]) return false;
    }
        return true;
}

void Try(int k) {
    for(int v = 0; v <= 1; v++){
        if(true) {
            x[k] = v;
            if (k == n-1 && check(str, x)){
                    solution();
//                if (test) {
//                    solution();
//                    return;
//                }
//                if (check(str, x)) {
//                    test = true;
//                }
//                continue;
            }
            else Try(k+1);
        }
    }

}

int main() {
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++) {
        x[i] = atoi(str[i]);
        cout << x[i];
    }
}
