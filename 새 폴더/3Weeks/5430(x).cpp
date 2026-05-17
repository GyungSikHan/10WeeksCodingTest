// 거의다 풀었는데 좀만더 고민하면 맞출수 있는 문제
#include <bits/stdc++.h>

using namespace std;

int t, n;
string p, s;

int main()
{
    cin>>t;
    
    while(t--)
    {
        deque<string> dq;
        cin>>p;
        cin>>n;
        cin>>s;
        
        string temp;
        for(char c : s)
        {
            if(c != ',' && c != '[' && c != ']')
            {
                temp += c;
            }
            else
            {
                if(temp == "")
                    continue;
                
                dq.push_back(temp);
                temp = "";
            }
        }

        bool b{};
        bool error{};
        for(int i = 0; i < p.size();i++)
        {
            if(p[i] == 'R')
            {
                b = !b;
            }
            else
            {
                if(dq.empty() == true)
                {
                    error = true;
                    break;
                }
                if(b == true)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if(error == true)
        {
            cout<<"error\n";
            continue;
        }
        else
        {
            cout<<"[";
            if(b == true)
                reverse(dq.begin(), dq.end());
            for(int i = 0; i < dq.size(); i++)
            {
                cout<<dq[i];
                if(i < dq.size() - 1)
                    cout<<",";
            }
            cout<<"]\n";
        }
    }
}

//{
    // #include <bits/stdc++.h>

// using namespace std;

// int t, n;
// string p, s;

// int main()
// {
//     cin>>t;

//     while(t--)
//     {
//         deque<int> dq;
//         cin>>p;
//         cin>>n;
//         cin>>s;
        
//         int x{};
//         for(int i = 0; i< s.size(); i++)
//         {
//             if(s[i] == '[' || s[i] == ']')
//                 continue;
//             else if('0'<= s[i] && s[i] <='9')
//             {
//                 x = x*10 + (s[i] - '0');
//             }
//             else
//             {
//                 dq.push_back(x);
//                 x = 0;
//             }
//         }
//         if(0 < x)
//             dq.push_back(x);

//         bool b{};
//         bool error{};
//         for(char c : p)
//         {
//             if(c == 'R')
//             {
//                 b = !b;
//             }
//             else 
//             {
//                 if(dq.empty() == true)
//                 {
//                     error = true;
//                     break;
//                 }
//                 if(b == true)
//                     dq.pop_back();
//                 else
//                     dq.pop_front();
//             }
//         }

//         if(error == true)
//         {
//             cout<<"error\n";
//             continue;
//         }
//         else
//         {
//             cout<<"[";
//             if(b == true)
//                 reverse(dq.begin(), dq.end());
//             for(int i = 0; i < dq.size(); i++)
//             {
//                 cout<<dq[i];
//                 if(i < dq.size() - 1)
//                     cout<<",";
//             }
//             cout<<"]\n";
//         }

//     }
// }
//}