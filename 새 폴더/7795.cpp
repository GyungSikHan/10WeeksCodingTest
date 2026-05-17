#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int Solution(int x, const vector<int> v2)
{
    int cnt{};
    for (int iter : v2)
    {
        if (x <= iter)
            break;
        cnt++;
    }

    return cnt;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> v(n, 0);
        vector<int> v2(m, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> v2[i];
        }

        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
        int ret{};
        for (auto iter : v)
            ret += Solution(iter, v2);

        cout << ret<<endl;
    }
}