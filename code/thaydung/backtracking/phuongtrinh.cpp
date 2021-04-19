#include <bits/stdc++.h>
using namespace std;
int x[100];
int n, M;
int T; // accumulated sum
int cnt;
bool check(int v, int k){
    if(k < n) return true;
    return T + v == M;
}
void solution(){
    cnt++;
    cout << cnt << ": ";
    for(int i = 1; i <= n ;i++) cout << x[i] << " "; cout << endl;
}
void Try(int k){// thu gia tri cho x[k] khi da biet x[1],..., x[k-1]
    for(int v = 1; v <= M - T - (n-k); v++){
        if(check(v,k)){
            x[k] = v;
            T = T + v;// update status
            if(k == n) solution();
            else Try(k+1);
            T = T - v;// recover when backtracking
        }
    }
}
int main(){
    n = 10;
    M = 20;
    cnt = 0;
    Try(1);
}
