#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s;
    for (int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    sort(s.begin(), s.end());

    vector<int> v1;
    vector<int> v2;
    vector<int> zero;

    for (int i=0; i<n; i++) {
        if(s[i] < 0) {
            v1.push_back(s[i]);
        } else if (s[i] > 0) {
            v2.push_back(s[i]);
        } else {
            zero.push_back(s[i]);
        }
    }

    if (v2.size() == 0) {
        v2.push_back(v1.back()); v1.pop_back();
        v2.push_back(v1.back()); v1.pop_back();
    }

    if (v1.size() % 2 == 0) {
        zero.push_back(v1.back());
        v1.pop_back();
    }

    cout << v1.size() << " ";
    for (int i=0; i<v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << v2.size() << " ";
    for (int i=0; i<v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    cout << zero.size() << " ";
    for (int i=0; i<zero.size(); i++) {
        cout << zero[i] << " ";
    }
    cout << endl;




}
