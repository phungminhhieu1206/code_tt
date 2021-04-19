#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long a, b;
    unsigned long long modd = pow(10,9)+7;
    cin >> a >> b;
    cout << ((a%modd)+(b%modd))%modd << endl;
    return 0;
}
