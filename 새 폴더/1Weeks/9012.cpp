#include<bits/stdc++.h>

using namespace std;

int t;
string s;


int main()
{
    cin>>t;

    while(t--)
    {
        cin>>s;

        bool b = true;
        stack<char> st;
        
        for(int i = 0; i<s.size();i++)
        {
            //cout<<s[i]<<endl;
            if(st.empty() == true)
            {
                if(s[i] == ')')
                {
                    
                    st.push(s[i]);
                    b = false;
                    break;
                }
                st.push(s[i]);
            }
            else
            {
                char c = st.top();
                if(c == s[i])
                {
                    st.push(s[i]);
                }
                else
                {
                    // if(st.top() == ')')
                    // {
                    //     b= false;
                    //     break;
                    // }
                    st.pop();
                }
            }
        }
        if(st.empty() == false)
            b = false;

        if(b == false)
            cout<<"NO\n";
        else if( b == true)
            cout<<"YES\n";

    }
}

