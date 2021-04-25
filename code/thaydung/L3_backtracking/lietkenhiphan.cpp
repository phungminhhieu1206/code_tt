#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int x[N];
int n;
int cnt = 0;
// khong duoc phep 1 bit 1 dung canh nhau
bool check(int v, int k){
    //if(x[k-1] == 1 && v == 1) return false;
    if(k == 1) return true;
    return x[k-1] + v <= 1;
}
void solution(){
    cnt ++;
    cout << cnt << ": ";
    for(int i = 1; i <= n; i++) cout << x[i]; cout << endl;
}
void Try(int k){// thu gia tri cho x[k], da biet x[1], x[2], ...., x[k-1]
    for(int v = 0; v<=1;v ++){
        if(check(v,k)){
            x[k] = v;
            if(k == n) solution();
            else Try(k+1);
        }
    }
}
int main(){
    n = 10;
    cnt = 0;
    Try(1);
}
