#include <bits/stdc++.h>
using namespace std;

// O(n^2): 2 vong for bth
long tinhmaxx(int a[], int n){
    long maxx=a[0];
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=i;j<n;j++){
            s+=a[j];
            maxx = maxx>s?maxx:s;
        }
    }
    return maxx;
}

// O(n): quy hoach dong
long pmh(int a[], int n){
    long maxx = a[0];
    int s[n];
    s[0]=a[0];
    maxx=s[0];
    for(int i=1;i<n;i++){
        if(s[i-1]>0) s[i]=s[i-1]+a[i];
        else s[i]=a[i];
        maxx = maxx>s[i]?maxx:s[i];
    }
    return maxx;
}

int main(){
    unsigned int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) cin >> a[i];
    cout << pmh(a,n) << endl;
//    cout << tinhmaxx(a,n) << endl;
    return 0;
}
