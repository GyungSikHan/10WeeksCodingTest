#include <bits/stdc++.h>

using namespace std;

int n, le, ri, ret = 0, sum;
char c;
stack<char> st;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        //cout << "le: " << le << " ri: " << ri << endl;
        if (st.empty() == true)
        {
            sum += le + ri;
            //cout << sum << endl;
            le = 0;
            ri = 0;
            if (c == ')')
            {
                ret = max(ret, sum);
                sum = 0;
                //cout << ret << endl;
                continue;
            }
            st.push(c);
            le++;
        }
        else if (st.top() == c)
        {
            st.push(c);
            if (c == '(')
                le++;
            else if (c == ')')
                ri++;
        }
        else if (st.top() != c)
        {
            st.pop();
            if (c == '(')
                le++;
            else if (c == ')')
                ri++;
        }
    }
    // cout << "end for" << endl;
    // cout << sum << endl;
    if (le + ri != 1)
    {
        if (sum != 0)
        {
            //cout << "i" << endl;
            sum += le + ri;
        }
        else if ((le + ri) % 2 == 0)
        {
            //cout << "e" << endl;
            if (sum == 0)
                sum = le + ri;
            else
                sum += le + ri;
        }
        else if ((le + ri) % 2 == 1)
        {
            //cout << "e2" << endl;
            sum = le + ri - abs(le - ri);
        }
    }
    ret = max(ret, sum);

    cout << ret;
}