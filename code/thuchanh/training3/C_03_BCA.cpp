#include <bits/stdc++.h>

using namespace std;
int n_teachers, n_courses;

const int N = 40;
bool can_teach[N][N];
bool conflict[N][N];

int assign[N];     // cac course dc gan voi giao vien
int load[N] = {0}; // khoi luong
int best_load = INT_MAX;

bool process_conflict(int i, int u) {
    // giang vien i, mon hoc
    for (int j=1; j< n_courses; j++) {
        if (assign[j] == i && conflict[u][j]) return false;
    }
    return true;
}

void TRY(int u) {
    if (u > n_courses) {
        int max_load = 0;
        for (int i = 1; i <= n_teachers; i++) {
            max_load = max(max_load, load[i]);
        }
        best_load = min(best_load, max_load);
        return;
    }

    for (int i = 1; i <= n_teachers; i++) {
        if (can_teach[i][u] && process_conflict(i, u)) {
            load[i] += 1;
            assign[u] = i;
            if (load[i] < best_load)
                TRY(u+1);
            load[i] -= 1;
            assign[u] = 0;

        }
    }
}

void input() {
    int k;
    cin >> n_teachers >> n_courses;
    for (int i = 1; i <= n_teachers; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int temp_course;
            cin >> temp_course;
            can_teach[i][temp_course] = true;
        }
    }

    cin >> k;
    int i, j;
    for (int x = 1; x <= k; x++) {
        cin >> i >> j;
        conflict[i][j] = true;
        conflict[j][i] = true;
    }
}

int main() {
    input();
    TRY(1);
    cout << best_load;

    return 0;
}
