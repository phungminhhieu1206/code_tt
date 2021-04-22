#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;
struct Element{
    int id;
    int key;
};
bool cmp(Element& e1, Element& e2){
    //return e1.key < e2.key;
    return e1.key > e2.key;

}
vector<Element> e;
int main(){
    int n = 10;
    for(int i = 0; i < n; i++){
        Element ei;
        ei.id = i+1;
        ei.key = rand()%100;
        e.push_back(ei);
    }
    for(int i = 0; i < n; i++) cout << "(" << e[i].id << "," << e[i].key << ") "; cout << endl;

    sort(e.begin(),e.end(),cmp);

    cout << "After sorting" << endl;
    for(int i = 0; i < n; i++) cout << "(" << e[i].id << "," << e[i].key << ") "; cout << endl;


}
