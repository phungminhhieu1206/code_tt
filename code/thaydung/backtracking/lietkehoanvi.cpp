#include <bits/stdc++.h>
using namespace std;
int x[100];
int n;
bool visited[100];
int A[100][100];
int cnt;
bool check(int v, int k){
    if(visited[v]) return false;
    for(int i = 1; i <= k-1; i++){
        if(A[v][x[i]] == 1) return false;
    }
    return true;
}
void solution(){
    cnt++;
    for(int i = 1; i <= n ;i++) cout << x[i] << " "; cout << endl;
}
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            A[i][j] = 0;
    int K;
    cin >> K;
    for(int k = 1; k <= K; k++){
        int i,j;
        cin >> i >> j;
        A[i][j] = 1;
    }

}
void Try(int k){// thu gia tri cho x[k] khi da biet x[1],..., x[k-1]
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = true;// update statue
            if(k == n) solution();
            else Try(k+1);
            visited[v] = false;// recover when backtracking
        }
    }
}
int main(){
    //n = 3;
    input();
    for(int v = 1; v <= n; v++) visited[v] = false;
    Try(1);
    cout << cnt;
}
