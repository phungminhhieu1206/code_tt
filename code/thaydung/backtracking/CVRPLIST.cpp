#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, K;
int Q;
int d[N];// demand of clients

// data structures for backtracking search
int y[N];// y[k] the first client point of the route k
int x[N];// x[v] is the next point of v on the route
bool visited[N];
int load[N];// accumulated demand on the route under construction
int segments;// number of segments of the solution
void solution(){
    // TODO
    for(int k = 1; k <= K; k++){
        cout << "Route[" << k << "]: ";
        cout << "0 -> ";// << y[k] << " -> ";
        int s = y[k];
        while(s > 0){
            cout << s << " -> ";
            s = x[s];
        }
        cout << "0" << " load = " << load[k] << endl;
    }
    cout << "---------------" << endl;
}
bool checkX(int v, int k){
    if(v == 0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}
void TryX(int s, int k){
    // try value for the next point of s (x[s]) on the kth route
    for(int v = 0; v <= n; v++){
        if(checkX(v,k)){
            x[s] = v;
            visited[v] = true;
            load[k] += d[v];
            segments += 1;
            if(v == 0){// return to he depot
                    if(k == K){
                        if(segments == n + K)
                            solution();
                    }else{
                        TryX(y[k+1],k+1);
                    }
            }else{
                TryX(v,k);
            }
            // recover
            visited[v] = false;
            load[k] = load[k] - d[v];
            segments = segments - 1;
        }
    }
}
bool checkY(int v, int k){
    if(visited[v]) return false;
    if(load[k] +d[v] > Q) return false;
    return true;
}
void TryY(int k){
    for(int v = y[k-1]+1; v <= n; v++){
        if(checkY(v,k)){
            y[k] = v;
            visited[v] = true;
            load[k] = load[k] + d[v];
            segments += 1;
            if(k == K){
                    // what to do
                    TryX(y[1],1);
            }else{
                TryY(k+1);
            }
            // recover when backtracking
            segments -= 1;
            visited[v] = false;
            load[k] = load[k] - d[v];
        }
    }
}


void input(){
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
}
void solve(){
    y[0] = 0;
    d[0] = 0;
    segments = 0;
    for(int k = 1; k <= K; k++) load[k] = 0;
    for(int v = 1; v <= n; v++) visited[v] = false;
    TryY(1);
}
int main(){
    input();
    solve();
}
