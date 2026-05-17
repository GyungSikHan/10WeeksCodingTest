#include<bits/stdc++.h>

using namespace std;

int n,ret;
string s;

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        stack<char> st;

        for(int j = 0; j < s.size(); j++)
        {
            if(st.empty() == true || st.top() != s[j])
                st.push(s[j]);
            else
                st.pop();
        }
        if(st.empty() == true)
            ret++;
    }

    cout<<ret;
}