#include<bits/stdc++.h>

using namespace std;

string s;


bool Solution()
{
    string temp{}, temp2{};
    int a{}, b{};
    int d{},e{},f{};
    //cout<<a<<endl;
    int size = s.size();
    for(int i = 0; i <size; i++)
    {
        if(s[i] == 'a' ||s[i] == 'e' || s[i] =='i' ||s[i] == 'o' ||s[i] == 'u')
        {
            f++;
            temp = "";
            a = 0;
            b++;
            if(temp2.size() != 0 && temp2[temp2.size() - 1] == s[i])
            {
                if(s[i] != 'o' && s[i] != 'e')
                {
                    //cout<<"모음 "<<s[i]<<" 같은 글자 연속 2개"<<endl;
                    return false;
                }
                else
                {
                    if(s[i] == 'o')
                    {
                        e = 0;
                        d++;
                    }
                    else
                    {
                        d = 0;
                        e++;
                    }
                    
                    if(d >= 2 || e >= 2)
                    {
                        //cout<<"o 또는 e가 연속 2개"<<endl;
                        return false;
                    }
                }
            }
            else
            {
                d= 0;
                e = 0;
            }
            temp2 += s[i];
            //cout<<"if "<<b<<endl;
        }
        else
        {
            temp2 = "";
            b = 0;
            d = 0;
            e = 0;
            a++;
            if(temp.size() != 0 && temp[temp.size()-1] == s[i])
            {
                //cout<<"자음 "s[i]<<" 같은 글자 연속 2개"<<endl;
                return false;
            }
            temp += s[i];
            //cout<<"else "<<a<<endl;
        }

        if(b >= 3 || a >= 3)
        {
            //cout<<a<<endl;
            //cout<<s[i]<<" 같은 글자 연속 3개"<<endl;
            return false;
        }
    }
    if(f == 0)
    {
        //cout<<"모음 없음"<<endl;
        return false;
    }

    return true;
}

int main()
{
    while(true)
    {
        cin>>s;
        if(s == "end")
            break;

        bool ret = Solution();
        //cout<<ret<<endl;
        if(ret == true)
            printf("<%s> is acceptable.\n", s.c_str());
        else
            printf("<%s> is not acceptable.\n", s.c_str());
        
    }
}