#include <bits/stdc++.h>
using namespace std;

bool check(int x,int y){
    return x&y;
}
int main(){
    int n, m;
    cin >> n;
    int a[n];
    int x;
    for (int i=0;i<n;i++){
        cin >> a[i];
        x=x|(1<<a[i]);
    }

    cin >> m;
    int b[m];
    for (int j=0;j<m;j++) cin >> b[j];

    for (int j=0;j<m;j++){
        int y = 1<< b[j];
        if(!check(x, y)){
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}
