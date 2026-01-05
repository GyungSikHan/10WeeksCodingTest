#include <bits/stdc++.h>

using namespace std;

string s, boom;
stack<char> st;
string ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    cin >> boom;
    for(int i = 0; i < s.size(); i ++)
    {
        st.push(s[i]);
        if(st.size() >= boom.size() && st.top() == boom[boom.size() - 1])
        {
            string temp{};
            for(int j = 0; j < boom.size(); j++)
            {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());

            if(temp != boom)
            {
                for(int j = 0; j < temp.size(); j++)
                    st.push(temp[j]);
            }
        }
    }
    // for (auto iter = s.rbegin(); iter != s.rend(); iter++)
    // {
    //     st.push(*iter);
    //     if (st.size() >= boom.size() && st.top() == boom[0])
    //     {
    //         string temp{};
    //         for (int i = 0; i < boom.size(); i++)
    //         {
    //             temp += st.top();
    //             st.pop();
    //         }
    //         cout<<temp<<endl;
    //         if(temp != boom)
    //         {
    //             for(int i = 0; i < temp.size(); i++)
    //                 st.push(temp[i]);
    //         }
    //     }
    // }

    if (st.empty() == true)
        cout << "FRULA";
    else
    {
        while (st.empty() == false)
        {
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret;
    }
}