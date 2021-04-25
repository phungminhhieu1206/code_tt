#include <bits/stdc++.h>
using namespace std;

int n, k;
int C[40][40];
int l = 0; //so hanh khach tren xe
int mark[40] = {0}; // mảng đánh dấu
int traveled_point[40] = {0};
int curr;
int best_cost = INT_MAX;
int cmin = INT_MAX;

void input() {
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> C[i][j];
            if (i != j) {
                cmin = min(cmin, C[i][j]); // tìm ra cmin để đánh giá nhánh cận
            }
        }
    }
}

int sum_array() {
    int sum = 0;
    int pre = 0;
    int crr = 0;
    for (int i = 1; i <= 2 * n; i++) {
        crr = traveled_point[i];
        pre = traveled_point[i - 1];
        sum += C[pre][crr];
        //cout << crr << "+";
    }
    sum += C[crr][0];
    //cout << endl;

    return sum;
}

void TRY(int p_count) {
    int pre_point; // điểm trước đó
    if (p_count > 2 * n) {
        // pre_point = traveled_point[p_count-1];
        // best_cost = min(best_cost, curr + C[pre_point][0]);
        int sum = sum_array();
        best_cost = min(best_cost, sum);
        return;
    }

    if (l < k) {
        for (int i = 1; i <= n; i++) {
            if (!mark[i]) {
                pre_point = traveled_point[p_count - 1];
                traveled_point[p_count] = i;
                l += 1;
                curr += C[pre_point][i];
                mark[i] = 1;
                int bound;
                bound = curr + (2 * n + 1 - p_count) * cmin;
                if (bound < best_cost) {
                    TRY(p_count + 1);
                }

                l -= 1;
                mark[i] = 0;
                curr -= C[pre_point][i];
            }
        }
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        if (mark[i - n] && (!mark[i])) {
            pre_point = traveled_point[p_count - 1];
            traveled_point[p_count] = i;
            mark[i] = 1;
            l -= 1;
            curr += C[pre_point][i];

            int bound;
            bound = curr + (2 * n + 1 - p_count) * cmin;
            if (bound < best_cost) {
                TRY(p_count + 1);
            }

            l += 1;
            mark[i] = 0;
            curr -= C[pre_point][i];
        }
    }
}

int main() {
    curr = 0;
    traveled_point[0] = 0;
    input();
    TRY(1);
    cout << best_cost << endl;

    return 0;
}
