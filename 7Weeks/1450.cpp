//meet in the middle
//완탐이 안될것같을때 dp를 만들어서 했을때 안되는 경우 발생
//N이 크지만 완탐을 해야될때 N/2를 기반으로 하는 알고리즘

#include <bits/stdc++.h>

using namespace std;

long n,c, ret;
vector<int> w, v, v2;

void go(int idx, int _n, vector<int>& temp, int sum)
{
    if(sum > c)
        return;
    if(idx > _n)
    {
        temp.push_back(sum);
        return;
    }
    go(idx+1, _n, temp, sum+w[idx]);
    go(idx+1, _n, temp, sum);

}

int main()
{
    cin>>n>>c;
    w.resize(n,0);
    for(int i = 0; i < n; i++)
    {  
        cin>>w[i];
    }

    go(0, n/2 - 1, v,0);
    go(n/2, n-1, v2, 0);

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    for(int iter : v)
    {
        if(c - iter >= 0)
            ret += 
            ((int)(upper_bound(v2.begin(), v2.end(), c-iter) 
            - v2.begin()));
    }

    cout << ret;
}