#include<bits/stdc++.h>

using namespace std;

string s;
bool b{};
int main()
{
    cin>>s;
    while(s.size() != 0)
    {
        if(s.substr(0,2) == "pi")
            s = s.substr(2);
        else if(s.substr(0,2) == "ka")
            s = s.substr(2);
        else if(s.substr(0,3) == "chu")
            s = s.substr(3);
        else
        {
            b = true;
            break;
        }
    }

    if(b == true)
        cout<<"NO";
    else
        cout<<"YES";
}