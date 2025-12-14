//x
#include <bits/stdc++.h>

using namespace std;

int k;
long long mi = 10000000000, ma = -1;
int visited[10];
vector<char> v;
vector<int> ret;
string retmi,retma;

bool Check(int a, int b, char c)
{
    if (c == '<')
        return a < b;
    return a > b;
}

void Solution(int data, int index, long long temp)
{
    if(index == k)
    {
        
        mi = min(mi, temp);
        ma = max(ma, temp);
        return;
    }

    for(int i = 0; i < 10; i++)
    {
        if(visited[i] == 0 && Check(data, i, v[index]) == true)
        {
            visited[i] = 1;
            Solution(i, index+1, temp*10+i);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    v.resize(k, '\0');
    ret.resize(k + 1, 0);

    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i < 10;i ++)
    {
        visited[i] = 1;
        Solution(i, 0, i);
        visited[i] = 0;
    }

    retmi = to_string(mi);
    retma = to_string(ma);

    if(retmi.size() == k)
        retmi = '0'+retmi;
    if(retma.size() == k)
        retma = '0'+retma;

    cout<<retma<<"\n";
    cout<<retmi<<"\n";
}