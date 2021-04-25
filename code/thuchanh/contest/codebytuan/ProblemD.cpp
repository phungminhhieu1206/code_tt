#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int z;
    int x = 0;
    int y = 0;
    for(int i = 0;i != n;i++){
        cin >> z;
        a.push_back(z);
    }
    int left = 0, right = -1, top = -1, curr = 0;
    for(int i = 0;i < n-1;i++){
//        cout << left << " " << top << " " << right << " " << curr << endl;
        if(a[i] == a[i+1]){
            if(right != -1 && top != -1){
                curr = top - left < right - top ? top - left : right - top;
                x = x > curr ? x : curr;
            }
            left = i+1;
            top = -1;
            right = -1;
        } else if(a[i] > a[i+1]) {
            if(top == -1){
                if(left != i){
                    top = i;
                } else {
                    left = i+1;
                }
            }
            if(top != -1){
                right = i+1;
            }
        } else if(a[i] < a[i+1]) {
            if(top != - 1 && right != -1){
                curr = top - left < right - top ? top - left : right - top;
                x = x > curr ? x : curr;
                left = i;
                top = -1;
                right = -1;
            }
        }
    }
    if(right != -1 && top != -1){
        curr = top - left < right - top ? top - left : right - top;
        x = x > curr ? x : curr;
    }

    left = 0;
    right = -1;
    top = -1;
    curr = 0;
    for(int i = 0;i < n-1;i++){
//        cout << left << " " << top << " " << right << " " << curr << endl;
        if(a[i] == a[i+1]){
            if(right != -1 && top != -1){
                curr = top - left < right - top ? top - left : right - top;
                y = y > curr ? y : curr;
            }
            left = i+1;
            top = -1;
            right = -1;
        } else if(a[i] > a[i+1]) {
            if(top != - 1 && right != -1){
                curr = top - left < right - top ? top - left : right - top;
                y = y > curr ? y : curr;
                left = i;
                top = -1;
                right = -1;
            }
        } else if(a[i] < a[i+1]) {
            if(top == -1){
                if(left != i){
                    top = i;
                }else{
                    left = i+1;
                }
            }
            if(top != -1){
                right = i+1;
            }
        }
    }
    if(right != -1 && top != -1){
        curr = top - left < right - top ? top - left : right - top;
        y = y > curr ? y : curr;
    }
    cout << x << " " << y << endl;
    return 0;
}

