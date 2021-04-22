/*
    - Sắp xếp với mảng cấu trúc, mỗi phần tử mảng là 1 kiểu cấu trúc, key-value
*/

#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;
struct Element{
    int id;
    int key;
};

Element e[100];

// ver_2
bool cmp(Element e1, Element e2) {
    // không giảm
//    return e1.key < e2.key;

    // không tăng
    return e1.key > e2.key;
}

int main() {
    int n = 10;
    for (int i=0; i<n; i++){
        e[i].id = i+1;
        e[i].key = rand()%100;
    }

    for (int i=0; i<n; i++)
        cout << "(" << e[i].id << ", " << e[i].key << ")" << endl;

    sort(e, e+n, cmp);

    cout << "after sort with key:" << endl;
    for (int i=0; i<n; i++)
        cout << "(" << e[i].id << ", " << e[i].key << ")" << endl;

}
