#include<bits/stdc++.h>

using namespace std;

string s;

int main()
{
    cin>>s;
    bool b{};
    while(s != "")
    {
        if(s.find("pi") != string::npos)
        {
            size_t i = s.find("pi");
            s.erase(i, 2);
        }
        else if(s.find("ka") != string::npos)
        {
            size_t i = s.find("ka");
            s.erase(i,2);
        }
        else if(s.find("chu") != string::npos)
        {
            size_t i = s.find("chu");            
            s.erase(i, 3);
        }
        else
        {
            b = true;
            break;;
        }
    }

    if(b == true)
        cout<<"NO";
    else 
        cout<<"YES";
}