#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
int n, m, M;
int Q;
int a[N];

void input() {
    cin >> n >> m >> M;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
}


int main(){
    input();
    Q = 0;
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=i;j<n;j++){
            s+=a[j];
            if (m<=s && s<=M) {
                Q++;
            }
        }
    }
    cout << Q;
}
