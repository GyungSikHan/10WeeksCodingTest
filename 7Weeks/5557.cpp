#include <bits/stdc++.h>

using namespace std;

int n, cnt;
vector<int> v;
string str;

void Solution(int sum, int idx)
{
    if(sum >= 20 || sum < 0)
    {
        cout<<endl;
        cout<<sum<<"is False"<<endl<<endl;
        return;
    }
    if(idx >= v.size())
    {
        cout<<str<<"= "<<sum<<endl<<endl;;
        cnt++;
        return;
    }
    str += to_string(sum);
    str += '+';
    Solution(sum + v[idx], idx+1);
    str.at(str.size()-1) = '-';
    Solution(sum - v[idx], idx+1);
}

int main()
{
    cin>>n;
    v.resize(n, 0);
    for(int i = 0; i < n ; i++)
        cin>>v[i];

    Solution(0, 0);

    cout<<cnt<<endl;
}