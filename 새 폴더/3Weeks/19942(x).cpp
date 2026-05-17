#include<bits/stdc++.h>

using namespace std;

int n, mp,mf,ms, mv;
int arr[16][5];
int ret = 987654321;
vector<vector<int>> vi;
vector<int> temp;

void Solution(int idx, int p, int f, int s, int v, int sum)
{
    if(mp <= p && mf <= f && ms <= s && mv <= v)
    {
        // cout<<sum<<endl;
        if(ret > sum)
        {
            ret = sum;
            vi.clear();
            vi.push_back(temp);
        }
        else if(ret == sum)
        vi.push_back(temp);
        
        return;
    }
    if(idx > n)
        return;

    temp.push_back(idx);
    Solution(idx+1, p+arr[idx][0], f+arr[idx][1],s+ arr[idx][2],v+ arr[idx][3],sum+arr[idx][4]);
    temp.pop_back();
    Solution(idx+1, p, f, s,v,sum);
}

int main()
{
    cin>>n;
    cin>>mp>>mf>>ms>>mv;
    
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4];
    }

    Solution(1,0,0,0,0,0);

    if(vi.size() == 0)
    {
        cout<<-1;
        return 0;
    }

    sort(vi.begin(), vi.end());
    cout<<ret<<"\n";
    for(int i = 0; i<vi[0].size(); i++)
    {
        cout<<vi[0][i]<<" ";
    }
}