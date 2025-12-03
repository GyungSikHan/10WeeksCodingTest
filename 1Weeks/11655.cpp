#include<bits/stdc++.h>
using namespace std;

string s,ret;
int a = 13;

int main()
{
    getline(cin, s);

    for(int i = 0; i<s.size(); i++)
    {
        char c =s[i];
        int t{};
        if(c >='A' && c <= 'Z')
        {
            t = (c - 'A') + 13;
            if(t > (int)('Z'-'A'))
                t = (t - (int)('Z'-'A')-1);
            c = 'A'+t;
        }
        else if(c>='a' && c<='z')
        {
            t = (c - 'a') + 13;
            if(t > (int)('z'-'a'))
            {
                t = (t - (int)('z'-'a')-1);
            }
            c = 'a'+t;
        }
        
        ret +=c;
    }

    cout<<ret;
}