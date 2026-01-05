#include <bits/stdc++.h>

using namespace std;

int n, d, p;
vector<pair<int, int>> v;

int days = 0;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> d;

        v.push_back({d, p});
    }
    sort(v.begin(), v.end(), compare);

    int ret{};
    int maxDay = v.size();
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i].second);
        if (v[i].first < pq.size())
            pq.pop();       
    }
    while (pq.size() != 0)
    {
        ret += pq.top();
        pq.pop();
    }

    cout << ret;
}