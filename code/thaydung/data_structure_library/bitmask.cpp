#include <bits/stdc++.h>
using namespace std;

string bin(unsigned int n){
    string s = "";
    for(int d = 31; d >= 0; d--){
        int i = 1 << d;
        if(n & i) s = s + "1"; else s = s + "0";
    }
    return s;
}
bool contains(unsigned int S, int x){
    if(S & (1 << x)) return true; else return false;
}
unsigned int residual(unsigned int S){
    return (1 << 31) - 1 - S;
}
int main(){

    //for(int x = 0; x <= 256; x++) cout << x << ": " << bin(x) << endl;
    unsigned int x = 1 << 31;
    unsigned int y = x - 1;
    cout << "x = " << x << " bin " << bin(x) << endl;
    cout << "y = " << y << " bin " << bin(y) << endl;

    unsigned int S = 1234;
    unsigned int R = residual(S);
    cout << "S = " << bin(S) << endl;
    cout << "R = " << bin(R) << endl;
     //int x = (1 << 0) | (1 << 3) | (1 << 4);
    //cout << "value x = " << x << ": " << bin(x) << " contains = " << contains(x,9) << endl;

}
