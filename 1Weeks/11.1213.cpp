// https://www.acmicpc.net/problem/1213 V
#include <iostream>
#include<string>

using namespace std;

int main()
{
    string s{};
    cin>>s;
    int arr[26]{};
    for (int i = 0; i < s.size(); i++) 
        arr[s.at(i) - 'A']++;

    string ret{};
    int flag{};
    char mid{};
    bool b{};
    for (int i = 25; i >= 0; i--) 
    {
        if(arr[i] == 0)
            continue;

        if(arr[i] % 2 == 1)
        {
            mid = i + 'A';
            arr[i]--;
            flag++;
        }
        else if(flag >= 2)
        {
            b = true;
            break;
        }
        
        if(arr[i] != 0)
        {
            while (arr[i] != 0) 
            {
                int temp = i + 'A';
                ret += (char)temp;
                ret = (char)temp + ret;
                arr[i] -= 2;
            }
        }
    }

    if(flag >= 2)
        cout<<"I'm Sorry Hansoo"<<endl;
    else
    {
        if(flag == 1)
            ret.insert(ret.begin()+ ret.size()/2 , mid);

        cout<<ret<<endl;
    }
}

//? ë¦°?œë¡¬??ë§Œë“¤???€?˜ì˜ ê°?ˆ˜ê°€ 2ê°œì´?ì´ë©??????†ë‹¤
//?´ë? ?ê°?˜ê³  ?ŒíŒŒë²??¤ë¦„ì°¨ìˆœ?¼ë¡œ string???žë’¤???ŒíŒŒë²³ì„ ì¶”ê??´ì£¼ë©??œë‹¤
//?´ë•Œ ?€??ê°?ˆ˜???ŒíŒŒë²³ì´ ?˜ë‚˜ ì¡´ìž¬?œë‹¤ë©??¤ë¥¸ê³³ì— ?€?¥í•´?ì—ˆ?¤ê? ê²°ê³¼ê°’ì— string::insert ?¨ìˆ˜ë¥??´ìš©??ì¤‘ê°„???£ì–´ì£¼ì–´ ì¶œë ¥?˜ë©´ ?