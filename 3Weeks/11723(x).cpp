//비트마스킹을 이용한 기초 문제
#include<bits/stdc++.h>

using namespace std;

int m,a;
string temp;
int s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>m;

    for(int i = 0; i < m; i++)
    {
        cin>>temp;
        if(temp == "all")
            s = (1<<21) -1;
        else if(temp == "empty")
            s = 0;
        else
        {
            cin>>a;
            if(temp == "add")
                s |= (1<<a);
            else if(temp == "remove")
                s &= ~(1<<a);
            else if(temp == "toggle")
                s ^= (1<<a);
            else
                cout<<((s & (1<<a)) ? 1 : 0)<<"\n";
        }
    }
}
