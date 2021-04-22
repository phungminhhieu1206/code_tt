#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector
    vector<int> Vint;
    vector<char> Vchar;
    vector<string> Vstring;

    for(int i=1; i<=10; i++) {
        Vint.push_back(i);
    }

    for (int i=0; i< Vint.size(); i++) {
        cout << Vint[i] << " ";
    }
    cout << endl << "------------------" << endl;

    // set
    set<int> Sint;
    for (int i=1; i<=10; i++) {
        Sint.insert(i);
    }

    for(set<int>::iterator p = Sint.begin(); p!=Sint.end(); p++) {
        int v = *p;
        cout << v << " ";
    }
    cout << endl;

    // ham find() tra ve con tro. O(logn)
    if(Sint.find(13) != Sint.end()) cout << "found" << endl;
    else cout << "not found" << endl;
    cout << endl << "------------------" << endl;

    // stack
    stack<int> s;
    for(int i=1; i<=10; i++){
        s.push(i);
    }

    while(!s.empty()) {
        int v = s.top(); s.pop();
        cout << "stack pop: " << v << endl;
    }
    cout << endl << "------------------" << endl;

    // queue
    queue<int> Q;
    for(int i=1; i<=10; i++){
        Q.push(i);
    }

    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        cout << "queue pop: " << v << endl;
    }
    cout << endl << "------------------" << endl;

    // map
    map<string,int> m;
    m["0"] = 0;
    m["1"] = 1;

    // tinh toan
    m["0"] = 2;

    cout << "map \"0\" = " << m["0"] << endl;
    cout << "map \"1\" = " << m["1"] << endl;

}
