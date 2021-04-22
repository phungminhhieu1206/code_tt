#include <bits/stdc++.h>
using namespace std;
#define MAX  1000000
int memory[MAX];
bool solved[MAX];// solved[i] = true: BT con doi voi i da duoc giai, memory[i]
int a[MAX];
int n;

int S(int i){
    if(i == 1){// BT con nho nhat
        memory[1] = a[1];
    }else{
        if(!solved[i]){
            memory[i] = max(S(i-1) + a[i], a[i]);
        }
    }
    solved[i] = true;// BT con doi voi i da duoc giai
    return memory[i];
}
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}
void solve(){
    for(int i = 1; i <= n; i++) solved[i] = false;
}
int main(){
    input();
    int ans = S(1);
    for(int i = 2; i <= n; i++){
        ans = max(ans, S(i));
        cout << "S(" << i << ") = " << S(i) << ", ans = " << ans << endl;

    }
}
