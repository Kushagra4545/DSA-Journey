    #include <bits/stdc++.h>
    using namespace std;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;

    vector<int> desired(n);
    vector<int> build(m);

    for (int i = 0; i < n; i++)
    {
        cin >> desired[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> build[i];
    }

    sort(desired.begin(), desired.end());
    sort(build.begin(), build.end());

    int count = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        long long mini = build[j] - k;
        long long maxi = build[j] + k;

        if (desired[i] >= mini && desired[i] <= maxi)
        {
            count++;
            i++;
            j++;
        }
        else if (build[j] >= desired[i])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << count;
}