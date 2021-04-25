#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    while(x--) {
        unsigned long long a, b, c;
        scanf("%llu %llu", &a, &b);
        c = a%10+b%10;
        unsigned long long tmp = a/10+b/10+c/10;
        if(tmp == 0) {
            cout << c%10 << endl;
            return 0;
        }
        cout << tmp << (c)%10 << endl;
    }
    return 0;
}
