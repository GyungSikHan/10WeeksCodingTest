//https://www.acmicpc.net/problem/1940
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n{},m{};
    cin>>n;
    cin>>m;
    vector<int> v(n,0);
    
    for (int i = 0; i < n; i++) 
    {
        cin>>v[i];
    }

    long long count{};
    for (int i = 0; i < n; i++) 
    {
        for (int j = i+1; j < n; j++) 
        {
            if(v[i]+v[j] == m)
                count++;
        }
    }

    cout<<count<<endl;
}
