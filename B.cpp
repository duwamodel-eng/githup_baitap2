#include<bits/stdc++.h>
#define int long long
#define ll long long
#define el '\n'
const int Mod = 1e9 + 7;
using namespace std;

// Hàm kiểm tra số nguyên tố
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra nếu tổng liền kề là số hợp
bool is_valid_permutation(const vector<int>& p) {
    for (size_t i = 0; i + 1 < p.size(); ++i) {
        if (is_prime(p[i] + p[i + 1])) {
            return false;
        }
    }
    return true;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 3) {
            cout << "-1\n";
            continue;
        }

        // Chia số chẵn và lẻ
        vector<int> evens, odds;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) evens.push_back(i);
            else odds.push_back(i);
        }

        // Ghép dãy
        vector<int> result;
        for (int x : evens) result.push_back(x);
        for (int x : odds) result.push_back(x);

        // Nếu không thỏa mãn, hoán đổi thêm
        if (!is_valid_permutation(result)) {
            swap(result[0], result[1]); // Hoán đổi đầu tiên nếu cần
        }

        // Xuất kết quả
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

signed main() {
    solve();
    return 0;
}
