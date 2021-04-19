#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n], s=0;
    long long modd=pow(10,9)+7;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        s+=a[i];
    }
    cout << s%modd << endl;
    return 0;
}
