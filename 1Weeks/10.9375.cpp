//https://www.acmicpc.net/problem/9375 V
#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n{},m{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;

    for (int i = 0; i < n; i++) 
    {
        cin>>m;
        map<string,int> list;
        
        for (int j = 0; j < m; j++) 
        {
            string s{}, s2{};
            cin>>s>>s2;
            
            list[s2]++;
        }
        
        long long count = 1;
        for (auto iter : list) 
        {
            count *= iter.second+1;
        }

        cout<<count-1<<endl;
    }
}