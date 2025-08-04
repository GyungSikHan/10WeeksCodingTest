//https://www.acmicpc.net/problem/3986
#include<iostream>
#include<vector> 
#include<stack>

using namespace std;

int main()
{
    int n{};
    int count{};
    cin>>n;

    for (int i = 0; i < n; i++) 
    {
        string s{};
        cin>>s;
        stack<char> st{};
        for (char c : s) 
        {
            if(st.empty() == true)
                st.push(c);
            else if(st.top() == c)
                st.pop();
            else
                st.push(c);
        }
        if(st.empty() == true)
            count++;
    }

    cout<<count<<endl;
}