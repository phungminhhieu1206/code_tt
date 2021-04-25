#include <bits/stdc++.h>
using namespace std;
char str[1000];
stack<char> s;
long long cout_s = 0, n;

void TRY(int k){
    if(k == n){
        if(s.empty())
            cout_s++;
    } else {
        if(s.size() < (n-k+1)){
            if(str[k] != '?'){
                char c = str[k];
                if(c == '('){
                    s.push(c);
                    TRY(k+1);
                    s.pop();
                } else {
                    if(!s.empty()){
                        s.pop();
                        TRY(k+1);
                        s.push('(');
                    }
                }
            }
            else {
                if(s.empty()){
                    s.push('(');
                    TRY(k+1);
                    s.pop();
                }
                else if(s.size() == n-k){
                    s.pop();
                    TRY(k+1);
                    s.push('(');
                }
                else {
                    s.push('(');
                    TRY(k+1);
                    s.pop();
                    s.pop();
                    TRY(k+1);
                    s.push('(');
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    n = strlen(str);
    TRY(0);
    cout_s %= 1000000007;
    cout << cout_s << endl;
    return 0;
}
