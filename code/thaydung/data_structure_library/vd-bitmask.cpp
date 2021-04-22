#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int d = 0; d <= 31; d++){
        unsigned int i = (1 << d);
        cout << "(1 << " << d << ") = " << i << endl;
    }
}
