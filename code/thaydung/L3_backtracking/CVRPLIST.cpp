#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, K; // n là số điểm giao, K là số xe có
int Q; // số thùng tối đa 1 xe chở được
int d[N]; // nhu cầu của khách hàng i là d[i] thùng

// data structures for backtracking search
int y[N];// y[k] điểm đầu tiên của lộ trình thứ k (hoặc xe thứ k)
int x[N];// x[v] điểm tiếp theo của (điểm giao v) trên lộ trình k đã chọn
bool visited[N]; // đánh dấu đã giao
int load[N];// Lưu số thùng trên lộ trình k (số thùng xe thứ k đã chở), index thuộc 1...K
int segments;// Lưu số chặng đi của cả đội, khi segments = n + K là hoàn thành K lộ trình của K xe.

void solution() {
    // TODO
    // In lần lượt K lộ trình
    for(int k = 1; k <= K; k++) {
        cout << "Route[" << k << "]: ";
        cout << "0 -> ";// << y[k] << " -> ";
        int s = y[k];

        // Trong lộ trình thứ k in ra các điểm đã đi qua
        while(s > 0) {
            cout << s << " -> ";
            s = x[s];
        }
        cout << "0" << " load = " << load[k] << endl;
    }
    cout << "---------------" << endl;
}
bool checkX(int v, int k) {
    if(v == 0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

void TryX(int s, int k) { // Thử cho chặng thứ k, bắt đầu từ điểm s.
    // try value for the next point of s (x[s]) on the k-th route
    for(int v = 0; v <= n; v++) { // chặng thành phần có thể bắt đầu từ điểm 0
        if(checkX(v,k)) {
            x[s] = v;
            visited[v] = true;
            load[k] += d[v];
            segments += 1;
            /*
                - Xác định khi nào thì thử xong chặng k. Rõ ràng là khi v = 0 => if (v=0) //TODO
                - Tuy nhiên cần chú ý:
                    + Nếu đang thử chặng thứ K thì tức là xong toàn bộ -> in ra lộ trình K chặng
                    + Ngược lại thì là đang thử chặng k < K, do đó sẽ thử tiếp cho chặng k + 1.
            */
            if(v == 0) { // return to he depot
                if(k == K) {
                    if(segments == n + K)
                        solution();
                } else {
                    TryX(y[k+1],k+1);
                }
            } else {
                TryX(v,k); // ngược lại thì lại tiếp tục thử giá trị tiếp cho chặng k, bắt đầu từ điểm v đã xác định
            }
            // recover
            visited[v] = false;
            load[k] = load[k] - d[v];
            segments = segments - 1;
        }
    }
}
bool checkY(int v, int k) {
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}
void TryY(int k) {
    /*
        - Thử giá trị cho y[k] khi đã biết y[k-1]
        - Tính tập các giá trị có thể nhận của y[k]
        - y[k] > y[k-1] => bắt đầu từ y[k-1] + 1 đến n là giá trị cuối cùng có thể
    */
    for(int v = y[k-1]+1; v <= n; v++) {
        /*
            - v : đại diện cho điểm đi qua. Các thông số đi kèm là:
                + d[v] là yêu cầu số thùng giao tại điểm v
                + segments tăng khi qua v.
        */
        if(checkY(v,k)) {
            y[k] = v;
            visited[v] = true;
            load[k] = load[k] + d[v]; // trọng tải trên chặng thứ k được cộng thêm khi đi qua điểm v
            segments += 1; // mỗi lần đi qua 1 v thì tăng segments
            if(k == K) { // đến đây là đã xác định xong bộ giá trị cho y[1]...y[K], tức mỗi xe đều chắc chắn được giao
                // what to do
                TryX(y[1],1); // Bắt đầu thử tiếp cho chặng đầu tiên, chặng đầu tiên bắt đầu từ điểm y[1].
            } else {
                TryY(k+1);
            }
            // recover when backtracking
            segments -= 1;
            visited[v] = false;
            load[k] = load[k] - d[v];
        }
    }
}


void input() {
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
}

void solve() {
    y[0] = 0;
    d[0] = 0;
    segments = 0;
    for(int k = 1; k <= K; k++) load[k] = 0;
    for(int v = 1; v <= n; v++) visited[v] = false;
    TryY(1);
}

int main() {
    input();
    solve();
}
