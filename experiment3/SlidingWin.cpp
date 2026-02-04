#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<bool> possible(n + 1, false);

        for (int i = 0; i < n; i++) {
            int sum = a[i];
            for (int j = i + 1; j < n; j++) {
                sum += a[j];
                if (sum > n) break;
                possible[sum] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (possible[a[i]]) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}