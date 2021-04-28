#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

int f(double tmp, const vector<double> &V) {
    int res = 0;
    for(const double &value: V) {
        res += floor(value/tmp); // số nguyên lớn nhất không lớn hơn giá trị thực của value/tmp
    }

    return res;
}


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n_test;
    cin >> n_test;
    while (n_test--) {
        int N, F; // N bánh, F người
        cin >> N >> F;
        // mảng lưu thể tích của từng chiếc bánh
        vector <double> V(N); // Khởi tạo N giá trị mặc định ban đầu cho vector V, tại đây V.size() = N
        for (double &value: V) {
            int radius;
            cin >> radius;
            value = PI * radius * radius; // tính giá trị cho phần tử của vector V
        }

//        for (int i=0; i<V.size(); i++) {
//            int radius;
//            cin >> radius;
//            V[i] = PI * radius * radius;
//        }

        double low = 0, high = PI * 1e4 * 1e4;
        while (high - low > 1e-6) { // vì lấy 6 chữ số sau dấu phảy
            double mid = (high +  low) /2;
            if (f(mid, V) < (F+1)) {
                high = mid;
            } else {
                low = mid;
            }
            //cerr << low << "+" << high << endl;
        }
        cout << fixed << setprecision(6) << low << endl;


    }
    return 0;
}
