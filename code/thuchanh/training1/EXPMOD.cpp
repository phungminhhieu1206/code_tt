#include <bits/stdc++.h>
using namespace std;

unsigned long long sqr(unsigned long long x) {
    return x*x;
}

unsigned long long pow(unsigned long long a, unsigned long long b, unsigned long long MOD) {
    if (b == 0) return 1 % MOD;
    else if (b % 2 == 0)
            return sqr(pow(a, b/2)) % MOD;
    else
            return a * (sqr(pow(a, b/2)) % MOD) % MOD;
}

int main(){
    unsigned long long a, b;
    unsigned long long m = 1000000007;
    cin >> a >> b;
//    cout << pow(a, b, m) << endl;
    unsigned long long tmp = a%m;
    unsigned long long sodu = tmp;
    unsigned long long b1 = b/2;

    for(unsigned long long i=2;i<=b1;i++){
        sodu = (sodu*tmp)%m;
    }
    sodu = (sodu*sodu)%m;

    if (b%2==0) {
        cout << sodu << endl;
    } else {
        sodu = (sodu*tmp)%m;
        cout << sodu << endl;
    }

    return 0;
}
