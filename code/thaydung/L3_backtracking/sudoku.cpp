#include <bits/stdc++.h>
using namespace std;

int x[9][9];
bool mr[9][10];
bool mc[9][10];
bool ms[3][3][10];
bool found;
bool check(int v, int r, int c){
    return !mr[r][v] && !mc[c][v] && !ms[r/3][c/3][v];
}
void solution(){
    found = true;
    for(int i = 0; i <= 8; i++){
        for(int j = 0; j <= 8; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void Try(int r, int c){
    if(found) return;

    for(int v = 1; v <= 9; v++){
        if(check(v,r,c)){
            x[r][c] = v;
            mr[r][v] = true;
            mc[c][v] = true;
            ms[r/3][c/3][v] = true;
            if(r == 8 && c == 8) solution();
            else{
                if(c == 8) Try(r+1,0);
                else Try(r,c+1);
            }
            mr[r][v] = false;
            mc[c][v] = false;
            ms[r/3][c/3][v] = false;
        }
    }

}

int main(){
    for(int v = 1; v <= 9; v++){
        for(int r = 0; r <= 8; r++) mr[r][v] = false;

        for(int c = 0; c <= 8; c++) mc[c][v] = false;

        for(int I = 0; I <= 2; I++)
            for(int J = 0; J <= 2; J++)
                ms[I][J][v] = false;
    }
    found = false;
    Try(0,0);
}
