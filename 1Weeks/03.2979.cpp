//https://www.acmicpc.net/problem/2979
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int A{}, B{}, C{};
vector<int> v(101,0);

int main()
{
    int Min = 987654321, Max{};
    cin>>A>>B>>C;
    for (int i = 0; i < 3; i++) 
    {
        int a{},b{};
        cin>>a>>b;
        Min = min(Min, a);
        Max = max(Max,b);
        for (int i = a; i < b; i++) 
        {
            v[i]++;
        }
    }

    int sum{};
    for (int i = Min; i < Max; i++) 
    {
        if(v[i] == 1)
            sum+= A*v[i];
        else if(v[i] == 2)
            sum+= B*v[i];
        else if(v[i] == 3)
            sum+= C*v[i];
    }

    cout<<sum;
}