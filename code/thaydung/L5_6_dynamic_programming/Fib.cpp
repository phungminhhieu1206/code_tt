#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int memory[MAX];

int F(int n){
    if(n <= 1){
        memory[n] = 1; return 1;
    }
    if(memory[n] > 0) return memory[n];
    memory[n] = F(n-1) + F(n-2);
    return memory[n];
}

int main(){
    for(int i = 0; i < MAX; i++) memory[i] = 0;// chua co bai toan con nao duoc giai
    cout << F(5) << endl;

    memory[0] = 1; memory[1]  = 1;
    for(int n = 2; n <= 10; n++){
        memory[n] = memory[n-1] + memory[n-2];
        cout << memory[n] << endl;
    }

}

