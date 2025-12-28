#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> num;
vector<vector<int>> lis;
vector<int> visited;

void A(int x, vector<int>& visited2, int& sum)
{
    for(int i = 1; i<= n; i++)
    {
        if(lis[x][i] != 0 && visited2[i] == 0)
        {
            visited2[i] = 1;
            sum += num[i];
            A(i, visited2, sum);
        }
    }
}

bool Check(int& sum)
{
    vector<int> visited2 = visited;
    int cnt{};
    for(int i = 1; i< n; i++)
    {
        for(auto iter : visited2)
            cout<<iter<<" ";
            cout<<endl<<endl;
        if(visited2[i] == 0 && cnt < 2)
        {
            cnt++;
            if(cnt >= 2)
                return false;
            visited2[i] = 1;
            sum += num[i];
            A(i, visited2, sum);
        }
    }
    return true;
}

int main()
{
    cin>>n;
    num.resize(n+1,0);
    lis.resize(n+1, vector<int>(n+1,0));
    visited.resize(n+1, 0);

    for(int i = 1; i<= n; i++)
        cin>>num[i];
    for(int i = 1; i<= n; i++)
    {
        int a{},b{};
        cin>>a;
        for(int j = 0; j<a; j++)
        {
            cin>>b;
            lis[i][b] = 1;
            lis[b][i] = 1;
        }
    }

    int ret = 987654321;
    int sum{};
    for(int i = 1; i<= n; i++)
    {
        int sum2{};
        sum += num[i];
        visited[i] = 1;
        cout<<"TEST "<<i<<endl;
        bool b = Check(sum2);
        cout<<b<<endl;
        cout<<"sum: "<<sum<<" sum2: "<<sum2<<endl<<endl;
        if(b == false)
        {
            visited[i] = 0;
            sum -= num[i];
        }
        else
        {
            ret = min(ret,abs(sum - sum2));
            cout<<ret<<endl;
        }
    }
    if(ret == 987654321)
        ret = -1;
    cout<<ret;
}