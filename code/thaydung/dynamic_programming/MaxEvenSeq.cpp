#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int a[MAX];
int n;
int S0[MAX];// tong chan
int S1[MAX];// tong le
bool solved0[MAX];//  solved0[i] = true neu tong chan S0[i] ton tai
bool solved1[MAX];// solved1[i] = true neu tong le S1[i] ton tai

// trace
int startIndex1[MAX];// chi so bat dau cua day le lon nhat ket thuc tai a[i]
int startIndex0[MAX];// chi so bat dau cua day chan lon nhat ket thuc tai a[i]

void input(){
    /*
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    */
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
}
void solve(){
    int ans;
    if(a[1]%2 == 0){
        S0[1] = a[1]; solved0[1] = true; solved1[1] = false;
        startIndex0[1] = 1;
    }else{
        S1[1] = a[1]; solved0[1] = false; solved1[1] = true;
        startIndex1[1] = 1;
    }

    for(int i = 2; i <= n; i++){
        if(a[i]%2 == 0){// a[i] chan
            if(solved0[i-1]){
                if(S0[i-1] > 0){
                        S0[i] = a[i] + S0[i-1]; startIndex0[i] = startIndex0[i-1];
                }else{
                    S0[i] = a[i]; startIndex0[i] = i;
                }
                //S0[i] = max(a[i],a[i] + S0[i-1]);
            }else{
                S0[i] = a[i]; startIndex0[i] = i;
            }
            solved0[i] = true;

            if(solved1[i-1]){
                S1[i] = S1[i-1] + a[i]; solved1[i] = true;
                startIndex1[i] = startIndex1[i-1];
            }else{
                solved1[i] = false;
            }
        }else{// a[i] le
            if(solved1[i-1]){
                    S0[i] = S1[i-1] + a[i]; solved0[i] = true;
                    startIndex0[i] = startIndex1[i-1];
            }else{
                solved0[i] = false;
            }
            if(solved0[i-1]){
                if(S0[i-1] > 0){
                    S0[i] = S0[i-1] + a[i]; startIndex0[i] = startIndex1[i-1];
                } else{
                    S0[i] = a[i]; startIndex0[i] = i;
                }
                //S1[i] = max(a[i], a[i] + S0[i-1]);
            }else{
                S1[i] = a[i]; startIndex1[i] = i;
            }
            solved1[i] = true;
        }
    }
    bool notfound = true;
    int selected = -1;
    for(int i = 1; i <= n; i++){
        if(solved0[i]){
            if(notfound) {
                ans = S0[i]; selected = i;
                notfound = false;
            }else{
                if(ans < S0[i]) {
                    ans = S0[i];
                    selected = i;
                }
            }
        }
    }
    if(notfound) cout << "NOT_FOUND";
    else
    cout << ans;

    cout << "from " << selected << " to " << startIndex0[selected] << endl;
}

int main(){
    input();
    solve();
}
