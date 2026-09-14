#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        priority_queue<long long> pq;

        long long sum = 0;
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {

            if (pq.size() == m - 1) {
                ans = max(ans, 1LL * m * a[i] - sum);
            }
            pq.push(a[i]);
            sum += a[i];
            if (pq.size() > m - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }

        cout << ans << endl;
    }

    return 0;
}