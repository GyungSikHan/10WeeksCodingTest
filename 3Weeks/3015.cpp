#include<bits/stdc++.h>


using namespace std;

int n, ret,cnt;
vector<int> v;
stack<int> st;
int temp;
int main()
{
    cin>>n; 
    for(int i = 0; i < n ; i ++)
    {   
        cin >> temp;  
        //logic
        if(st.empty() && st.top() == temp)
            cnt += 1; 
        else if (st.top() > temp )
            ret +1;
        else if (st.top() < temp)
            ret +1;

        st.push(temp); 
    }

    int end{};
    for(int i = 0; i < n-1; i++)
    {
        end = i+1;
        for(int j = i+1; j < n; j++)
        {
            if(end != j && v[i] < v[j] || v[end] < v[j])
                break;
            ret++;
        }
    }

    cout<<ret;
}