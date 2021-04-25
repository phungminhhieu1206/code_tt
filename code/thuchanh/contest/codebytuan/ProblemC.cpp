#include <bits/stdc++.h>
using namespace std;
int n, m, M, x;
vector<int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> M;
    int result = 0;
    for(int i = 0;i != n;i++){
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0;i < n;i++){
        int sum = 0;
        for(int j = i;j < n;j++){
            sum += a[j];
            if(sum >= m && sum <= M)
                result++;
        }
    }
    cout << result << endl;
    return 0;
}
