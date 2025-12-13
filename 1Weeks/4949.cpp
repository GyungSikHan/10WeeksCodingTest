#include<bits/stdc++.h>
#include <sstream>

using namespace std;

string s;


int main()
{
    while(getline(cin, s)) 
    {
        stack<char> st;
        bool b = true;
        if(s == ".")
            break;
        for(int i = 0; i<s.size();i++)
        {
            if(s[i] == '(' || s[i] ==')' || s[i] == '[' || s[i] == ']')
            {
                if(st.empty() == true)
                {
                    if(s[i] == ')' || s[i] == ']')
                    {
                        b = false;
                        break;
                    }
                    st.push(s[i]);
                }
                else
                {
                    char c = st.top();
                    if((c == '(' && s[i] == ']') || (c == '[' && s[i] == ')'))
                    {
                        b = false;
                        break; 
                    }
                    else if((c == '(' && s[i] == ')') || (c == '[' && s[i] == ']'))
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
            }
        }

        if(st.empty() == false)
            b = false;

        if(b == false)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
}