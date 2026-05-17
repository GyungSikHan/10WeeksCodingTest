#include<bits/stdc++.h>

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        int a{};
        int ret{};
        int temp = 1;
        cin>>a;

        for(int i = 5; i <= a; i*=5)
        {
            ret += (a/i);
        }

        cout<<ret<<"\n";
    }
}