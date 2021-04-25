#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n;
int c[N][N];
int x[N];
int f;// do dai lo trinh duoc tich luy trong qua trinh duyet
int f_min; // ghi nhan ky luc (do dai lo trinh ngan nhat tim thay)
bool visited[N];// mang danh dau
int cm;// khoang cach nho nhat trong ma tran chi phi
void input(){
    cin >> n;
    cm  = 1e9;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            if(i != j && c[i][j] < cm) cm = c[i][j];
        }
}
bool check(int v, int k){
    return !visited[v];
}
void updateBest(){
    if(f + c[x[n]][x[1]] < f_min){
        f_min = f + c[x[n]][x[1]];
        for(int i = 1; i <= n; i++) cout << x[i] << " ";
        cout << "update best " << f_min << endl;
    }
}
vector<int> candidates(int cur){
    int t[N];
    int sz = 0;
    for(int v = 1;  v<= n; v++){
        if(!visited[v]){
            t[sz] = v; sz++;
        }
    }

    for(int i = 0; i < sz; i++)
        for(int j = i+1; j < sz; j++)
    if(c[cur][t[i]] > c[cur][t[j]]){
        int tmp = t[i]; t[i] = t[j]; t[j] = tmp;
    }

    vector<int> cand;
    for(int i = 0; i < sz; i++)
        cand.push_back(t[i]);
    return cand;
}
void Try(int k){// thu gia tri cho x[k] khi da biet x[1],..., x[k-1]
    //for(int v = 1; v <= n; v++){

    vector<int> cand = candidates(x[k-1]);

    //cout << "cand = ";
    //for(int i = 0; i < cand.size(); i++) cout << "(" << cand[i] << "," << c[x[k-1]][cand[i]] << ") "; cout << endl;
    for(int i = 0; i < cand.size(); i++){
            int v = cand[i];
        //if(check(v,k)){
            x[k] = v;// di them 1 chang tu x[k-1] den x[k]
            f = f + c[x[k-1]][x[k]];// update
            visited[v] = true;
            if(k == n) updateBest();
            else{
                int g = f + cm*(n-k+1);
                if (g < f_min)
                    Try(k+1);
                else{// f_min <= g
                    // CUT-OFF
                }
            }
            visited[v] = false;
            f = f - c[x[k-1]][x[k]];
        }
    //}

}
int main(){
    freopen("TSP-14.inp","r",stdin);
    input();
    for(int v = 1; v <= n; v++) visited[v] = false;
    x[1] = 1;
    visited[1] = true;
    f = 0;
    f_min = 1e9;
    Try(2);
    cout << f_min << endl;
}
