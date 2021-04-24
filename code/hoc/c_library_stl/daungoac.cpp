#include <bits/stdc++.h>
using namespace std;

bool check(string str) {
	stack<char> s;
	for(int i=0; i<str.length(); i++) {
		char c = str[i];
		if(c == '(' || c == '{' || c == '[') s.push(c);
		else {
			if(!s.empty() && c == ']' && s.top() == '[')
			    s.pop();
			else if(!s.empty() && c == '}' && s.top() == '{')
			    s.pop();
			else if(!s.empty() && c == ')' && s.top() == '(')
			    s.pop();
			else return 0;
		}
	}
	return 1;
}
int main() {
	int t; cin >> t;
	while(t--) {
		string str; cin >> str;
		if(check(str)) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
