#include<bits/stdc++.h>

using namespace std;
int n,k, ret = 987654321;
vector<int> arr;
vector<int> v;
vector<int> temp;

void DFS(int curr, vector<int>& temp)
{
    if(curr >= k*2)
        return;
    if(curr == k)
    {
        if(arr[curr] < ret)
        {   
            ret = arr[curr];
            v = temp;

        }
        return;
    }

    for(int next : {curr*2, curr+1, curr-1})
    {
        if(next < 0 || k*2 <= next)
            continue;
        if(arr[next] != 0 && arr[next] < arr[curr] + 1)
            continue;

        arr[next] = arr[curr] + 1;
        temp.push_back(next);
        DFS(next, temp); 
        temp.pop_back();
    }
}

int main()
{
    cin>>n>>k;
    arr.resize(k*2, 0);
    
    arr[n] = 1;
    temp.push_back(n);
    DFS(n,temp);

    cout<<ret-1<<"\n";
    for(auto iter : v)
        cout<<iter<<" ";
}