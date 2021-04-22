#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
struct Block{
    int x,y,z;
    bool operator < (Block& b){
            return x < b.x && y < b.y;
    }
}b[N];

bool cmp(Block&b1, Block& b2){
    if(b1.x != b2.x) return b1.x > b2.x;
    if(b1.y != b2.y) return b1.y > b2.y;
    return b1.z > b2.z;
}

int main(){
    int t;
    int n,m;// number of blocks including permutations
    int S[N];
    t = 0;
    while(true){
        cin >> n;
        if(n == 0) break;
        t++;
        m = -1;
        for(int i = 0; i < n; i++){
            int x[3];
            cin >> x[0] >> x[1] >> x[2];
            sort(x,x+3);
            do{
                m++;
                b[m].x = x[0]; b[m].y = x[1]; b[m].z = x[2];
            }while(next_permutation(x,x+3));
        }
        sort(b,b+m+1,cmp);
        S[0] = b[0].z;
        int ans = S[0];
        for(int i = 1; i <= m; i++){// compute S[i]
            S[i] = b[i].z;
            for(int j = 0; j <= i-1; j++){
                if(b[i] < b[j]){
                    S[i] = max(S[i], S[j] + b[i].z);
                }
            }
            ans = max(ans,S[i]);
        }
        cout << "Case " << t << ": maximum height = " << ans << endl;
    }
}
