#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> ones;

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                ones.push_back(i);
            }
        }

        int bestL = -1;
        int bestR = -1;

        if (ones.size() >= 2) {
            for (int i = 0; i + 1 < ones.size(); i++) {
                int l = ones[i];
                int r = ones[i + 1];

                if (r - l + 1 > bestR - bestL + 1) {
                    bestL = l;
                    bestR = r;
                }
            }

            for (int i = 0; i < ones[0]; i++) {
                if (a[i] == -1) {
                    if (ones[0] - i + 1 > bestR - bestL + 1) {
                        bestL = i;
                        bestR = ones[0];
                    }
                    break;
                }
            }
            for (int i = n - 1; i > ones.back(); i--) {
                if (a[i] == -1) {
                    if (i - ones.back() + 1 > bestR - bestL + 1) {
                        bestL = ones.back();
                        bestR = i;
                    }
                    break;
                }
            }
        }
        else if (ones.size() == 1) {

            int one = ones[0];

            for (int i = 0; i < one; i++) {
                if (a[i] == -1) {
                    bestL = i;
                    bestR = one;
                    break;
                }
            }

            for (int i = n - 1; i > one; i--) {
                if (a[i] == -1) {
                    if (bestL == -1 ||
                        i - one + 1 > bestR - bestL + 1) {
                        bestL = one;
                        bestR = i;
                    }
                    break;
                }
            }
        }
        else {

            int l = -1, r = -1;

            for (int i = 0; i < n; i++) {
                if (a[i] == -1) {
                    l = i;
                    break;
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == -1) {
                    r = i;
                    break;
                }
            }

            if (l != -1 && r != -1) {
                bestL = l;
                bestR = r;
            }
        }

        if (bestL != -1) {
            for (int i = 0; i < n; i++) {
                if (i == bestL || i == bestR) {
                    a[i] = 1;
                }
                else if (a[i] == -1) {
                    a[i] = 0;
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                if (a[i] == -1) {
                    a[i] = 0;
                }
            }
        }

        for (int x : a) {
            cout << x << " ";
        }

        cout << '\n';
    }
}