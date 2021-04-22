#include <bits/stdc++.h>
using namespace std;
const unsigned int N = 20;
const int INF = 1e9;
int n;
int c[N][N];
int F[N][1 << N];// memory for storing solutions to subproblems

string bin(unsigned int S){
    string s = "";
    for(int i = 31; i >= 0; i--){
        int b = S & (1 << i);
        if(b == (1 << i)) s = s + "1"; else s = s + "0";
    }
    return s;
}
unsigned int addElement(unsigned int S, int x){
    return S | (1 << x);
}
unsigned int removeElement(unsigned int S, int x){
    return S & (~(1 << x));
}
bool contains(unsigned int S, int x){
    return (S & (1 << x)) == (1 << x);
}
void input(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];

}

int TSP(int i, unsigned int S){
    // return the shorest path from i visiting all points of S and comback to 0;
    if(S == 0){// base case
        F[i][S] = c[i][0];
    }else{
        if(F[i][S] == -1){// solution not available
            F[i][S] = INF;
            for(int j = 1; j < n; j++){
                if(contains(S,j)){
                    unsigned int Sj = removeElement(S,j);
                    F[i][S] = min(F[i][S], c[i][j] + TSP(j,Sj));
                }
            }
        }
    }
    return F[i][S];
}
int main(){
    memset(F,-1,sizeof(F));
    freopen("TSP-15.inp","r",stdin);
    input();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    unsigned int S = (1 << n) - 2;
    //cout << "n = " << n << " S = " << bin(S) << endl;
    cout << TSP(0,S);
}
