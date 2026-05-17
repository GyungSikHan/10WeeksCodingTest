#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> v;
long long dp[104][21];
//string str;

long long Solution(int sum, int idx)
{
    if(sum > 20 || sum < 0)
    {
        //cout<<endl;
        //cout<<sum<<"is False"<<endl<<endl;
        return 0;
    }
    long long& ret = dp[idx][sum];
    if (ret)
        return ret;
    if (idx == n -2)
    {
        //cout << str << endl << endl;
        if (sum == v[n - 1])
            return 1;
        return 0;
    }

    //str += "+" + to_string(v[idx + 1]);
    ret += Solution(sum + v[idx + 1], idx + 1);
    //str.at(str.size() - 2) = '-';
    ret += Solution(sum - v[idx + 1], idx + 1);
    //str.erase(str.size() - 2, 2);
    return ret;
}

int main()
{
    cin>>n;
    v.resize(n, 0);
    for(int i = 0; i < n ; i++)
        cin>>v[i];
    //str = to_string(v[0]);
    cout<<Solution(v[0], 0);
}
