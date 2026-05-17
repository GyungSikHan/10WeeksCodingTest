#include<bits/stdc++.h>

using namespace std;

int n, a[1000001], ret[1000001];
stack<int> st;
stack<int> st2;

int main()
{
    cin>>n;
    memset(ret, -1,sizeof(ret));
    for(int i = 0; i < n;i++)
     {
        cin>>a[i];

        if(st.empty() == true)
        {
            st.push(a[i]);
            st2.push(i);
        }
        else{
            while(st2.size() )
            {
                int t = a[st2.top()];
                if(t < a[i])
                {
                    ret[st2.top()] =a[i];  
                    st2.pop();
                }
                else{ 
                    st2.push(i);
                    break;
                }
            } 
            st2.push(i);
        }
     }

     for(int i = 0; i< n;i++)
     {
        cout<<ret[i]<<" ";

     }
}