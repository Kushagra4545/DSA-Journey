#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int cnt[4] = {0};

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x % 4]++;
        }

        cout << max({cnt[0], cnt[1] + cnt[3], cnt[2]}) << endl;
    }

    return 0;
}