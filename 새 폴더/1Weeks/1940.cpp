#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[15001];

int main()
{
    cin>>n;
    cin>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int ret{};
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] + arr[j] == m)
                ret++;
        }
    }

    cout<<ret;
}