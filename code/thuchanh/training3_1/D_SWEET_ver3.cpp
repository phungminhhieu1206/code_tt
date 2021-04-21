
// C++ program for above implementation
#include<iostream>

using namespace std ;

int nCr(int n, int r) {
    int fac[100] = {1} ;

    for (int i = 1 ; i < n + 1 ; i++) {
        fac[i] = fac[i - 1] * i ;
    }

    int ans = fac[n] / (fac[n - r] *
                        fac[r]) ;
    return ans ;
}

// Driver Code
int main() {
    int n,k;
    cin >> k >> n;

    int ans = nCr(n + k - 1, k);

    cout << ans ;

    return 0 ;
}

// This code is contributed
// by ANKITRAI1
